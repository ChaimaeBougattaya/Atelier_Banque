#pragma once
#include "CompteCourant.h"
namespace banque {
	class ComptePayant :
		public CompteCourant
	{
	private:
		static double taux;
	public:
		ComptePayant(Client*, Devise*,Devise*);
		void print()const override;
		void crediter(Devise*);
		bool debiter(Devise*);
		~ComptePayant();
	};
}