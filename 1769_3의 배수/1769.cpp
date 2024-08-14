#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 1000010

using namespace std;

typedef vector<int> vec;
int cnt = 0;	
bool tf = false;

bool isDivBy3(vec v);
vec splitInt(int N);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	vec v(s.size(), 0);

	for (int i = 0; i < s.size(); i++)
		v[i] = s[i] - '0';

	if (v.size() == 1)
		cnt--;

	if (isDivBy3(v))
		cout <<cnt << '\n' << "YES";
	else
		cout << cnt << '\n' << "NO";
}

bool isDivBy3(vec v)
{
	cnt++;
	int N = 0;

	for (int i = 0; i < v.size(); i++)
		N += v[i];

	if (N > 9)
		isDivBy3(splitInt(N));
	else if (N == 3 || N == 6 || N == 9)
		return true;

	return false;
}

vec splitInt(int N)
{
	vec v;
	string s = to_string(N);
	v.resize(s.size(), 0);

	for (int i = 0; i < s.size(); i++)
		v[i] = s[i] - '0';

	return v;
}
