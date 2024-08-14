#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    int N = 0;

    cin >> N;
    vector<vector<int>> houses(N, vector<int>(3, 0));
    vector<int> selected(3, 0);
    vector<int> temp(3, 0);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> houses[i][j];

    for (int i = 0; i < N; i++)
    {
        selected[0] = min(houses[i][0]+temp[1], houses[i][0]+temp[2]);
        selected[1] = min(houses[i][1]+temp[0], houses[i][1]+temp[2]);
        selected[2] = min(houses[i][2]+temp[0], houses[i][2]+temp[1]);

        for (int j = 0; j < 3; j++)
            temp[j] = selected[j];
    }

    cout << min({selected[0], selected[1], selected[2]});

    return 0;
}