#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string S;
	vector<int>vec;
	long long N;
	cin >> N;

	S = to_string(N);

	for (int i = 0; i < S.size(); i++)
		vec.push_back(S[i] - '0');


	sort(vec.begin(), vec.end(), greater<int>());

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i];


}