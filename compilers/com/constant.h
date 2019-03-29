#pragma once
#include "expr.h"
#include "num.h"
#include <memory>

class Constant : public Expr
{

  public:
	Constant(Token tok, Type p) : Expr{tok, p} {}
	Constant(int i) : Expr(Num{i}, Type::ret(Tag::INT)) {}
	Constant(const Word a, const Word b) : Expr(a, b) {}

  public:
	static Constant &ret(Tag tag)
	{

		switch (tag)
		{

		case Tag::TURE:
		{
			static Constant True{Word::fac(Tag::TURE), Type::fac(Tag::TURE)};
			return True;
		}
		case Tag::FALSE:
		{
			static Constant FALSE{Word::fac(Tag::FALSE), Type::fac(Tag::FALSE)};
			return FALSE;
		}
		default:
			break;
		}
	}

	void jumping(int t, int f)
	{

		if (*(std::dynamic_pointer_cast<Word>(this->type)) == Type::fac(Tag::TURE) && t != 0)
		{

			emit("goto L" + std::to_string(t));
		}
		else if (*(std::dynamic_pointer_cast<Word>(this->type)) == Type::fac(Tag::FALSE) && f != 0)
		{

			emit("goto L" + std::to_string(f));
		}
	}
};