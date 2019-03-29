#pragma once
#include "token.h"
#include "tag.h"

class Word : public Token
{
	friend class Lexer;

  public:
	Word(std::string s, Tag tag)
		: Token(tag),
		  lexeme(s)
	{
	}
	virtual ~Word() {}

	virtual const std::string toString() const override
	{
		return lexeme;
	}

	static const Word &fac(Tag select)
	{

		switch (select)
		{
		case Tag::AND:
		{
			static Word and{"and", Tag::AND};
			return and;
		}
		case Tag::OR:
		{
			static Word or {"or", Tag::OR};
			return or ;
		}
		case Tag::EQ:
		{
			static Word eq("==", Tag::EQ);
			return eq;
		}
		case Tag::NE:
		{
			static Word ne("!=", Tag::NE);
			return ne;
		}
		case Tag::LE:
		{
			static Word LE("<=", Tag::LE);
			return LE;
		}
		case Tag::GE:
		{
			static Word ge(">=", Tag::GE);
			return ge;
		}
		case Tag::MINUS:
		{
			static Word minus("minus", Tag::MINUS);
			return minus;
		}
		case Tag::TURE:
		{
			static Word ture("true", Tag::TURE);
			return ture;
		}
		case Tag::FALSE:
		{
			static Word fales("false", Tag::FALSE);
			return fales;
		}
		default:
		{
			static Word temp("NULL", Tag::NUll_T);
			return temp;
		}
		}
	}

  private:
	std::string lexeme;
};