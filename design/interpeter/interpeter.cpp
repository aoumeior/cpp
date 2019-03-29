// interpeter.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <stdio.h>
#include <tchar.h>
#include "Context.h"
#include "AndExp.h"
#include "BooleanExp.h"
#include "VariableExp.h"
#include <memory>

int main()
{

	BooleanExp *expression;
	Context context;

	VariableExp *x = new VariableExp("x");
	VariableExp *y = new VariableExp("y");

	context.Assign(x, true);
	context.Assign(y, true);
	expression = new AndExp(x, y);

	bool res = expression->Evaluate(context);
}
