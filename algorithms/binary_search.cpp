#include <vector>
#include <iostream>

using namespace std;

int binary_search(vector<int> &nums, int target)
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

	return -1;
}
