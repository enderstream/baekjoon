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
	cin >> N;

	vector<int> vec(N, 0);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	sort(vec.begin(),vec.end());
	
	for (int i = 0; i < N; i++)
		cout << vec[i] << "\n";
	
	return 0;
}
