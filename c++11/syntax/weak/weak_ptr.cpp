#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class person : public enable_shared_from_this<person>
{

  public:
	person(const string &name,
		   shared_ptr<person> Mon = nullptr,
		   shared_ptr<person> Dad = nullptr)
		: namE(name), mom(Mon), dad(Dad), son()
	{

		cout << "creat" << namE << endl;
	}

	void init(const shared_ptr<person> &Mom, const shared_ptr<person> &Dad)
	{
		mom = Mom;
		dad = Dad;
		if (nullptr != mom)
		{

			mom->son.emplace_back(shared_from_this());
		}
		if (nullptr != dad)
		{

			dad->son.emplace_back(shared_from_this());
		}
	}

	~person()
	{
		cout << "delete" << namE << endl;
	}

  private:
	string namE;
	shared_ptr<person> mom;
	shared_ptr<person> dad;
	vector<weak_ptr<person>> son;
};

int main()
{
	{
		auto mom = make_shared<person>("mom");
		auto dad = make_shared<person>("dad");
		auto son = make_shared<person>("son");
		son->init(mom, dad);
	}
}