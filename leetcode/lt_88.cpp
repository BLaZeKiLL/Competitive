#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/merge-sorted-array/

using namespace std;

void compute(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int> ans;

	int mi = 0, ni = 0;

	for (int i = 0; i < m + n; i++)
	{
		if (mi >= m && ni < n)
		{
			ans.push_back(nums2[ni]);
			ni++;
		}
		else if (ni >= n && mi < m)
		{
			ans.push_back(nums1[mi]);
			mi++;
		}
		else
		{
			int mx = nums1[mi];
			int nx = nums2[ni];

			if (mx < nx)
			{
				ans.push_back(nums1[mi]);
				mi++;
			}
			else
			{
				ans.push_back(nums2[ni]);
				ni++;
			}
		}
	}


	nums1 = ans;
}

int main()
{
	int m, n;

	cin >> m >> n;

	vector<int> nums1, nums2;

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		nums1.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		nums2.push_back(x);
	}

	return 0;
}
