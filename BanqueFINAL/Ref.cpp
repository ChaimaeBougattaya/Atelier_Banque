#include "Ref.h"
#include<iostream>
using namespace std;
using namespace banque;
Ref::Ref(int val)
{
    this->compteur = val;
}

void Ref::print() const
{
    cout << "nombre de references est : " << this->compteur << endl;
}

void Ref::incre()
{
    this->compteur = this->compteur + 1;
}

int& Ref::decre()
{
    this->compteur = this->compteur - 1;
    return this->compteur;
}

Ref::~Ref()
{
    //déstructeur
}
