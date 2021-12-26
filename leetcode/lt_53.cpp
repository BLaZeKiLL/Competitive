#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/maximum-subarray/

int recurse(std::vector<int>& nums, int index, int sum, bool take)
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
int compute(std::vector<int>& nums)
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
int compute2(std::vector<int>& nums)
{
	int psum = nums[0];
	int lsum = psum;

	for (int i = 1; i < nums.size(); i++)
	{
		psum = std::max(psum + nums[i], nums[i]);
		if (psum > lsum) lsum = psum;
	}

	return lsum;
}

int main()
{
	int n = 0;

	std::cin >> n;

	auto input = std::vector<int>();

	for (int i = 0; i < n; i++)
	{
		int x = 0;
		std::cin >> x;
		input.push_back(x);
	}

	std::cout << compute2(input) << std::endl;

	return 0;
}
