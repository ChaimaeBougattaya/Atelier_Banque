#pragma once
#include"Compte.h"

namespace banque{
	class CompteEpargne : 
		public Compte
	{
	private:
		static const double TauxInteret;
	public:
		CompteEpargne(Client*,Devise*);
		void calculInteret();
		void print()const;
		bool debiter(Devise*)override;
		~CompteEpargne();
	};
}