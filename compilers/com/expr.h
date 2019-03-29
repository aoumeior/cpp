#pragma once
#include "node.h"
#include "token.h"
#include "type.h"
#include <memory>

class Expr : public Node
{
	//friend class Arith;
  public:
	Expr(Token tok, Type typ) : op{std::make_shared<Token>(tok)}, type{std::make_shared<Type>(typ)} {}
	Expr(const Token &tok, nullptr_t) : op{std::make_shared<Token>(tok)}, type{std::make_shared<Type>(Type::ret(Tag::NUll_T))} {}
	Expr(const Word &tok, const Type &typ) : op{std::make_shared<Word>(tok)}, type{std::make_shared<Type>(typ)} {}
	Expr(const Word &tok, const Word &typ) : op{std::make_shared<Word>(tok)}, type{std::make_shared<Type>(typ)} {}
	virtual const Expr gen() const { return *this; }
	virtual const Expr reduce() const { return *this; }

	virtual void jumping(int t, int f) const { emitjumps("", t, f); }

	void emitjumps(std::string test, int t, int f) const
	{

		if (t != 0 && f != 0)
		{
			emit("if" + test + "goto L" + std::to_string(t));
			emit("goto L" + f);
		}
		else if (t != 0)
		{
			emit("if" + test + "goto L" + std::to_string(t));
		}
		else if (f != 0)
		{
			emit("iffalse" + test + "goto L" + std::to_string(f));
		}
		else
			;
	}
	const Type &getType() const
	{

		return *type;
	}
	virtual const std::string toString() const { return op->toString(); }

  protected:
	std::shared_ptr<Token> op;
	std::shared_ptr<Type> type;
};