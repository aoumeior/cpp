#pragma once
#include "token.h"
#include "tag.h"

class Real : public Token
{

  public:
	Real(float v) : Token(Tag::REAL), value(v) {}
	virtual const std::string toString() const override { return std::to_string(value); }

  private:
	float value;
};
