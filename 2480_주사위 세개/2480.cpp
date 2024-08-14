#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a;
    int b;
    int c;
    int P;

    cin >> a >> b >> c;
    vector<int> vec = {a, b, c};

    if ((a == b) && (b == c))
        P = 10000 + a * 1000;
    else if ((a != b) && (b != c) && (c != a))
    {
        int max = *max_element(vec.begin(), vec.end());
        P = 100 * max;
    }
    else if ((a == b) && (a != c))
        P = 1000 + 100 * a;
    else if ((c == b) && (a != c))
        P = 1000 + 100 * b;
    else
        P = 1000 + 100 * c;

    cout << P;
    return 0;
}