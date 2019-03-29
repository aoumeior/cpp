#pragma once
#include <vector>
#include <utility>
class VariableExp;

class Context
{

  public:
	bool Lookup(const char *) const;
	void Assign(VariableExp *, bool);

  private:
	std::vector<std::pair<VariableExp *, bool>> c;
};