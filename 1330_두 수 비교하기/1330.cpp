﻿#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a;
	int b;

	cin >> a >> b;

	if (a > b)
		cout << ">";
	else if (a == b)
		cout << "==";
	else
		cout << "<";

	return 0;
}