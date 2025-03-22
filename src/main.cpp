#include "formulas.hpp"

int main(){
	auto propositon1 = Proposition('R');
	auto propositon2 = Proposition('P');
	auto propositon3 = Proposition('Q');

	auto formula1 = ComplexFormula(new AndOperator(&propositon1,&propositon2));
	auto formula2 = ComplexFormula(new OrOperator(&propositon3,&formula1));

	formula2.print();

	return 0;
}