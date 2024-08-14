#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M = 0;
    int N = 0;
    cin >> M >> N;
    int limit = sqrt(N);

    vector<bool> primes(N + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i <= limit; i++)
        if (primes[i])
            for (int j = i; j * i <= N; j++)
                primes[j * i] = false;

    for (int i = M; i <= N; i++)
        if (primes[i])
            cout << i << "\n";

   return 0;
}
