#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ull;

vector<ull> factorial_vector;

bool is_decomposible(ull n);
ull find_factorial(ull n);
ull find_combination(ull n);

ull main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ull n;

    cin >> n;

    factorial_vector.push_back(1);
    factorial_vector.push_back(1);
    factorial_vector.push_back(2);
    
    if((n == 0) || (n == 1) || (n == 2))
    {
        cout << "YES";
    }
    else //n >= 3
    {

    }

    return 0;

    
    /*
    cin >> n;
    if (n == 0)
    {
        cout << "NO";
    }
    else if ((n == 1) || (n == 2))
    {
        cout << "YES";
    }
    else // n>= 3
    {
        if (is_decomposible(n))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    } */
}

bool is_decomposible(ull n) //memoization!!!! no memoization, nor DP 
{
    bool TF = false;

    ull x = 2;
    ull y = find_factorial(x);
    ull z = 0;

    while(n > y)
    {
        z = y;
        y = find_factorial(++x);
    }

    return TF;
}

ull find_factorial(ull n)
{

}

ull find_combination(ull n)
{
    ull x = 2;
    ull y = find_factorial(x);
    ull z = 0;
    while (n > y)
    {
        z = y;
        y = find_factorial(++x);
    }
    if (n == y)
    {
        return 1; //we found comobination!
    }
    else //n < y
    {
        return find_combination(n-z); //oops! over!
    }
}