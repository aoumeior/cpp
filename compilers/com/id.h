#pragma once
#include "node.h"
#include "word.h"
#include "type.h"
#include "expr.h"

class Id : public Expr
{

  public:
	Id(Word id, Type p, int b) : Expr{id, p}, offset(b) {}

  private:
	int offset;
};