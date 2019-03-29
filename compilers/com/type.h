#pragma once
#include "word.h"
#include <string>
#include "tag.h"

class Type : public Word
{
  public:
	Type(std::string s, Tag tag, int w)
		: Word(s, tag),
		  width(w)
	{
	}
	Type(const Word &w)
		: Word(w),
		  width((ret(w.getTag()).getWidth()))
	{
	}
	static const Type &ret(const Tag tag)
	{

		switch (tag)
		{

		case Tag::INT:
		{
			static Type Int{"int", Tag::BASIC, 8};
			return Int;
		}
		case Tag::FLOAT:
		{
			static Type Float{"Float", Tag::BASIC, 8};
			return Float;
		}

		case Tag::CHAR:
		{
			static Type Char{"Char", Tag::BASIC, 1};
			return Char;
		}
		case Tag::BOOL:
		{
			static Type Bool{"Bool", Tag::BASIC, 1};
			return Bool;
		}
		default:
		{
			static Type Null{"Bool", Tag::NUll_T, 0};
			return Null;
			break;
		}
		}
	}

	static bool numeric(const Type &p)
	{

		if (p == ret(Tag::CHAR) || p == ret(Tag::INT) || p == ret(Tag::FLOAT))
		{

			return true;
		}
		return false;
	}

	static Type max(const Type &p1, const Type &p2)
	{
		if (!numeric(p1) || !numeric(p2))
			return Type("", Tag::TEMP, 0);
		else if (p1 == ret(Tag::FLOAT) || p2 == ret(Tag::FLOAT))
			return ret(Tag::FLOAT);
		else if (p1 == ret(Tag::INT) || p2 == ret(Tag::INT))
			return ret(Tag::INT);
		else if (p1 == ret(Tag::CHAR))
			return ret(Tag::CHAR);
		return ret(Tag::NUll_T);
	}

	friend bool operator==(const Type &, const Type &);
	void operator=(const Type &r)
	{

		this->width = r.width;
	}
	int getWidth() const
	{
		return width;
	}

  private:
	int width = 0;

	friend class Array;
};

bool operator==(const Type &A, const Type &B)
{
	return A.toString() == B.toString();
}

//array
class Array : public Type
{

  public:
	Array(int sz, Type p) : Type("[]", Tag::INDEX, sz * p.getWidth()), of(p), size(sz) {}
	virtual const std::string toString() const override { return "[" + std::to_string(size) + "] " + of.toString(); }

  private:
	Type of;
	int size;
};