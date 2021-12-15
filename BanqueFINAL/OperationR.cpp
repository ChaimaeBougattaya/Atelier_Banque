#include "OperationR.h"
using namespace banque;
OperationR::OperationR(Compte* C, string date, Devise* montant)
	:Operations(C, date, montant)
{
}

void OperationR::print() const
{
	cout << "\noperation de Retrait";
	this->Operations::DetailOperation();
}

OperationR::~OperationR()
{
	//déstructeur
}
