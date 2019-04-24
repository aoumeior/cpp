#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> con = {9, 6, 4, 7, 8};
    /**
     *  sort : 1, 2, 3
    */ 
    sort(con.begin(), con.end());

    /**
     *  unqique ,  inpution must be AABBCC, otherwise will show 
    */
    unique(con.begin(), con.end());

    for_each(con.begin(), con.end(), [](const int v) {
        // rt : 4 6 7 8 9
        std::cout << v << " ";
    });
    return 0;
}