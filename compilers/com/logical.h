#pragma once
#include "expr.h"
#include "temp.h"

class Logical : public Expr
{

  public:
	Logical(Token tok, Expr x1, Expr x2) : Expr(tok, nullptr), E1(x1), E2(x2)
	{

		type = std::make_shared<Type>(check(E1.getType(), E2.getType()));
		if (*type == Type::ret(Tag::NUll_T))
		{
			//error
		}
	}

	const Type check(const Type &l, const Type &r)
	{

		if (E1.getType() == Type::ret(Tag::BOOL) && E2.getType() == Type::ret(Tag::BOOL))
		{

			return Type::ret(Tag::BOOL);
		}

		return Type::ret(Tag::NUll_T);
	}

	virtual const Expr gen() const override
	{

		int f = newlabel();
		int a = newlabel();
		Temp temp{*type};
		this->jumping(0, f);
		emit(temp.toString() + " = true");
		emit("goto L" + std::to_string(a));
		emitlabel(f);
		emit(temp.toString() + "= false");
		emitlabel(a);
		return temp;
	}

	virtual const std::string toString() const
	{

		return E1.toString() + (op->toString()) + E2.toString();
	}

  protected:
	Expr E1, E2;
};