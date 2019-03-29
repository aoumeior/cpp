/*************************************************************************
    > File Name: status.h
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月24日 星期六 21时55分03秒
 ************************************************************************/
#include <vector>
#include <string>
#include <map>
#include <algorith>
enum class ele
{
	OR = '|',
	START = '*',
	LEFTPARENTHESES = '(',
	RIGHTPAEWNTHESES = ')',

	BLANK = -2 BEGIN = 0,
	END = -1,
	LETTER = 1
};

class status;

static std::map<int, status *> tab_;

class status
{
  public:
	status(char c)
		: attribute_(ele::LETTER),
		  value_(c),
		  next_() {}
	status(ele e, char c)
		: attribute_(e),
		  value_(c),
		  next_() {}
	status(ele e)
		: attribute_(e),
		  value_(0),
		  next_()
	{
	}
	void push(const status &sta)
	{
		next_.push_back(sta);
	}

	void swap(std::std::vector<status> v)
	{
		std::swap(v, next_)
	}

  private:
	ele attribute_;
	char value_;
	std::vector<status> next_;
};
