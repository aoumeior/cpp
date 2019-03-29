#include <boost\intrusive\slist.hpp>
#include <iostream>
using namespace boost::intrusive;
using namespace std;

class point : public slist_base_hook<>
{

  public:
	int x, y;
	point(int a = 0, int b = 0) : x{a}, y{b}
	{
	}
};

int main()
{

	point p1, p2(2, 2), p3(3, 3);

	slist<point> s1;

	s1.push_front(p1);
	s1.push_front(p2);
	s1.push_front(p3);

	assert(s1.size() == 3);
	s1.reverse();
	for (auto &p : s1)
	{

		cout << "	" << p.x << "	" << p.y;
	}

	s1.erase(next(s1.begin()));
}