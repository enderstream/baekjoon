#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int A;
int C;
int G;
int T;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int S;
	int P;

	string pw;
	cin >> S >> P;
	pw.resize(S);

	for (int i = 0; i < S; i++)
		cin >> pw[i];

	cin >> A >> C >> G >> T;


	int start = 0;
	int end = P - 1;
	int cnt = 0;

	int a = 0;
	int c = 0;
	int g = 0;
	int t = 0;

	for (int i = start; i <= end; i++)
		switch (pw[i])
		{
		case 'A':
		{
			a++;
			break;
		}
		case 'C':
		{
			c++;
			break;
		}
		case 'G':
		{
			g++;
			break;
		}
		case 'T':
		{
			t++;
			break;
		}
		}




	while (end < S)
	{
		if (a >= A && c >= C && g >= G && t >= T)
			cnt++;

		switch (pw[start])
		{
		case 'A':
		{
			a--;
			break;
		}
		case 'C':
		{
			c--;
			break;
		}
		case 'G':
		{
			g--;
			break;
		}
		case 'T':
		{
			t--;
			break;
		}
		}
		start++;
		end++;

		if (end >= S)
			break;

		switch (pw[end])
		{
		case 'A':
		{
			a++;
			break;
		}
		case 'C':
		{
			c++;
			break;
		}
		case 'G':
		{
			g++;
			break;
		}
		case 'T':
		{
			t++;
			break;
		}
		}


	}

	cout << cnt;
}

