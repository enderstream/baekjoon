#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int M = -1;
	float sum = 0;
	cin >> N;
	vector<float> grade(N,0);
	vector<float> grade2(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> grade[i];

		if (grade[i] > M)
			M = grade[i];
	}

	for (int i = 0; i < N; i++)
	{
		grade2[i] = (grade[i]*100)/M;
		sum += grade2[i];
	}
	cout << sum / N;

}