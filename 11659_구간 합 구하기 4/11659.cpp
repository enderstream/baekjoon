#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	vector<int> sum(N + 1, 0);
	vector<int> sum2(M, 0);
	sum[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		sum[i] = sum[i - 1] + input;
	}
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		sum2[i] = sum[y] - sum[x - 1];
	}
	for (int i = 0; i < M; i++)
		cout << sum2[i] << "\n";
		
	return 0;
}