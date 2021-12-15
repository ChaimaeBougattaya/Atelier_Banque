#include "Operations.h"
#include"Devise.h"
#include"Compte.h"
using namespace banque;
int Operations::compteur = 0;
Operations::Operations(Compte* C, string date, Devise* d) :Numop(++compteur)
{
	this->date = date;
	this->Montant = d;
	this->CompteOp = C;
}

void Operations::DetailOperation() const
{
	cout << "\nDetails :   ";
	cout << this->date << "  || n° : " << this->Numop << "  ||  ";
	this->Montant->print(); 
	cout << endl;
}

Operations::~Operations()
{
	//désctructeur
}
