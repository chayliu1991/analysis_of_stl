#include "../Allocator.h"

#include <vector>
using namespace std;

int main(int argc, const char **argv)
{
    int ia[]{1, 2, 3, 4, 5};

    vector<int, stl::Allocator<int>> iv(ia, ia + 5);

    for (const auto &ele : iv)
        std::cout << ele << endl;
    return 0;
}