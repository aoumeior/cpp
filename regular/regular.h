/*************************************************************************
    > File Name: regular.h
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月25日 星期日 14时51分15秒
 ************************************************************************/

#include "./status.h"
#include "./read.h"

class regular
{

  public:
	regular(const std::string &str)
		: read_(str)
	{
	}

  private:
	void init()
	{
		std::vector<status> backstatus;
		std::vector<status> tempstatus;

		std::string::iterator itr;

		while (read_.next(itr))
		{

			switch (*itr)
			{

			case '|':
			{
				status s(ele::OR);
				status l(ele::BLANK);
				status r(ele::BLANK);
				l.swap(tempstatus);
				seek(r);
				s.push(l);
				s.push(r);
			}
			break;
			default:
				tempstatus.push_back(status(*itr));
				break;
			}
		}
	}

  private:
	void seek(status &s)
	{
		std::string::iterator itr = read_.current();
	}

  private:
	read read_;
	std::vector<status> s_;
};
