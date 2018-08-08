#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>
using namespace std;

void GetMoney(size_t& count, int sum, stack<int> moneyStack);

int solution(int n, vector<int> money) {

	sort(money.begin(), money.end(), less<int>());
	size_t count = 0;
	stack<int> moneyStack;
	for (int num : money)
		moneyStack.push(num);
	
	int sum = n;
	
	GetMoney(count, sum, moneyStack);


	return count;
}

void GetMoney(size_t& count, int sum, stack<int> moneyStack)
{
	if (0 == sum)
	{
		++count;
		return;
	}
	else if (0 > sum)
		return;

	if (true == moneyStack.empty())
		return;

	int top = moneyStack.top();
	int quotient = sum / top;

	moneyStack.pop();
	for (size_t i = 0; i <= quotient; ++i)
	{
		GetMoney(count, sum - top*i, moneyStack);
	}
}
