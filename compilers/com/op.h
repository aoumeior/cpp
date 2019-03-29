#pragma once
#include "expr.h"

class Op : public Expr
{
  private:
  public:
	Op(const Token &tok, const Type &p) : Expr(tok, p) {}
	Op(const Token &tok, nullptr_t) : Expr(tok, nullptr) {}
	virtual const Expr reduce() const override
	{
		const Expr &x = gen();
		auto t = Word{"t", Tag::TEMP};
		emit(t.toString() + "=" + x.toString());
		return x;
	}
};
