#pragma once
#include <string>
#include <iostream>
class Node
{

  public:
	Node() : lexline{} {}

	void error(std::string err)
	{
	}

	int newlabel() const
	{
		return ++getlabels();
	}

	void emitlabel(int i) const
	{
	}
	void emit(std::string s) const
	{

		std::cout << s << std::endl;
	}

	int &getlabels() const
	{

		static int labels = 0;
		return labels;
	}

  private:
	int lexline;
};
