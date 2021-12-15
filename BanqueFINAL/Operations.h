#pragma once
#include<iostream>
using namespace std;
namespace banque {
	class Devise;
	class Compte;
	class Operations
	{
	private:
		static int compteur;
		const int Numop;
		string date;
		Devise* Montant;
		Compte* CompteOp;
	public:
		Operations(Compte*, string, Devise*);
		void DetailOperation()const;
		virtual void print()const=0;
		virtual ~Operations();
	};

}
