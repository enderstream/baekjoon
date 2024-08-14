#include <iostream>
#include <vector>
#include <string>

using namespace std;

void index_mediate(int &index, int N);

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int K = 0;
    int idx = 0;
    string answer = "<";

    cin >> N >> K;

    vector<pair<int, bool>> josephus(N + 1, pair(0, true));
    for (int i = 1; i <= N; i++)
        josephus[i].first = i;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            index_mediate(idx, N);
            while (!josephus[idx].second)
                index_mediate(idx, N);
        }

        answer += to_string(josephus[idx].first) + ", ";
        josephus[idx].second = false;
    }

    answer.pop_back();
    answer.pop_back();
    answer += ">";

    cout << answer;

    return 0;
}

void index_mediate(int &index, int N)
{
    index++;
    if (index > N)
        index %= N;
    if (index == 0)
        index++;
}