#pragma once
#include "token.h"
#include "tag.h"
class Num : public Token
{

  public:
	Num(int v) : Token(Tag::NUM), value{v} {}

	virtual const std::string toString() const override { return std::to_string(value); }

  private:
	int value;
};