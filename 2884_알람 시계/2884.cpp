#include <iostream>

using namespace std;

int main()
{
    int H;
    int M;

    cin >> H >> M;

    M -= 45;
    if (M < 0)
    {
        H--;
        M += 60;
    }

    if (H < 0)
        H = 23;

    cout << H << " " << M;

    return 0;
}