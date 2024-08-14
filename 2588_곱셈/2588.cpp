#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x = 0;
	int y = 0;

	cin >> x >> y;

	cout << x * (y % 10) << "\n"
		 << x * int((y % 100) / 10) << "\n"
		 << x * (y / 100) << "\n"
		 << x * y;
}
