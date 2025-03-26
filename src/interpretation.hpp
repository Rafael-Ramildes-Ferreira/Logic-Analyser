#pragma once
#include "formulas.hpp"

#include <utility>
#include <vector>


class Interpretation : public std::pair<Formula*,Verdict>{
public:
	using std::pair<Formula*,Verdict>::pair;
	Formula *get_formula();
	Verdict get_verdict();
};

typedef std::vector<Interpretation*> Case;
