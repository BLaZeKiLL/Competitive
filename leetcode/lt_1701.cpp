#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/average-waiting-time/

/**
 * @brief computes the average waitng time
 *
 * @param customers customer matrix
 * @return double average waitng time
 */
double compute(std::vector<std::vector<int>>& customers)
{
	double w = 0;
	int t = customers[0][0];
	int n = 0;

	for (int i = 0; i < customers.size() ; i++)
	{
		int a = customers[i][0];
		int o = customers[i][1];

		if (t == a)
		{
			w += o;
			t += o;
		}
		else if (t > a)
		{
			w += (t - a) + o;
			t += o;
		}
		else
		{
			w += o;
			t += (a - t) + o;
		}

		n++;
	}

	return w / n;
}

/**
 * @brief n = number of customers, customers = [[ai, oi]] where ai = arival time and oi = order time
 *
 * @return int
 */
int main()
{
	auto input = std::vector<std::vector<int>>();

	int n = 0;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a = 0, o = 0;
		std::cin >> a >> o;
		auto x = std::vector<int>();
		x.push_back(a);
		x.push_back(o);
		input.push_back(x);
	}

	std::cout << compute(input) << std::endl;

	return 0;
}
