#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/first-bad-version/

// NOTE : Needs to be run on leetcode IDE as an API is provided

using namespace std;

/**
 * @brief Defined by leetcode
 * bellow impl is a guess
 * @param version
 * @return true
 * @return false
 */
bool isBadVersion(int version, int bad)
{
	return version >= bad;
}

int compute(int n, int b)
{
	if (n == 1) return n;

	long long int l = 0, r = n;
	bool last = false;

	while (l <= r)
	{
		long long int mid = (l + r) / 2;
		bool bad = isBadVersion(mid, b);
		bool pbad = isBadVersion(mid - 1, b);

		if (bad && !pbad) return mid;
		else if (bad) r = mid;
		else l = mid + 1;

		last = bad;
	}

	return -1;
}

int main()
{
	int n = 0, b = 0;

	cin >> n >> b;

	cout << compute(n, b) << endl;

	return 0;
}
