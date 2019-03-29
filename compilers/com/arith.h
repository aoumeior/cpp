#pragma once
#include "op.h"
class Arith : public Op
{

  public:
	Arith(Token tok, Expr x1, Expr x2) : Op(tok, nullptr), expr1(x1), expr2(x2)
	{
		type = std::make_shared<Type>(Type::max(expr1.getType(), expr2.getType()));
		if (getType() == Type::ret(Tag::NUll_T))
		{
		}
	}

	virtual const Expr gen() const override
	{

		return Arith(*op, expr1.reduce(), expr2.reduce());
	}

	virtual const std::string &toString() const override
	{

		return expr1.toString() + expr2.toString();
	}

  private:
	Expr expr1, expr2;
};