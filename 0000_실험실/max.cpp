#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 2, 3, 4, 5};
    list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << max({1, 2, 3, 4, 5});
    cout << *max_element(vec.begin(), vec.end());
    // int max_num = max(vec);

    // cout << max({vec});
    return 0;
}
