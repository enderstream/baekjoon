#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    queue<int> josephus_q;
    vector<int> josephus_v;
    for (int i = 0; i < N; i++)
        josephus_q.push(i + 1);

    for (int i = 1; i <= N * K; i++)
    {
        int num = josephus_q.front();
        if (i % K == 0)
            josephus_v.push_back(num);
        else
            josephus_q.push(num);
        josephus_q.pop();
    }

    cout << "<";
    for (int i = 0; i < N - 1; i++)
        cout << josephus_v[i] << ", ";
    cout << josephus_v[N - 1] << ">";

    return 0;
}
