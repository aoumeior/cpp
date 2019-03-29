#include "AndExp.h"
#include "Context.h"
#include <string>

AndExp::AndExp(BooleanExp *opl, BooleanExp *opr) : _BooleanExpl(opl), _BooleanExpr(opr)
{
}

AndExp::~AndExp()
{

	if (_BooleanExpl != nullptr)
		delete _BooleanExpl;
	if (_BooleanExpr != nullptr)
		delete _BooleanExpr;
}

bool AndExp::Evaluate(Context &aContext)
{
	return _BooleanExpl->Evaluate(aContext) &&
		   _BooleanExpr->Evaluate(aContext);
}

BooleanExp *AndExp::Replace(const char *name, BooleanExp &exp)
{
	return new AndExp(
		_BooleanExpl->Replace(name, exp),
		_BooleanExpr->Replace(name, exp));
}

BooleanExp *AndExp::Copy() const
{
	return new AndExp(
		_BooleanExpl->Copy(),
		_BooleanExpr->Copy());
}
