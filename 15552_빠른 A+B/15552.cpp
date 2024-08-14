#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	int A;
	int B;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		cout << A + B << "\n";
	}
}