#include <iostream>
#include <memory>
#include <array>
#include <boost/asio.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/compressed_pair.hpp>

#pragma comment(lib, R"(libboost_serialization-vc140-mt-gd-1_59.lib)")

class point : boost::noncopyable
{

	int x;
	int y;
};

int main(int argc, char *argv[])
{
	sizeof(point);
	sizeof(boost::noncopyable);
	sizeof(boost::compressed_pair<point, boost::noncopyable>);

	return 0;
}