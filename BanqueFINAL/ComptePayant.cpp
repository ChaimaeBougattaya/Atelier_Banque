#include "ComptePayant.h"
#include"Devise.h"
double banque::ComptePayant::taux=0.5;
banque::ComptePayant::ComptePayant(Client* C, Devise* sol,Devise* dec):CompteCourant(C,sol,dec)
{
}

void banque::ComptePayant::print() const
{
	cout << "\n\nDétail d'un compte payant "<<endl;
	this->CompteCourant::print();
}

void banque::ComptePayant::crediter(Devise* d)
{
	this->CompteCourant::crediter(d);
	this->Compte::Mise_A_jour_payant(taux);
}

bool banque::ComptePayant::debiter(Devise* d)
{
	bool val = this->CompteCourant::debiter(d);
	this->Compte::Mise_A_jour_payant(taux);
	return val;
}

banque::ComptePayant::~ComptePayant()
{
	//déstructeur
}
