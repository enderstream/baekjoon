#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef vector<vector<int>> table;

int isInfested(table &T);

int CPU;
int connection;
vector<bool> infestedPC;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> CPU >> connection;

	table T;

	T.resize(CPU + 1, vector<int>(CPU + 1, 0));
	infestedPC.resize(CPU + 1, false);

	for (int i = 0; i < connection; i++)
	{
		int x, y;
		cin >> x >> y;
		T[x][y] = 1;
		T[y][x] = 1;
	}
	int cnt = isInfested(T);

	cout << cnt;
}

int isInfested(table &T)
{
	stack<int> S;
	int i = 1;
	int cnt = 0;

	S.push(0);//더미밸류
	do// 노드 안쓰고 스택으로 DFS 구현
	{
		S.pop();
		for (int j = 1; j <= CPU; j++)
		{
			if (T[i][j] == 1)
			{
				if (infestedPC[j] == false)
				{
					S.push(j);
					cout << "push : " << j << "\n";
					cnt++;
					infestedPC[j] = true;

					cout << "counted __ i, j : " << i << "," << j << "\n";
					T[i][j] = 0;
					T[j][i] = 0;
					cout << "T[" << i << "][" << j << "] : " << T[i][j] << "\n";
					cout << "T[" << j << "][" << i << "] : " << T[j][i] << "\n";
				}
			}
		}
		if (!S.empty())
		{
			i = S.top();
		}
		cout << "pop : " << i << '\n'<<'\n';
	} while (!S.empty());

	return cnt;
}