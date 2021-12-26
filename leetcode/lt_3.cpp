#include <iostream>
#include <string>
#include <unordered_map>

// PROBLEM : https://leetcode.com/problems/longest-substring-without-repeating-characters/

int compute(std::string& s)
{
	if (s.size() == 0) return 0;

	int plen = 1;
	int llen = 1;

	auto map = std::unordered_map<char, int>();

	map[s.at(0)] = 0;

	for (int i = 1; i < s.size(); i++)
	{
		char c = s.at(i);

		if (map.find(c) == map.end()) {
			map[c] = i;
			plen++;
			if (plen > llen) llen = plen;
		} else {
			int pi = map[c];

			map.clear();

			for (int x = pi + 1; x <= i; x++) {
				map[s.at(x)] = x;
			}

			plen = i - pi;
		}
	}

	return llen;
}

/**
 * @brief Maintains 2 pointers L and R that way no need to
 * clear the map
 *
 * @param s
 * @return int
 */
int compute2(std::string& s)
{
	int ans = 0;
	auto hash = std::unordered_map<char, int>();

	for(int l = 0, r = 0; r < s.length(); r++)
	{
		if (hash.find(s[r]) != hash.end() && l <= hash[s[r]])
			l = hash[s[r]] + 1;
		else ans = std::max(ans, r-l+1);

		hash[s[r]] = r;
	}

	return ans;
}

int main()
{
	auto input = std::string();

	std::getline(std::cin, input);

	std::cout << compute(input) << std::endl;

	return 0;
}
