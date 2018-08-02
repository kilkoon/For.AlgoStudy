#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(int n);
unsigned int fibonacci(int n, unordered_map<int, unsigned int>* table);

void main()
{

	cout << solution(90000)<< endl;

}

int solution(int n) {

	unordered_map<int, unsigned int> table;
	unsigned int answer = fibonacci(n, &table);

	return int(answer);
}

unsigned int fibonacci(int n, unordered_map<int, unsigned int>* table)
{
	if (0 == n || 1 == n)
		return n;

	unsigned int num1 = 0;
	unsigned int num2 = 0;

	auto iter = (*table).find(n - 2);
	if ((*table).end() != iter)
	{
		num1 = (*iter).second % (unsigned int)1234567;
	}
	else
	{
		num1 = fibonacci(n - 2, table) % (unsigned int)1234567;
	}

	iter = (*table).find(n - 1);
	if ((*table).end() != iter)
	{
		num2 = (*iter).second % (unsigned int)1234567;
	}
	else
	{
		num2 = fibonacci(n - 1, table) % (unsigned int)1234567;
	}

	unsigned int sum = (num1 + num2) % (unsigned int)1234567;
	(*table).emplace(n, sum);
	
	return  sum;
}
