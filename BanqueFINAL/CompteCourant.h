#pragma once
#include "Compte.h"
namespace banque {
	class Devise;
	class CompteCourant : 
		public Compte
	{
	private:
		Devise* decouvert;
	public:
		CompteCourant(Client*,Devise*,Devise*);
		virtual void print()const;
		bool debiter(Devise*);
		~CompteCourant();
	};
}
