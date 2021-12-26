#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/average-waiting-time/

using namespace std;

/**
 * @brief computes the average waitng time
 *
 * @param customers customer matrix
 * @return double average waitng time
 */
double compute(vector<vector<int>>& customers)
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
	vector<vector<int>> input;

	int n = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a = 0, o = 0;
		cin >> a >> o;
		vector<int> x;
		x.push_back(a);
		x.push_back(o);
		input.push_back(x);
	}

	cout << compute(input) << endl;

	return 0;
}
