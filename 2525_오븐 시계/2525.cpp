#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int H;
    int M;
    int T;

    cin >> H >> M >> T;

    H += T / 60;
    M += T % 60;

    if (M >= 60)
    {
        M -= 60;
        H++;
    }
    if (H >= 24)
        H -= 24;

    cout << H << " " << M;

    return 0;
}