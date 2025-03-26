#include "formulas.hpp"

int main(){
	auto propositon1 = Proposition('R');
	auto propositon2 = Proposition('P');
	auto propositon3 = Proposition('Q');

	auto formula1 = AndOperator(&propositon1,&propositon2);
	auto formula2 = OrOperator(&propositon3,&formula1);

	// formula1.print();
	formula2.print();

	return 0;
}