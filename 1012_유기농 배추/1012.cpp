#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<vector<int>> farm;
typedef vector<farm> goranG;
typedef pair<int, int> set;

farm createFarm();
void checkWorm(farm F);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	goranG G;

	for (int i = 0; i < T; i++)
		checkWorm(createFarm());

	return 0;
}

farm createFarm()
{
	int M, N, K;
	farm F;
	cin >> M >> N >> K;
	F.resize(M + 2, vector<int>(N + 2, 0));

	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		F[x + 1][y + 1] = 1;
	}

	return F;
}

void checkWorm(farm F)
{
	int cnt = 0;

	set P;
	farm V(F.size(), vector<int>(F[0].size(), 0)); // 방문했는지를 체크하는 밭뙈기
	for (int i = 0; i < V.size(); i++)
		for (int j = 0; j < V[0].size(); j++)
			if (i == 0 || j == 0 || i == V.size() - 1 || j == V[0].size() - 1)
				V[i][j] = 1;

	stack<set> S;
	S.push(make_pair(-1, -1));

	for (int i = 1; i < V.size() - 1; i++)
		for (int j = 1; j < V[0].size() - 1; j++)
		{
			if (V[i][j] == 1 || F[i][j] == 0)
				continue;

			int x = i;
			int y = j;
			V[x][y] = 1;

			cnt++;

			S.push(make_pair(x, y));

			while (!S.empty())
			{

				if (V[x - 1][y] == 0 && F[x - 1][y] == 1)
				{
					S.push(make_pair(x - 1, y));
					V[x - 1][y] = 1;
				}
				if (V[x][y + 1] == 0 && F[x][y + 1] == 1)
				{
					S.push(make_pair(x, y + 1));
					V[x][y + 1] = 1;
				}
				if (V[x + 1][y] == 0 && F[x + 1][y] == 1)
				{
					S.push(make_pair(x + 1, y));
					V[x + 1][y] = 1;
				}
				if (V[x][y - 1] == 0 && F[x][y - 1] == 1)
				{
					S.push(make_pair(x, y - 1));
					V[x][y - 1] = 1;
				}

				P = S.top();
				S.pop();
				if (S.empty())
					break;

				// 다음자리로 옮기도록
				x = P.first;
				y = P.second;
			}
		}
	cout << cnt << '\n';
}
