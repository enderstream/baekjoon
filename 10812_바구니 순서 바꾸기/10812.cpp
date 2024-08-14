#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int N;
    int M;
    bool tf = true;

    cin >> N >> M;

    vector<int> bucketA(N + 1, 0);
    vector<int> bucketB(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        bucketA[i] = i;
        bucketB[i] = i;
    }

    for (int t = 1; t <= M; t++)
    {
        if (tf) // A to B
        {
            int i = 0; // begin
            int j = 0; // end
            int k = 0; // mid
            int n = 0;

            cin >> i >> j >> k;

            n = i;
            for (int x = k; x <= j; x++)
                bucketB[n++] = bucketA[x];

            for (int x = i; x < k; x++)
                bucketB[n++] = bucketA[x];

            for (int i = 1; i <= N; i++)
                bucketA[i] = bucketB[i];
            
            tf = false;
        }
        else // B to A
        {
            int i = 0;
            int j = 0;
            int k = 0;
            int n = 0;

            cin >> i >> j >> k;

            n = i;
            for (int x = k; x <= j; x++)
                bucketA[n++] = bucketB[x];

            for (int x = i; x < k; x++)
                bucketA[n++] = bucketB[x];

            for (int i = 1; i <= N; i++)
                bucketB[i] = bucketA[i];

            tf = true;
        }
    }

    if (tf)
        for (int i = 1; i <= N; i++)
            cout << bucketA[i] << " ";
    else
        for (int i = 1; i <= N; i++)
            cout << bucketB[i] << " ";

    return 0;
}
