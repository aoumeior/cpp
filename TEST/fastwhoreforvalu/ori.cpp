
#include <memory>
#include <iostream>

class i
{
  public:
	int jj() const {}
	int mm() {}

  public:
	int k;
	int m;
};
int main()
{

	const std::shared_ptr<i> mm{new i{}};
	const i cc;
	cc.mm();
}
