#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/climbing-stairs/

using namespace std;

int compute(int n)
{
	n--;

	if (n == 0) return 1;
	if (n == 1) return 2;

	vector<int> fib(n + 1);

	fib[0] = 1;
	fib[1] = 2;

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
