#include <boost/archive/text_oarchive.hpp>
#include <cassert>
#include <iostream>
using namespace boost::archive;
using namespace std;

int main()
{

	text_oarchive oa(cout);
	assert(text_oarchive::is_saving::value);
	assert(!text_oarchive::is_loading::value);

	int i;
	oa << i;
}