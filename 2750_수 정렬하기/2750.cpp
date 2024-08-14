#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	vector<int> vec(n, 0);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(),vec.end());

	for (int i = 0; i < n; i++)
		cout << vec[i] << endl;
}