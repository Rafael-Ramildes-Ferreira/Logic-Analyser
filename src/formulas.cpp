#include "formulas.hpp"

#include <utility>
#include <iostream>


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
	std::string str = "(";
	str = str + this->phi->to_string();
	str = str + " ^ ";
	str = str + this->psi->to_string();
	return str + ")";
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
	std::string str = "(";
	str = str + this->phi->to_string();
	str = str + " v ";
	str = str + this->psi->to_string();
	return str + ")";
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
	std::string str = "(";
	str = str + this->phi->to_string();
	str = str + " XOR ";
	str = str + this->psi->to_string();
	return str + ")";
}

