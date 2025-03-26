#include "formulas.hpp"

#include <iostream>
#include <exception>


std::vector<Verdict> Operator::get_truth_table()
{
	return this->truth_table;
}

TwoValueOperator::TwoValueOperator(Formula *first, Formula *second){
	if(first == nullptr) throw std::runtime_error("Invalid nullptr argument");
	if(second == nullptr) throw std::runtime_error("Invalid nullptr argument");
	
	this->set_phi(first);
	this->set_psi(second);
}

Formula *TwoValueOperator::get_phi()
{
	return phi;
}

Formula *TwoValueOperator::get_psi()
{
	return psi;
}

void TwoValueOperator::set_phi(Formula *f)
{
	this->phi = f;
}

void TwoValueOperator::set_psi(Formula *f)
{
	this->psi = f;
}

Proposition::Proposition(const char name)
{
	this->identifier = name;
}

void Proposition::print()
{
	std::cout << this->identifier << std::endl;
}

std::string Proposition::to_string()
{
	return std::string(&this->identifier);
}


AndOperator::AndOperator(Formula *first, Formula *second) : TwoValueOperator(first, second)
{
	/* This may be not very optimized */
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(false);
	this->get_truth_table().emplace_back(false);
	this->get_truth_table().emplace_back(false);
}

void AndOperator::print()
{
	if(this->get_phi() == nullptr){
		this->set_phi(new Proposition('-'));
	}
	if(this->get_psi() == nullptr){
		this->set_psi(new Proposition('-'));
	}

	std::cout << this->get_phi()->to_string() << " ^ " << this->get_psi()->to_string() << std::endl;	
}

std::string AndOperator::to_string()
{
	if(this->get_phi() == nullptr){
		this->set_phi(new Proposition('-'));
	}
	if(this->get_psi() == nullptr){
		this->set_psi(new Proposition('-'));
	}

	std::string str = "(" + this->get_phi()->to_string() + " ^ " + this->get_psi()->to_string() + ")";
	return str;
}


std::vector<int> AndOperator::find_cases(bool verdict)
{
	if(verdict){
		return (std::vector<int>) {0};
	} else{
		return (std::vector<int>) {1,2,3};
	}
}


OrOperator::OrOperator(Formula *first, Formula *second) : TwoValueOperator(first, second)
{
	/* This may be not very optimized */
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(false);
}

void OrOperator::print()
{
	if(this->get_phi() == nullptr){
		this->set_phi(new Proposition('-'));
	}
	if(this->get_psi() == nullptr){
		this->set_psi(new Proposition('-'));
	}

	std::cout << this->get_phi()->to_string() << " v " << this->get_psi()->to_string() << std::endl;
}

std::string OrOperator::to_string()
{
	if(this->get_phi() == nullptr){
		this->set_phi(new Proposition('-'));
	}
	if(this->get_psi() == nullptr){
		this->set_psi(new Proposition('-'));
	}

	std::string str = "(" + this->get_phi()->to_string() + " v " + this->get_psi()->to_string() + ")";
	return str;
}


std::vector<int> OrOperator::find_cases(bool verdict)
{
	if(verdict){
		return (std::vector<int>) {0,1,2};
	} else{
		return (std::vector<int>) {3};
	}
}


XorOperator::XorOperator(Formula *first, Formula *second) : TwoValueOperator(first, second)
{
	/* This may be not very optimized */
	this->get_truth_table().emplace_back(false);
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(true);
	this->get_truth_table().emplace_back(false);
}

void XorOperator::print()
{
	if(this->get_phi() == nullptr){
		this->set_phi(new Proposition('-'));
	}
	if(this->get_psi() == nullptr){
		this->set_psi(new Proposition('-'));
	}

	std::cout << this->get_phi()->to_string() << " XOR " << this->get_psi()->to_string() << std::endl;
}

std::string XorOperator::to_string()
{
	if(this->get_phi() == nullptr){
		this->set_phi(new Proposition('-'));
	}
	if(this->get_psi() == nullptr){
		this->set_psi(new Proposition('-'));
	}

	std::string str = "(" + this->get_phi()->to_string() + " XOR " + this->get_psi()->to_string() + ")";
	return str;
}


std::vector<int> XorOperator::find_cases(bool verdict)
{
	if(verdict){
		return (std::vector<int>) {1,2};
	} else{
		return (std::vector<int>) {0,3};
	}
}

