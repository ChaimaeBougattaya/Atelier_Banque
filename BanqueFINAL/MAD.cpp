#include "MAD.h"
#include "Euro.h"
#include "Dollars.h"
#include<iostream>
using namespace std;
using namespace banque;

double MAD::tauxE = 0.096;	// le taux pour changer du MAD à EURO 
double MAD::tauxD = 0.11;	// le taux pour changer du MAD à DOLLAR

MAD::MAD(double val):Devise(val)
{
}

void MAD::print() const
{
	this->Devise::print(); cout << " MAD\n";
}

MAD& MAD::convertToMAD()
{
	return *this;
}

Euro& MAD::convertToEuro()
{
	Euro* d = new Euro(this->Devise::calculVal(MAD::tauxE));
	return *d;
}

Dollars& MAD::convertToDollar()
{
	Dollars* d = new Dollars(this->Devise::calculVal(MAD::tauxD));
	return *d;
}

MAD::~MAD()
{
	//déstructeur
}

