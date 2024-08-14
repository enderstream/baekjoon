#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool isGood(vector<long long> vec, int i);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	int N;
	cin >> N;

	vector<long long> vec(N, 0);
	for (int i = 0; i < N; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
		if (isGood(vec, i))
			cnt++;

	cout << cnt;
}

bool isGood(vector<long long> vec, int i)
{
	bool tf = false;
	int x = 0;
 	int y = vec.size() - 1;
	long long find = vec[i];
	while (x < y)
		if (vec[x] + vec[y] > find)
			y--;
		else if (vec[x] + vec[y] < find)
			x++;
		else // vec[x] + vec[y] == vec[i]
			if ((x != i) && (y != i)) //vec[x] != find 로 하는게 아님!!
				return true;
			else if (x == i)
				x++;
			else
				y--;
			

	
	return tf;
}