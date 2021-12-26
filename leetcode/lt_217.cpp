#include <unordered_map>
#include <vector>
#include <iostream>

// PROBLEM : https://leetcode.com/problems/contains-duplicate/

bool compute(std::vector<int>& nums)
{
	auto hash_map = std::unordered_map<int, int>();

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

	std::cin >> n;

	auto input = std::vector<int>();

	for (int i = 0; i < n; i++)
	{
		int x = 0;
		std::cin >> x;
		input.push_back(x);
	}

	bool result = compute(input);

	if (result)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}

	return 0;
}
