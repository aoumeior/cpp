#include "VariableExp.h"
#include "Context.h"
#include <string>

VariableExp::VariableExp(const char *name)
{

	_name = _strdup(name);
}

VariableExp::~VariableExp()
{

	free(_name);
}

bool VariableExp::Evaluate(Context &aContext)
{

	return aContext.Lookup(_name);
}

BooleanExp *VariableExp::Replace(const char *name, BooleanExp &exp)
{

	return strcmp(name, _name) == 0 ? exp.Copy() : new VariableExp(_name);
}

BooleanExp *VariableExp::Copy() const
{

	return new VariableExp(_name);
}
