#pragma once
namespace banque {
	class Ref
	{
	private:
		int compteur;
	public:
		Ref(int);
		void print()const;
		void incre();
		int& decre();
		~Ref();
	};
}

