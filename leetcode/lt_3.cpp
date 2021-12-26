#include <iostream>
#include <string>
#include <unordered_map>

// PROBLEM : https://leetcode.com/problems/longest-substring-without-repeating-characters/

using namespace std;

int compute(string& s)
{
	if (s.size() == 0) return 0;

	int prev_len = 1;
	int max_len = 1;

	unordered_map<char, int> hash;

	hash[s.at(0)] = 0;

	for (int i = 1; i < s.size(); i++)
	{
		char c = s.at(i);

		if (hash.find(c) == hash.end()) {
			hash[c] = i;
			prev_len++;
			if (prev_len > max_len) max_len = prev_len;
		} else {
			int pi = hash[c];

			hash.clear();

			for (int x = pi + 1; x <= i; x++) {
				hash[s.at(x)] = x;
			}

			prev_len = i - pi;
		}
	}

	return max_len;
}

/**
 * @brief Maintains 2 pointers L and R that way no need to
 * clear the map
 *
 * @param s
 * @return int
 */
int compute2(string& s)
{
	int ans = 0;
	unordered_map<char, int> hash;

	for(int l = 0, r = 0; r < s.length(); r++)
	{
		if (hash.find(s[r]) != hash.end() && l <= hash[s[r]])
			l = hash[s[r]] + 1;
		else ans = max(ans, r-l+1);

		hash[s[r]] = r;
	}

	return ans;
}

int main()
{
	string input;

	getline(cin, input);

	cout << compute(input) << endl;

	return 0;
}
