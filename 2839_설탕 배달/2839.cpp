#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0;
	cin >> n;
	int cnt = 0;
	bool done = true;

	if (n % 5 == 0)
		cout << n / 5;
	else
	{
		while (true)
		{
			n -= 3;
			if (n >= 3 || n == 0)
				cnt++;
			else
			{
				cout << -1;
				done = false;
				break;
			}
			if (n % 5 == 0)
				break;
		}
		if (done)
			cout << cnt + (n / 5);
	}
}
