#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/fibonacci-number/

using namespace std;

int compute(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	vector<int> fib(n + 1);

	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	return fib[n];
}

int main()
{
	int n = 0;

	cin >> n;

	cout << compute(n) << endl;

	return 0;
}
