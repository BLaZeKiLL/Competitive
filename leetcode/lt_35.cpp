#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/search-insert-position/

using namespace std;

int compute(vector<int> &nums, int target)
{
	int l = 0, r = nums.size();

	while (l < r)
	{
		int mid = (l + r) / 2;
		int x = nums[mid];

		if (x == target) return mid;
		else if (x > target) r = mid;
		else l = mid + 1;
	}

	return l;
}

int main()
{
	int n = 0, target = 0;
	vector<int> input;

	cin >> n >> target;

	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		input.push_back(x);
	}

	cout << compute(input, target) << endl;

	return 0;
}
