#pragma once
#include "Operations.h"
namespace banque {
	class OperationV :
		public Operations
	{
	public:
		OperationV(Compte* C, string, Devise*);
		void print()const override;
		~OperationV();
	};

}
