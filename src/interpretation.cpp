#include "interpretation.hpp"


Formula *Interpretation::get_formula()
{
	return this->first;
}

Verdict Interpretation::get_verdict()
{
	return this->second;
}