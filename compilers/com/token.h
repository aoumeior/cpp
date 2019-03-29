#pragma once
#include <string>
#include "tag.h"

class Token
{

  public:
	Token(Tag t)
		: tag(t)
	{
	}
	Token(const Token &t)
		: tag(t.tag)
	{
	}

	virtual const std::string toString() const
	{
		return std::to_string(static_cast<int>(tag));
	}

	void operator=(Token &a)
	{
		tag = a.tag;
	}

	bool operator==(const Token &a) const
	{
		return tag == a.tag;
	}
	virtual const Tag &getTag() const
	{
		return tag;
	}
	virtual ~Token() {}

  private:
	Tag tag;
};
