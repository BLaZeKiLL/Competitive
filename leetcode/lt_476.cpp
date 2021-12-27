#include <iostream>

// PROBLEM : https://leetcode.com/problems/number-complement/

using namespace std;

int compute(int num)
{
	long long int number_of_bits = floor(log2(num))+1;
	long long int comp = 1 << number_of_bits;
	return (comp - 1) ^ num;
}

int main()
{
	int num = 0;

	cin >> num;

	cout << compute(num) << endl;

	return 0;
}
