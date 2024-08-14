#include <iostream>

using namespace std;

int sumTable[1025][1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int M;

	int input;
	int x1;
	int y1;
	int x2;
	int y2;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> input;
			sumTable[i][j] = sumTable[i - 1][j] + sumTable[i][j - 1] - sumTable[i - 1][j - 1] + input;
		}

	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sumTable[x2][y2] + sumTable[x1 - 1][y1 - 1] - sumTable[x1 - 1][y2] - sumTable[x2][y1 - 1] << "\n";
	}
}