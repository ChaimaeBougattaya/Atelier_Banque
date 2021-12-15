#include "Client.h"
#include"Compte.h"
using namespace banque;
Client::Client(string n, string p, string a)
{
	this->nom = n;
	this->prenom = p;
	this->adresse = a;
	this->list = vector<Compte*>();
}

void Client::ajouterCompte(Compte& C)
{
	this->list.push_back(&C);
}

void Client::print() const
{
	cout << "Nom : " << this->nom << endl;
	cout << "Prenom : " << this->prenom << endl;
	cout << "Adresse : " << this->adresse << endl;
	for (int unsigned i = 0; i < this->list.size(); i++)
	{
		cout << "\n\nle compte N° : " << i + 1 << endl;
		this->list[i]->print();
	}
}

Client::~Client()
{
	// déstructeur
	for (int unsigned i = 0; i < this->list.size(); i++)
	{
		delete this->list[i];
		this->list[i] = 0;
	}
}