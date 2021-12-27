#include <vector>
#include <string>
#include <iostream>

// EXPLANATION : https://www.youtube.com/watch?v=V5-7GzOfADQ&t=1021s
// IMPLEMENTATION : https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

using namespace std;

vector<int> compute_lsp(string& pattern)
{
	int i = 1, len = 0, size = pattern.size();

	vector<int> lsp(size);

	while (i < size)
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			lsp[i] = len;
			i++;
		}
		else
		{
			if (len != 0) len = lsp[len - 1]; // bring back
			else
			{
				lsp[i] = 0;
				i++;
			}
		}
	}

	return lsp;
}

vector<int> kmp_search(string& text, string& pattern)
{
	vector<int> result;

	int size_text = text.size(), size_pattern = pattern.size();

	vector<int> lsp = compute_lsp(pattern);

	int i = 0, j = 0;

	while (i < size_text)
	{
		if (pattern[j] == text[i])
		{
			i++;
			j++;
		}

		if (j == size_pattern)
		{
			result.push_back(i - j);
			j = lsp[j - 1]; // bring back
		}
		else if (i < size_text && pattern[j] != text[i])
		{
			if (j != 0) j = lsp[j-1]; // bring back
			else i++;
		}
	}

	return result;
}

int main()
{
	string text = "BDACABACACDAAJHACABACACDKOJACABACACD";
	string pattern = "ACABACACD";

	vector<int> result = kmp_search(text, pattern);

	return 0;
}
