#pragma once

#include "BooleanExp.h"

class Context;

class VariableExp : public BooleanExp
{
	friend class Context;

  public:
	VariableExp(const char *);
	virtual ~VariableExp();

	virtual bool Evaluate(Context &) override;
	virtual BooleanExp *Replace(const char *, BooleanExp &) override;
	virtual BooleanExp *Copy() const override;

  private:
	char *_name;
};