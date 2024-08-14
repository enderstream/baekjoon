#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int M;
	int cnt = 0;

	cin >> N >> M;

	int x = 0;
	int y = N - 1;
	vector<int> vec(N, 0);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	while (x < y)
		if (vec[x] + vec[y] > M)
			y--;
		else if (vec[x] + vec[y] < M)
			x++;
		else
		{
			x++;
			y--;
			cnt++;
		}

	cout << cnt;
}