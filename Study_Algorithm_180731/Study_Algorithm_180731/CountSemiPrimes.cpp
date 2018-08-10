#include <vector>
#include <unordered_set>

using namespace std;

bool IsPrime(int num);
bool IsSemiPrime(int num, const unordered_set<int>& primeNum);
vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
	unordered_set<int> primeNum;
	primeNum.reserve(int(sqrt(N)));

	size_t maxIdx = N;
	for (size_t i = 2; i <= maxIdx; ++i)
	{
		if (IsPrime(i))
			primeNum.emplace(i);
	}

	vector<int> semiCnt;
	semiCnt.resize(N+1, 0);
	int accCnt = 0;
	for (size_t i = 4; i <= N; ++i)
	{
		if (IsSemiPrime(i, primeNum))
			++accCnt;
		semiCnt[i] = accCnt;
	}

	
	size_t maxInput = P.size();
	vector<int> answer;
	answer.resize(maxInput, 0);

	for (size_t i = 1; i < maxInput; ++i)
	{
		answer[i] = semiCnt[Q[i]] - semiCnt[P[i-1]];
	}

	return answer;
}

bool IsPrime(int num)
{
	size_t maxIdx = sqrt(num);
	for (size_t i = 2; i <= maxIdx; ++i)
	{
		if (num%i != 0)
			return false;
	}

	return true;
}

bool IsSemiPrime(int num, const unordered_set<int>& primeNum)
{
	size_t maxIdx = sqrt(num);
	size_t count = 0;
	for (size_t i = 2; i <= maxIdx; ++i)
	{
		if (num%i == 0)
		{
			if (primeNum.end() != primeNum.find(i)
				&& primeNum.end() != primeNum.find(num / i))
			{
				count+=2;
			}
			else
				return false;
		}

		if (2 < count)
			return false;
	}

	if (2 == count)
		return true;
	else
		return false;
}
