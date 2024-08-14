#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void length_synchronize(vector<int> &v1, vector<int> &v2);
void vector_sum(vector<int> v1, vector<int> v2, vector<int> &v3);
void carry_up(vector<int> &v);

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;
    vector<vector<int>> Fn(N + 1, vector<int>());
    Fn[0] = {0};
    Fn[1] = {1};

    for (int i = 0; i < N - 1; i++)
    {
        length_synchronize(Fn[i], Fn[i + 1]);
        vector_sum(Fn[i], Fn[i + 1], Fn[i + 2]);
    }

    for (int j = Fn[N].size() - 1; j >= 0; j--)
        cout << Fn[N][j];

    return 0;
}

void length_synchronize(vector<int> &v1, vector<int> &v2)
{
    // make sure both vectors are flipped reverse
    int len_diff = v1.size() - v2.size();
    if (len_diff == 0) // v1 == v2
        return;
    else if (len_diff < 0) // v1 < v2
        for (int i = 0; i < abs(len_diff); i++)
            v1.push_back(0);
    else // v2 < v1
        for (int i = 0; i < abs(len_diff); i++)
            v2.push_back(0);
}

void vector_sum(vector<int> v1, vector<int> v2, vector<int> &v3)
{
    // make sure both vectors are flipped reverse and have same length
    int vec_len = v1.size();
    for (int i = 0; i < vec_len; i++)
        v3.push_back(v1[i] + v2[i]);
    carry_up(v3);
}

void carry_up(vector<int> &v)
{
    if (v[v.size() - 1] >= 10)
        v.push_back(0);

    for (int i = 0; i < v.size() - 1; i++)
    {
        v[i + 1] += v[i] / 10;
        v[i] %= 10;
    }
}