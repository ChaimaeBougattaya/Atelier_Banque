#include "Compte.h"
#include "Client.h"
#include"Operations.h"
#include"OperationR.h"
#include"OperationV.h"
#include"Ref.h"
#include"MAD.h"
#include"Euro.h"
#include"Dollars.h"
using namespace banque;

int Compte::compteur = 0;
Devise* Compte::plafond = new MAD(10000);

Compte::Compte(Client* client, Devise* solde):numCompte(++compteur)
{
    this->propretaire = client;
    this->solde = solde;
    this->reference = new Ref(1);
    this->listOp = vector<Operations*>();
}

void Compte::addOperation(Operations& C)
{
    this->listOp.push_back(&C);
}

Compte::Compte(const Compte& c) :numCompte(++compteur)
{
    this->propretaire = c.propretaire;
    this->solde = c.solde;
    this->reference = c.reference;
}

Compte& Compte::operator=(const Compte& c)
{
    if (this != &c)
    {
        if (this->propretaire && this->reference && this->reference->decre() == 0)
        {
            delete this->reference;
            this->reference = nullptr;
        }
        this->propretaire = c.propretaire;
        this->solde = c.solde;
        this->reference = c.reference;
        this->reference->incre();
    }
    return *this;
}

void Compte::detailcompte() const
{
    this->solde->print();
    cout << endl;
    for (int unsigned i = 0; i < this->listOp.size(); i++)
    {
        this->listOp[i]->print();
    }
}

void banque::Compte::calculInteretSolde(double val)
{
    double val1;
    val1 = this->solde->Devise::calculVal(1-(val/100));
    this->solde->Devise::modifierSolde(val1);
}

bool banque::Compte::comparerSolde(Devise* d, Devise* dec)
{
    // si le solde du compte est >= ( decouvert + le montant à débiter)
    return this->solde->check_solde_dec(d, dec);
}


bool banque::Compte::comparerMoitie(Devise* d)
{
    if (typeid(*(this->solde)) == typeid(MAD))
        return this->solde->checkmoit(&d->convertToMAD());
    else
        if (typeid(*(this->solde)) == typeid(Euro))
            return this->solde->checkmoit(&d->convertToEuro());
        else
            if (typeid(*(this->solde)) == typeid(Dollars))
                return this->solde->checkmoit(&d->convertToDollar());   
}

void banque::Compte::Mise_A_jour_payant(double taux)
{
    this->solde->modifierSolde(this->solde->calculVal(1 - taux));
}

void banque::Compte::crediter(Devise* M)
{
    if (typeid(*(this->solde)) == typeid(MAD))
        this->solde->operator+(M->convertToMAD());
    else
        if (typeid(*(this->solde)) == typeid(Euro))
            this->solde->operator+(M->convertToEuro());
        else
            if (typeid(*(this->solde)) == typeid(Dollars))
                this->solde->operator+(M->convertToDollar());
    
    Operations* op = new banque::OperationV(this,__DATE__, M);
    this->addOperation(*op);
}

bool banque::Compte::debiter(Devise* M)
{
    if (M->convertToMAD() <= *plafond)
    {
        if (typeid(*(this->solde)) == typeid(MAD))
        {
            if (*this->solde >= M->convertToMAD())
            {
                this->solde->operator-(M->convertToMAD());
                Operations* op = new banque::OperationR(this, __DATE__, M);
                this->addOperation(*op);
                return true;
            }
        }
        if (typeid(*(this->solde)) == typeid(Euro))
        {
            if (*this->solde >= M->convertToEuro())
            {
                this->solde->operator-(M->convertToEuro());
                Operations* op = new banque::OperationR(this, __DATE__, M);
                this->addOperation(*op);
                return true;
            }
        }
        if (typeid(*(this->solde)) == typeid(Dollars))
        {
            if (*this->solde >= M->convertToDollar())
            {
                this->solde->operator-(M->convertToDollar());
                Operations* op = new banque::OperationR(this, __DATE__, M);
                this->addOperation(*op);
                return true;
            }
        }
    }
    return false;
}
bool Compte::verser(Compte* C, Devise* M)
{
    if (this->debiter(M) == true)
    {
         C->crediter(M);
         return true;
    }
    return false;
}

Compte::~Compte()
{
    for (int unsigned i = 0; i < this->listOp.size(); i++)
    {
        delete this->listOp[i];
        this->listOp[i] = 0;
    }

}
