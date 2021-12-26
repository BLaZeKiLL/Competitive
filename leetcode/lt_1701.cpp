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
	double total_wait = 0;
	int time = customers[0][0];
	int num_customers = 0;

	for (int i = 0; i < customers.size() ; i++)
	{
		int arrival = customers[i][0];
		int order = customers[i][1];

		if (time == arrival)
		{
			total_wait += order;
			time += order;
		}
		else if (time > arrival)
		{
			total_wait += (time - arrival) + order;
			time += order;
		}
		else
		{
			total_wait += order;
			time += (arrival - time) + order;
		}

		num_customers++;
	}

	return total_wait / num_customers;
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
		int arrival = 0, order = 0;
		cin >> arrival >> order;
		vector<int> x;
		x.push_back(arrival);
		x.push_back(order);
		input.push_back(x);
	}

	cout << compute(input) << endl;

	return 0;
}
