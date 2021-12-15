#pragma once
#include "Operations.h"
namespace banque {
	class OperationR :
		public Operations
	{
	public:
		OperationR(Compte* C, string, Devise*);
		void print()const override;
		~OperationR();
	};
}

