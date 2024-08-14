#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N = 0;
	cin >> N;

	vector<int> nums(N + 1, 0);

	for (int i = 2; i <= N; i++)
	{
		nums[i] = nums[i - 1] + 1;
		if (i % 2 == 0)
			nums[i] = min(nums[i / 2] + 1, nums[i]);
		if (i % 3 == 0)
			nums[i] = min(nums[i / 3] + 1, nums[i]);
	}

	cout << nums[N];
}