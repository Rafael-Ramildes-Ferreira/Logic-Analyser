#pragma once
#include <vector>
#include <string>

/* Generic types -------------------------------------------------------------*/
typedef bool Verdict;

class Formula {
public:
	virtual void print() = 0;
	virtual std::string to_string() = 0;
};

class Operator : public Formula
{
private:
	std::vector<Verdict> truth_table;
public:
	std::vector<Verdict> get_truth_table();
	virtual std::vector<int> find_cases(bool verdict) = 0;
};

class TwoValueOperator : public Operator
{
private:
	Formula *phi;
	Formula *psi;
public:
	Formula *get_phi();
	Formula *get_psi();
	void set_phi(Formula *f);
	void set_psi(Formula *f);
};


/* Especific types -----------------------------------------------------------*/
class Proposition : public Formula
{
private:
	char identifier;
public:
	Proposition(const char name);
	void print() override;
	std::string to_string() override;
};


class AndOperator : public TwoValueOperator
{
public:
	AndOperator(Formula *first, Formula *second);
	void print() override;
	std::string to_string() override;
	std::vector<int> find_cases(bool verdict) override;
};


class OrOperator : public TwoValueOperator
{
public:
	OrOperator(Formula *first, Formula *second);
	void print() override;
	std::string to_string() override;
	std::vector<int> find_cases(bool verdict) override;
};


class XorOperator : public TwoValueOperator
{
public:
	XorOperator(Formula *first, Formula *second);
	void print() override;
	std::string to_string() override;
	std::vector<int> find_cases(bool verdict) override;
};