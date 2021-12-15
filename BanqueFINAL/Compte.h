#pragma once
#include<iostream>
#include<vector>
using namespace std;
namespace banque {
	class Devise;
	class Client;
	class Ref;
	class Operations;
	class Compte
	{
	private:
		Client* propretaire;
		const int numCompte;
		static int compteur;
		Devise* solde;
		static Devise* plafond;
		vector <Operations*> listOp;
		Ref* reference;
	public:
		Compte(Client*, Devise*);
		void addOperation(Operations&);
		Compte(const Compte&);
		Compte& operator=(const Compte&);
		void detailcompte()const;
		virtual void print()const = 0;

		void calculInteretSolde(double);
		bool comparerSolde(Devise*,Devise*);
		bool comparerMoitie(Devise*);
		
		void Mise_A_jour_payant(double);

		virtual void crediter(Devise*);				// ajouter au compte
		virtual bool debiter(Devise*);				//retirer du compte
		bool verser(Compte*, Devise*);				//verser 
		
		~Compte();

	};
};

