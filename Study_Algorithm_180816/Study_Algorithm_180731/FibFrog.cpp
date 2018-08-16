#include <vector>
#include <unordered_set>

using namespace std;


int solution(vector<int> &A)
{
	size_t inputSize = A.size();
	unordered_set<int> fib;
	fib.reserve(inputSize);
	fib.emplace(0);
	fib.emplace(0);

	int preNum = 0;
	int prepreNum = 0;
	size_t accNum = 3;
	for (size_t i = 2; i < inputSize; ++i)
	{
		// i+1 이 피보나치 수인지 체크
		// A[i] ==1 일 때만 피보나치 가능
		// 
		int curNum = prepreNum + preNum;
		fib.emplace(curNum);
		if (1 == A[i])
		{
			if (fib.end != fib.find(i + 1))
			{
				accNum = 0;
			}
		}

		++accNum;
		prepreNum = preNum;
		preNum = curNum;
	}

}