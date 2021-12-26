#include <string>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/longest-palindromic-substring/

// SOLUTION : https://www.youtube.com/watch?v=XYQecbcd6_c

// LINEAR_TIME : https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/

using namespace std;

string compute(string& s)
{
	int max = 0, l = 0, r = 0, size = s.size();
	int lmax = 0;

	for (int i = 0; i < size; i++)
	{
		// Odd Length
		l = i;
		r = i;

		while (l >= 0 && r < size && s[l] == s[r])
		{
			int len = (r - l) + 1;
			if (len > max)
			{
				max = len;
				lmax = l;
			}
			l--;
			r++;
		}

		// Even Length
		l = i;
		r = i + 1;

		while (l >= 0 && r < size && s[l] == s[r])
		{
			int len = (r - l) + 1;
			if (len > max)
			{
				max = len;
				lmax = l;
			}
			l--;
			r++;
		}
	}

	return s.substr(lmax, max);
}

int main()
{
	string input;

	cin >> input;

	cout << compute(input) << endl;

	return 0;
}
