#include <vector>
#include <unordered_set>
#include <math.h>

using namespace std;

bool IsPrime(int num);
vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
	unordered_set<int> primeNum;
	primeNum.reserve(int(sqrt(N)));

	for (int i = 2; i <= N; ++i)
	{
		if (IsPrime(i))
			primeNum.emplace(i);
	}

	vector<int> semiCnt;
	semiCnt.resize(N+1, 0);
	int accCnt = 0;
	for (int i = 4; i <= N; ++i)
	{
		for (int divide : primeNum)
		{
			if (int(sqrt(i)) < divide)
				break;

			if (0 == i%divide)
			{
				if (primeNum.end() != primeNum.find(i / divide))
					++accCnt;
				else
					break;
			}
		}
		semiCnt[i] = accCnt;
	}

	
	size_t maxInput = P.size();
	vector<int> answer;
	answer.reserve(maxInput);

	for (size_t i = 0; i < maxInput; ++i)
	{
		answer.emplace_back(semiCnt[Q[i]] - semiCnt[P[i] - 1]);
	}

	return answer;
}

bool IsPrime(int num)
{
	int maxIdx = int(sqrt(num));
	for (int i = 2; i <= maxIdx; ++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}
