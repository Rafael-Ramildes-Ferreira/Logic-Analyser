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


class AndOperator : public Operator
{
private:
	Formula *phi;
	Formula *psi;
public:
	AndOperator(Formula *first, Formula *second);
	void print() override;
	std::string to_string() override;
};


class OrOperator : public Operator
{
private:
	Formula *phi;
	Formula *psi;
public:
	OrOperator(Formula *first, Formula *second);
	void print() override;
	std::string to_string() override;
};


class XorOperator : public Operator
{
private:
	Formula *phi;
	Formula *psi;
public:
	XorOperator(Formula *first, Formula *second);
	void print() override;
	std::string to_string() override;
};