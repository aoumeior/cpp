#pragma once
#include "op.h"
class Unary : public Op
{

  public:
	Unary(Token tok, Expr x)
		: Op(tok, Type(std::to_string('t'), Tag::TEMP, 0)),
		  expr(x)
	{
	}

  private:
	Expr expr;
};