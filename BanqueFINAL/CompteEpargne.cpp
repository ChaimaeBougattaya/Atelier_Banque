#include "CompteEpargne.h"
using namespace banque;
const double CompteEpargne::TauxInteret = 2;

banque::CompteEpargne::CompteEpargne(Client* C, Devise* d):Compte(C,d)
{
}

void banque::CompteEpargne::calculInteret()
{
	this->Compte::calculInteretSolde(CompteEpargne::TauxInteret);
}

void banque::CompteEpargne::print() const
{
	cout << "\nDetails compte Epargne : \n";
	this->Compte::detailcompte();
}

bool banque::CompteEpargne::debiter(Devise* d)
{
	// si le montant qu'on veut débité est <= à la moitié du compte
	if (this->Compte::comparerMoitie(d) == true)
	{
		cout << "\nle compte epargne on peut debiter \n";
		this->Compte::debiter(d);
		return true;
	}
	return false;	
}

banque::CompteEpargne::~CompteEpargne()
{
	//déstructeur
}
