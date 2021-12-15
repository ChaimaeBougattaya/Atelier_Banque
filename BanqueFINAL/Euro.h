#pragma once
#include "Devise.h"
namespace banque {
	class Euro :
		public Devise
	{
	private:
		static double tauxM;
		static double tauxD;
	public:
		Euro(double);
		void print()const override;
		MAD& convertToMAD();
		Euro& convertToEuro();
		Dollars& convertToDollar();
		~Euro();
	};
}