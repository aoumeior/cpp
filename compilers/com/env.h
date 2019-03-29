#pragma once

#include <map>
#include "token.h"
#include "id.h"
#include <memory>
class Env
{
  public:
	Env() : table(), prev(nullptr) {}

	void put(Token w, Id i) { table.insert({w, i}); }

	std::shared_ptr<Id> get(const Token &w)
	{

		auto itr = table.find(w);
		if (itr != table.end())
		{

			return std::make_shared<Id>(itr->second);
		}
		return std::make_shared<Id>(nullptr);
	}

  private:
	std::map<Token, Id> table;
	std::shared_ptr<Env> prev;
};