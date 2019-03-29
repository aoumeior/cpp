#include "Context.h"
#include "VariableExp.h"
#include <algorithm>
#include <iterator>
#include <string>

bool Context::Lookup(const char *name) const
{

	return std::find_if(c.begin(), c.end(),
						[&](const std::pair<VariableExp *, bool> &a) {
							if (!strcmp(name, (a.first)->_name))
								return true;
							return false;
						})
		->second;
}

void Context::Assign(VariableExp *l, bool b)
{

	c.push_back(std::make_pair(l, b));
}
