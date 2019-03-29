/*************************************************************************
    > File Name: read.h
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月25日 星期日 14时42分22秒
 ************************************************************************/

#include <string>

class read
{

  public:
	read(const char *str)
		: value_(str),
		  currentitr_(value_.begin())
	{
	}
	read(const std::string &str)
		: value_(str),
		  currentitr_(value_.begin())
	{
	}
	bool next(std::string::iterator &itr)
	{

		if (currentitr_ != value_.end())
		{
			itr = currentitr_++;
			return true;
		}
		return false;
	}

	std::string::iterator begin()
	{
		return value_.begin();
	}

	std::string::iterator current() const
	{
		return currentitr_;
	}
	bool back(std::string::iterator &itr)
	{

		if (currentitr_ != value_.begin())
		{
			itr = --currentitr_;
			return true;
		}
		return false;
	}

  private:
	std::string value_;
	std::string::iterator currentitr_;
};
