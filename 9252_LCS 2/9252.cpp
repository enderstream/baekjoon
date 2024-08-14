#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1;
    string s2;
    string LCS = "";
    cin >> s1 >> s2;

    int s1_len = s1.length();
    int s2_len = s2.length();

    vector<vector<int>> DP(s1_len + 1, vector<int>(s2_len + 1, 0));
    for (int i = 1; i <= s1_len; i++)
        for (int j = 1; j <= s2_len; j++)
            if (s1[i - 1] == s2[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);

    int x = s1_len;
    int y = s2_len;
    cout << DP[x][y] << "\n";

    while (true)
    {
        if (s1[x - 1] == s2[y - 1])
        {
            LCS.push_back(s1[x - 1]);
            x--;
            y--;
        }
        else if (DP[x - 1][y] > DP[x][y - 1])
            x--;
        else
            y--;

        if (x == 0 || y == 0)
            break;
    }
    for (int i = LCS.length() - 1; i >= 0; i--)
        cout << LCS[i];

    return 0;
}
