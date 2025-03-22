#include "formulas.hpp"

#include <utility>
#include <iostream>


ComplexFormula::ComplexFormula(Operator *op)
{
	this->_operator = op;
}

Operator *ComplexFormula::get_operator(){
	return this->_operator;
}

void ComplexFormula::print(){
	std::cout << this->_operator->to_string() << std::endl;
}

std::string ComplexFormula::to_string(){
	std::string str = "(";
	str = str + this->_operator->to_string();
	return str + ")";
}

Proposition::Proposition(const char name)
{
	this->identifier = name;
}

void Proposition::print(){
	std::cout << this->identifier << std::endl;
}

std::string Proposition::to_string(){
	return std::string(&this->identifier);
}

/* Put in other file maybe*/
class Case : public std::pair<Formula*,Verdict>{
public:
	Formula *get_formula(){
		return this->first;
	}
	Verdict get_verdict(){
		return this->second;
	}
};


std::vector<Verdict> Operator::get_truth_table()
{
	return this->truth_table;
}


AndOperator::AndOperator(Formula *first, Formula *second)
{
	this->phi = first;
	this->psi = second;
	/* This may be not very optimized */
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(false);
	this->get_truth_table().emplace_back(false);
	this->get_truth_table().emplace_back(false);
}

void AndOperator::print(){
	std::cout << this->phi->to_string() << " ^ " << this->psi->to_string() << std::endl;
}

std::string AndOperator::to_string(){
	std::string str = this->phi->to_string();
	str = str + " ^ ";
	return str + this->psi->to_string();
}


OrOperator::OrOperator(Formula *first, Formula *second)
{
	this->phi = first;
	this->psi = second;
	/* This may be not very optimized */
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(false);
}

void OrOperator::print(){
	std::cout << this->phi->to_string() << " v " << this->psi->to_string() << std::endl;
}

std::string OrOperator::to_string(){
	std::string str = this->phi->to_string();
	str = str + " v ";
	return str + this->psi->to_string();
}


XorOperator::XorOperator(Formula *first, Formula *second)
{
	this->phi = first;
	this->psi = second;
	/* This may be not very optimized */
	this->get_truth_table().emplace_back(false);
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(false);
}

void XorOperator::print(){
	std::cout << this->phi->to_string() << " XOR " << this->psi->to_string() << std::endl;
}

std::string XorOperator::to_string(){
	std::string str = this->phi->to_string();
	str = str + " XOR ";
	return str + this->psi->to_string();
}

