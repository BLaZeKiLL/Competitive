#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/median-of-two-sorted-arrays/

using namespace std;

double compute(vector<int>& nums1, vector<int>& nums2)
{
	double median;

	int m = nums1.size();
	int n = nums2.size();

	int sum = m + n;
	int index = sum / 2;

	int mi = 0, ni = 0;

	double last1, last2;

	while (mi + ni <= index)
	{
		if (mi != nums1.size() && (ni == nums2.size() || nums1[mi] < nums2[ni]))
		{
			last2 = last1;
			last1 = nums1[mi];
			mi++;
		}
		else
		{
			last2 = last1;
			last1 = nums2[ni];
			ni++;
		}
	}

	if (sum % 2 == 0)
	{
		median = (last1 + last2) / 2;
	}
	else
	{
		median = last1;
	}

	return median;
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

	cout << compute(nums1, nums2) << endl;

	return 0;
}
