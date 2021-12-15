#pragma once
#include "Devise.h"
namespace banque {
	class MAD :
		public Devise
	{
	private:
		static double tauxD;
		static double tauxE;
	public:
		MAD(double);
		void print()const override;
		MAD& convertToMAD();
		Euro& convertToEuro();
		Dollars& convertToDollar();
		~MAD();
	};

}
