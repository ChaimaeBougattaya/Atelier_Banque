#include "Euro.h"
#include "MAD.h"
#include "Dollars.h"
#include<iostream>
using namespace std;
using namespace banque;
double Euro::tauxM = 10.44;	// le taux pour changer du EURO à MAD
double Euro::tauxD = 1.13;	// le taux pour changer du EURO à DOLLAR 
Euro::Euro(double val) :Devise(val)
{
}
void Euro::print() const
{
	this->Devise::print(); std::cout << " €" << std::endl;
}
MAD& Euro::convertToMAD()
{
	MAD* d = new MAD(this->Devise::calculVal(Euro::tauxM));
	return *d;
}
Euro& Euro::convertToEuro()
{
	return *this;
}
Dollars& Euro::convertToDollar()
{
	Dollars* d = new Dollars(this->Devise::calculVal(Euro::tauxD));
	return *d;
}
Euro::~Euro()
{
}
