#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/squares-of-a-sorted-array/

using namespace std;

void compute(vector<int> &nums, int k)
{
	int size = nums.size();

	if (size == 1)
		return;

	k = k % size;

	int r = size - k;

	vector<int> result;

	for (int i = r; i < size; i++)
	{
		result.push_back(nums[i]);
	}

	for (int i = 0; i < r; i++)
	{
		result.push_back(nums[i]);
	}

	nums = result;
}

int main()
{
	int n = 0, k = 0;
	vector<int> input;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		input.push_back(x);
	}

	compute(input, k);

	return 0;
}
