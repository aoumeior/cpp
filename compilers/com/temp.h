#pragma once
#include <string>
#include "token.h"
#include "word.h"
#include "type.h"
#include "expr.h"
#include "op.h"
class Temp : public Expr
{

  public:
	Temp(Type p)
		: Expr(Word::fac(Tag::TEMP), p),
		  number(0)
	{
		number = ++getcount();
	}

	const std::string toString() const override
	{
		return "t" + std::to_string(number);
	}

	int &getcount()
	{
		static int count{};
		return count;
	}

  private:
	int number;
};
