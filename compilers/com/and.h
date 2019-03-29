#pragma once
#include "logical.h"

class And : public Logical
{

  public:
	And(Token tok, Expr x1, Expr x2) : Logical(tok, x1, x2)
	{
	}

	virtual void jumping(int t, int f) const override
	{

		int lable = f != 0 ? f : newlabel();
		E1.jumping(lable, 0);
		E2.jumping(t, f);
		(!f) ? emitlabel(lable)
			 : em();
	}

  private:
	void em() const {}
};