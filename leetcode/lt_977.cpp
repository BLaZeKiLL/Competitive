#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/squares-of-a-sorted-array/

using namespace std;

vector<int> compute(vector<int>& nums)
{
	int size = nums.size();
	vector<int> result(size);
	int l = 0, r = size - 1;

	for (int i = size - 1; i >= 0; i--)
	{
		if (abs(nums[l]) > abs(nums[r]))
		{
			result[i] = nums[l] * nums[l];
			l++;
		}
		else
		{
			result[i] = nums[r] * nums[r];
			r--;
		}
	}

	return result;
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

	vector<int> result = compute(input);

	return 0;
}
