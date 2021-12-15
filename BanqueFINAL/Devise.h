#pragma once
namespace banque {
	class MAD;
	class Euro;
	class Dollars;
	class Devise
	{
	private:
		double valeur;
	public:
		Devise(double);
		Devise(const Devise&);
		virtual void print()const;
		double calculVal(double);
		void modifierSolde(double);
		virtual MAD& convertToMAD() = 0;
		virtual Euro& convertToEuro() = 0;
		virtual Dollars& convertToDollar() = 0;
		bool checkmoit(Devise*);
		bool check_solde_dec(Devise*,Devise*);
		Devise& operator+(const Devise&);
		Devise& operator-(const Devise&);
		bool operator>=(Devise&);
		bool operator<=(Devise&);
		~Devise();

		
	};
};