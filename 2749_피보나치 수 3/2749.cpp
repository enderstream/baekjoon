#include <iostream>

using namespace std;

typedef unsigned long long i64;

int main(int argc, char const *argv[])
{
    //period of pisano!
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    i64 N = 0;
    cin >> N;
    N %= 1500000;
    if (N == 0)
        cout << 0;
    else if (N == 1 || N == 2)
        cout << 1;
    else
    {
        int F0 = 0;
        int F1 = 1;
        int Fn = 1;
        for (i64 i = 3; i <= N + 1; i++)
        {
            Fn = F0 + F1;
            if (Fn >= 1000000)
                Fn %= 1000000;
            F0 = F1;
            F1 = Fn;
        }
        cout << Fn;
    }

    return 0;
}