#pragma once
#include "BooleanExp.h"

class Context;

class AndExp : public BooleanExp
{

  public:
	AndExp(BooleanExp *, BooleanExp *);
	virtual ~AndExp();

	virtual bool Evaluate(Context &) override;
	virtual BooleanExp *Replace(const char *, BooleanExp &) override;
	virtual BooleanExp *Copy() const override;

  private:
	BooleanExp *_BooleanExpl;
	BooleanExp *_BooleanExpr;
};