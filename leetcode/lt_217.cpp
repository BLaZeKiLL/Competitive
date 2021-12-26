#include <unordered_map>
#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/contains-duplicate/

using namespace std;

bool compute(vector<int>& nums)
{
	unordered_map<int, int> hash_map;

	bool result = false;

	for (int i = 0; i < nums.size(); i++)
	{
		if (hash_map.find(nums[i]) != hash_map.end())
		{
			result = true;
			break;
		}
		else
		{
			hash_map[nums[i]] = 1;
		}
	}

	return result;
}

int main()
{
	int n = 0;

	cin >> n;

	vector<int> input;

	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		input.push_back(x);
	}

	bool result = compute(input);

	if (result)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	return 0;
}
