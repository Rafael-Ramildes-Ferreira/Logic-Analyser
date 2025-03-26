#include "formulas.hpp"
#include "interpretation.hpp"

#include <vector>
#include <stdexcept>

bool refute_tautology(Formula *target)
{
	// auto base = Case(target,false);
	return false;
}

bool resolve_hypothesys(Case *c)
{
	Interpretation *hyp = c->front();
	Formula *base_formula = hyp->get_formula();
	Verdict base_verdict = hyp->get_verdict();

	if(dynamic_cast<Proposition*>(base_formula)){
		return false;
	}else if(dynamic_cast<Operator*>(base_formula)){
		Operator *base_operator = reinterpret_cast<Operator*>(base_formula);
		std::vector<int> vec = base_operator->find_cases(base_verdict);

		if(dynamic_cast<TwoValueOperator*>(base_formula)){
			TwoValueOperator *base_two_value = reinterpret_cast<TwoValueOperator*>(base_operator);
			
			for(auto interp : vec){
				Case new_case(*c);
				Formula *firstf = base_two_value->get_phi();
				if(firstf==nullptr) throw std::runtime_error("Object is uninitialized");
				Formula *secondf = base_two_value->get_psi();
				if(secondf==nullptr) throw std::runtime_error("Object is uninitialized");
				
				switch (interp)
				{
				case 0:
					// new_case[0] = new Interpretation(firstf,true);
					// new_case.emplace(1, new Interpretation(secondf,true));
					break;
				case 1:
					/* code */
					break;
				case 2:
					/* code */
					break;
				case 3:
					/* code */
					break;
				
				default:
					break;
				}
			}
		}
	}
}