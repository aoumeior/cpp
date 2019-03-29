#include "and.h"

int main()
{
	Token a{Tag::TEMP};
	Expr e1{a, Type::ret(Tag::INT)};
	Expr e2{a, Type::ret(Tag::INT)};
	And c{a, e1, e2};

	c.emitjumps("a", 1, 2);
}