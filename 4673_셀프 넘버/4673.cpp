#include <iostream>
#include <vector>
#include <cmath>

#define MAX 10001

using namespace std;
typedef vector<int> vec;

vec createDigit(int n);
int findSelfNum(int n, vec digit);

int main()
{
	int dn;
	vec digit;
	vec table;
	table.resize(MAX);

	for (int i = 1; i < MAX; i++)
		table[i] = i;

	for (int i = 1; i < MAX; i++)
	{
		dn = findSelfNum(i, createDigit(i));
		if (dn < MAX)
			table[dn] = -1; 
	}

	for (int i = 1; i < MAX; i++)
		if (table[i] != -1)
			cout << table[i] << endl;

	return 0;
}

int findSelfNum(int n, vec digit)
{
	int dn = n;
	for (int i = 0; i < digit.size(); i++)
		dn += digit[i];

	return dn;
}

vec createDigit(int n)
{
	int log = (int)log10(n);
	vec power;
	vec digit;

	power.resize(log + 1);
	digit.resize(log + 1);

	for (int i = 0; i < power.size(); i++)
		power[i] = i;

	for (int i = 0; i < digit.size(); i++)
	{
		digit[i] = n % (int)(pow(10, (power[i] + 1)));
		if (i != 0)
			digit[i] = (digit[i] - digit[i - 1]) / int(pow(10, power[i]));
	}
	return digit;
}

