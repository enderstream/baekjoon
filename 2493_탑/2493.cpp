#include <iostream>
#include <vector>
#include <stack>
#define INF 100000001
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;
    vector<int> towers(N + 1, 0);
    stack<pair<int, int>> tower_stack;

    for (int i = 1; i <= N; i++)
        cin >> towers[i];

    int max_height = 0;
    tower_stack.push(make_pair(INF, 0));

    for (int i = 1; i <= N; i++)
    {
        while (tower_stack.top().first < towers[i])
            tower_stack.pop();
        cout << tower_stack.top().second << " ";
        tower_stack.push(make_pair(towers[i], i));
    }

    return 0;
}