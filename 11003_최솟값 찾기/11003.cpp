#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

typedef pair<int, int> node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int L;

	// node first : value
	// node second : index

	cin >> N >> L;
	vector<node> vec;
	deque<node> deq;
	vec.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].first;
		vec[i].second = i;
	}

	for (int i = 0; i < N; i++)
	{
		while (true)
			if ((deq.size() <= 0) || (deq.back().first < vec[i].first))
				break;
			else
				deq.pop_back();

		deq.push_back(node(vec[i].first, vec[i].second));

		if (deq.back().second - L >= deq.front().second)
			deq.pop_front();

		cout << deq.front().first << " ";
	}

	return 0;
}
