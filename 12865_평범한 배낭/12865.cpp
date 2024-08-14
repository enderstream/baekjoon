#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int K = 0;
    cin >> N >> K;

    vector<vector<int>> luggages(N, vector<int>(2, 0));
    vector<int> DP(K + 1, 0);
    for (int i = 0; i < N; i++)
        cin >> luggages[i][0] >> luggages[i][1];

    for (int i = 0; i < N; i++) 
        for (int j = K; j >= luggages[i][0]; j--) // important!!
            if (DP[j] < DP[j - luggages[i][0]] + luggages[i][1]) 
                DP[j] = DP[j - luggages[i][0]] + luggages[i][1];
        
        
    

    cout << DP[K];

    return 0;
}
