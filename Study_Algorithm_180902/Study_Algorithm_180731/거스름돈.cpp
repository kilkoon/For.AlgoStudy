#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


int GetMoney(int sum, vector<int>* moneyStack);

int solution(int n, vector<int> money) {

	//sort(money.begin(), money.end(), less<int>());
	int sum = n;

	return GetMoney(sum, &money);
}

int GetMoney(int sum, vector<int>* moneyVec)
{
	vector<int> tmpVec = *moneyVec;
	
	if (0 == sum)
	{
		return 1;
	}
	else if (0 > sum)
		return 0;

	if (0 == tmpVec.size())
		return 0;
	
	int top = *tmpVec.end();
	int quotient = sum / top;

	tmpVec.pop_back();
	int count = 0;
	for (size_t i = 0; i <= quotient; ++i)
	{
		count += GetMoney(sum - top*i, &tmpVec);
	}
	return count;
}


