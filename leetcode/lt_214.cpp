#include <string>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/shortest-palindrome/

// OPTIMAL : https://leetcode.com/problems/shortest-palindrome/discuss/60113/Clean-KMP-solution-with-super-detailed-explanation

using namespace std;

string compute(string& s)
{
	int size = s.size();

	if (size == 0) return s;

	string anso, anse;

	bool foundo = false, founde = false;

	for (int i = size / 2; i >= 0; i--)
	{
		int lo = i, ro = i;

		while (lo > 0 && s[lo] == s[ro]) {
			lo--;
			ro++;
		}

		if (lo == 0 && s[lo] == s[ro]) {
			anso = s.substr(ro + 1, size - (ro + 1));

			foundo = true;
		}

		int le = i, re = i + 1;

		while (le > 0 && s[le] == s[re]) {
			le--;
			re++;
		}

		if (le == 0 && s[le] == s[re]) {
			anse = s.substr(re + 1, size - (re + 1));

			founde = true;
		}

		if (foundo || founde) break;
	}

	if (foundo && founde)
	{
		if (anso.size() < anse.size())
		{
			reverse(anso.begin(), anso.end());

			return anso.append(s);
		}
		else
		{
			reverse(anse.begin(), anse.end());

			return anse.append(s);
		}
	}
	else if (foundo)
	{
		reverse(anso.begin(), anso.end());

		return anso.append(s);
	}
	else
	{
		reverse(anse.begin(), anse.end());

		return anse.append(s);
	}
}

int main()
{
	string input;

	cin >> input;

	cout << compute(input) << endl;

	return 0;
}
