#include "CompteCourant.h"
#include"Compte.h"
#include"MAD.h"
#include"Euro.h"
#include"Dollars.h"
using namespace banque;

CompteCourant::CompteCourant(Client* c, Devise* sol,Devise* dec):Compte(c,sol)
{
	this->decouvert = dec;
}

void banque::CompteCourant::print()const
{
	cout << "\nDetails compte courant : \n";
	this->Compte::detailcompte();
}

bool banque::CompteCourant::debiter(Devise* d)
{
	bool val=false;
	if (typeid(*(this->decouvert)) == typeid(MAD))
		val = this->comparerSolde(&d->convertToMAD(), banque::CompteCourant::decouvert);
	if (typeid(*(this->decouvert)) == typeid(Euro))
		val = this->comparerSolde(&d->convertToEuro(), banque::CompteCourant::decouvert);
	if (typeid(*(this->decouvert)) == typeid(Dollars))
		val = this->comparerSolde(&d->convertToDollar(), banque::CompteCourant::decouvert);
	if (val == true)
	{
		this->Compte::debiter(d);
		return true;
	}
	return false;
}

banque::CompteCourant::~CompteCourant()
{
	//déstructeur
}
