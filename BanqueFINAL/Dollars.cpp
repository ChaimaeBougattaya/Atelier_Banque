#include "Dollars.h"
#include "Euro.h"
#include "MAD.h"
#include<iostream>
using namespace std;
using namespace banque;
double Dollars::tauxM = 9.27;	// le taux pour changer du DOLLAR à MAD
double Dollars::tauxE = 0.89;	// le taux pour changer du DOLLAR à EURO 

Dollars::Dollars(double val) :Devise(val)
{
}

void Dollars::print() const
{
	this->Devise::print(); std::cout << " $\n";
}

MAD& Dollars::convertToMAD()
{
	MAD* d = new MAD(this->Devise::calculVal(Dollars::tauxM));
	return *d;
}

Euro& Dollars::convertToEuro()
{
	Euro* d = new Euro(this->Devise::calculVal(Dollars::tauxE));
	return *d;
}

Dollars& Dollars::convertToDollar()
{
	return *this;
}

Dollars::~Dollars()
{
	//déstructeur
}
