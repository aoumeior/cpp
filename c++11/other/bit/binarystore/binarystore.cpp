#include <fstream>
#include "binaryfstream.h"
#include "binarybuffer.h"
#include <typeinfo>
#include <iterator>

using namespace std;

int main()
{

	binaryfstream mm{"binary.bin"};

	mm.binarys(1, 2);
}