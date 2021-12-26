#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/maximum-subarray/

using namespace std;

int recurse(vector<int>& nums, int index, int sum, bool take)
{
	if (index == nums.size()) return sum;

	int take_sum = sum;

	if (sum == INT_MIN)
	{
		take_sum = recurse(nums, index + 1, nums[index], true);
	}
	else
	{
		take_sum = recurse(nums, index + 1, sum + nums[index], true);
	}

	int no_take_sum = sum;

	if (!take) no_take_sum = recurse(nums, index + 1, sum, false);

	return take_sum > no_take_sum ? take_sum : no_take_sum;
}

/**
 * @brief bottom up kinda
 * COMPLEXITY = 3 + 3(n-1)
 * @param nums
 * @return int
 */
int compute(vector<int>& nums)
{
	int index = 0;

	int take = recurse(nums, index + 1, nums[index], true);
	int no_take = recurse(nums, index + 1, INT_MIN, false);

	return take > no_take ? take : no_take;
}

/**
 * @brief DP top down
 * COMPLEXITY = n
 * @param nums
 * @return int
 */
int compute2(vector<int>& nums)
{
	int psum = nums[0];
	int lsum = psum;

	for (int i = 1; i < nums.size(); i++)
	{
		psum = max(psum + nums[i], nums[i]);
		if (psum > lsum) lsum = psum;
	}

	return lsum;
}

int main()
{
	int n = 0;

	cin >> n;

	vector<int> input;

	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		input.push_back(x);
	}

	cout << compute2(input) << endl;

	return 0;
}
