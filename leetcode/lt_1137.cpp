#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/n-th-tribonacci-number/

using namespace std;

int compute(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;

	vector<int> trib(n + 1);

	trib[0] = 0;
	trib[1] = 1;
	trib[2] = 1;

	for (int i = 0; i <= n - 3; i++)
	{
		trib[i + 3] = trib[i] + trib[i + 1] + trib[i + 2];
	}

	return trib[n];
}

int main()
{
	int n = 0;

	cin >> n;

	cout << compute(n) << endl;

	return 0;
}
