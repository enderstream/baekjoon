#include <iostream>
#include <vector>

using namespace std;

int find_prime_falindrom(int N);
bool is_falindrom(int falindrom);
bool is_prime(int falindrom);

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    cout << find_prime_falindrom(N);

    return 0;
}

int find_prime_falindrom(int N)
{
    int falindrom = N;

    while (true)
        if (is_falindrom(falindrom) && is_prime(falindrom))
            return falindrom;
        else
            falindrom++;
}

bool is_falindrom(int falindrom)
{
    string str_falindrom = to_string(falindrom);
    int i = 0;
    int j = str_falindrom.size() - 1;

    while (i < j)
        if (str_falindrom[i++] != str_falindrom[j--])
            return false;

    return true;
}

bool is_prime(int falindrom)
{
    if (falindrom == 1)
        return false;

    if (falindrom == 2)
        return true;

    if (falindrom % 2 == 0)
        return false;

    for (int i = 3; i * i <= falindrom; i += 2)
        if (falindrom % i == 0)
            return false;

    return true;
}
