#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/min-cost-climbing-stairs/

using namespace std;

int compute(vector<int> &cost)
{
	int size = cost.size();

	if (size == 2) return min(cost[0], cost[1]);

	vector<int> table(size);

	table[0] = cost[0];
	table[1] = cost[1];

	for (int i = 2; i < size - 1; i++)
	{
		table[i] = min(table[i - 1] + cost[i], table[i - 2] + cost[i]);
	}

	return min(table[size - 2], table[size - 3] + cost[size - 1]);
}

/**
 * @brief model the indecies as it is in the problem
 * cost for height 0 is taken as 0 in my solution everything is shifted back by 1
 * which convolutes the solution a bit
 *
 * @param cost
 * @return int
 */
int compute_clean(vector<int> &cost)
{
	int n = cost.size();

	vector<int> dp(n + 1);

	dp[1] = cost[0];

	for (int i = 2; i <= n; i++)
	{
		dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i - 1];
	}

	return min(dp[n - 1], dp[n]);
}

int main()
{
	int n = 0;
	vector<int> input;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		input.push_back(x);
	}

	cout << compute(input) << endl;

	return 0;
}
