#include "Devise.h"
#include "MAD.h"
#include "Euro.h"
#include "Dollars.h"
#include<iostream>
using namespace std;
using namespace banque;
Devise::Devise(double val)
{
    this->valeur = val;
}

banque::Devise::Devise(const Devise& d)
{
    this->valeur = d.valeur;
}

void Devise::print() const
{
    std::cout << "\nle solde est " << this->valeur;
}

double Devise::calculVal(double taux)
{
    return this->valeur * taux;
}

void banque::Devise::modifierSolde(double val)
{
    this->valeur = val;
}


bool banque::Devise::checkmoit(Devise* d)
{
    if (this->valeur / 2 >= d->valeur)
        return true;
    return false;
}

bool banque::Devise::check_solde_dec(Devise* d1, Devise* d2)
{
    if (this->valeur >= (d1->valeur + d2->valeur))
        return true;
    return false;
}

Devise& Devise::operator+(const Devise& M)
{
    this->valeur += M.valeur;
    return *this;
}

Devise& Devise::operator-(const Devise& d1)
{
    this->valeur -= d1.valeur;
    return *this;
}

bool Devise::operator>=(Devise& d)
{
    return (this->valeur >= d.valeur);
}

bool Devise::operator<=(Devise& d)
{
    return (this->valeur <= d.valeur);
}

Devise::~Devise()
{
    //déstructeur
}
