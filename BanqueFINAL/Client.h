#pragma once
#include<iostream>
#include<vector>
using namespace std;
namespace banque {
	class Compte;
	class Client
	{
	private:
		string nom;
		string prenom;
		string adresse;
		vector <Compte*> list;
	public:
		Client(string, string, string);
		void ajouterCompte(Compte&);
		void print()const;
		~Client();
	};

}
