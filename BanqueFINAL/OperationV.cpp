#include "OperationV.h"
#include"Devise.h"
using namespace banque;
OperationV::OperationV(Compte* C, string date, Devise* montant)
	:Operations(C, date, montant)
{
}

void OperationV::print() const
{
	cout << "\noperation de versement";
	this->Operations::DetailOperation();
}

OperationV::~OperationV()
{
	//déstructeur
}
