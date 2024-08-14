#include <iostream>
#include <vector>

using namespace std;

void get_prime_square(long max_num);

vector<long> primes;
vector<long> prime_square;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long min_num = 0;
    long max_num = 0;
    int cnt = 0;
    
    cin >> min_num >> max_num;

    vector<bool> nums_by_index(max_num - min_num + 1, true);

    get_prime_square(max_num);

    for (int i = 0; i < prime_square.size(); i++)
    {
        long lack_of = prime_square[i] - (min_num % prime_square[i]);
        if(lack_of == prime_square[i])
            lack_of = 0;
        for (long j = lack_of; j < nums_by_index.size(); j += prime_square[i])
            nums_by_index[j] = false;   
    }
    
    for (int i = 0; i < nums_by_index.size(); i++)
        if (nums_by_index[i])
            cnt++;

    cout << cnt;

    return 0;
}

void get_prime_square(long max_num)
{
    for (long i = 0; i * i <= max_num; i++)
        primes.push_back(i);

    for (long p = 2; p * p <= max_num; p++)
        if (primes[p] > 1)
        {
            for (long i = p * p; i < primes.size(); i += p)
                primes[i] = -1;
            prime_square.push_back(p * p);
        }
}

// 18,446,744,073,709,551,615
// 18,446,744,073,709,551,615
// 00,000,001,000,000,000,000
// 00,000,000,004,294,967,295
// 1000000000000 1000001000000
