#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long cnt = 0;
long result = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long N;
	long M;
	long input;
	cin >> N >> M;

	vector<long> sum(N + 1, 0);
	vector<long> mod(M, 0);
	sum[0] = 0;

	for (long i = 1; i <= N; i++)
	{
		cin >> input;
		sum[i] = (sum[i - 1] + input) % M;
	}

	for (long i = 1; i <= N; i++)
		mod[sum[i]]++;

	result += mod[0];

	for (long i = 0; i < M; i++)
		result += (mod[i] * (mod[i] - 1)) / 2;

	cout << result;
	return 0;
}