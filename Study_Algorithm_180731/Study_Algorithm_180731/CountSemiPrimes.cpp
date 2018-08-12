#include <vector>
#include <unordered_set>
#include <math.h>
#include <iostream>

using namespace std;

bool IsPrime(int num);
vector<int> solution(int N, vector<int> &P, vector<int> &Q);

void main()
{
	vector<int> Q;
	vector<int> P;

	P.emplace_back(1);
	P.emplace_back(4);
	P.emplace_back(16);

	Q.emplace_back(26);
	Q.emplace_back(10);
	Q.emplace_back(20);


	vector<int>  answer = solution(26, P, Q);

	for (int n : answer)
		cout << n<< endl;

}



vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
	unordered_set<int> primeNum;
	primeNum.reserve(int(N));

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
