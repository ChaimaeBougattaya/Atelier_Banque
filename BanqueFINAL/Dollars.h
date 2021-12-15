#pragma once
#include "Devise.h"
namespace banque {
	class Dollars :
		public Devise
	{
	private:
		static double tauxM;
		static double tauxE;
	public:
		Dollars(double);
		void print()const override;
		MAD& convertToMAD();
		Euro& convertToEuro();
		Dollars& convertToDollar();
		~Dollars();
	};

}
