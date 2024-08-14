#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int sum = 1;
	int cnt = 1;

	int start_index = 1;
	int end_index = 1;

	cin >> N;

	while (end_index != N)
		if (sum > N)
			sum -= start_index++;
		else if (sum <= N)
		{
			if (sum == N)
				cnt++;
			sum += ++end_index;
		}

	cout << cnt;
}
