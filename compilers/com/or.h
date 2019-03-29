#pragma once
#include "logical.h"

class Or : public Logical
{

  public:
	Or(Token tok, Expr x1, Expr x2) : Logical(tok, x1, x2)
	{
	}

	virtual void jumping(int t, int f) const override
	{

		int lable = t != 0 ? t : newlabel();
		E1.jumping(lable, 0);
		E2.jumping(t, f);
		(!t) ? emitlabel(lable)
			 : em();
	}

  private:
	void em() const {}
};