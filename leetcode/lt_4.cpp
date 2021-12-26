#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/median-of-two-sorted-arrays/

double compute(std::vector<int>& nums1, std::vector<int>& nums2)
{
	double median;

	int m = nums1.size();
	int n = nums2.size();

	int sum = m + n;
	int index = sum / 2;

	int mi = 0, ni = 0;

	double l1, l2;

	while (mi + ni <= index)
	{
		if (mi != nums1.size() && (ni == nums2.size() || nums1[mi] < nums2[ni]))
		{
			l2 = l1;
			l1 = nums1[mi];
			mi++;
		}
		else
		{
			l2 = l1;
			l1 = nums2[ni];
			ni++;
		}
	}

	if (sum % 2 == 0)
	{
		median = (l1 + l2) / 2;
	}
	else
	{
		median = l1;
	}

	return median;
}

int main()
{
	int m, n;

	std::cin >> m >> n;

	std::vector<int> nums1, nums2;

	for (int i = 0; i < m; i++)
	{
		int x;
		std::cin >> x;
		nums1.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		nums2.push_back(x);
	}

	std::cout << compute(nums1, nums2) << std::endl;

	return 0;
}
