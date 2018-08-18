#include <vector>
#include <unordered_set>

using namespace std;


//int solution(vector<int> &A)
//{
//	size_t inputSize = A.size();
//	unordered_set<int> fib;
//	fib.reserve(inputSize);
//	fib.emplace(0);
//	fib.emplace(0);
//
//	int preNum = 0;
//	int prepreNum = 0;
//	size_t accNum = 3;
//	for (size_t i = 2; i < inputSize; ++i)
//	{
//		// i+1 이 피보나치 수인지 체크
//		// A[i] ==1 일 때만 피보나치 가능
//		// 
//		int curNum = prepreNum + preNum;
//		fib.emplace(curNum);
//		if (1 == A[i])
//		{
//			if (fib.end != fib.find(i + 1))
//			{
//				accNum = 0;
//			}
//		}
//
//		++accNum;
//		prepreNum = preNum;
//		preNum = curNum;
//	}
//
//}

typedef struct jumpInfo
{
	jumpInfo(size_t jumpCnt, size_t accDist)
		:jumpCount(jumpCnt), accDistance(accDist)
	{}
	size_t jumpCount = 0;
	size_t accDistance = 0;

}JUMP;

unordered_set<int> GetFibonacci(int endNum);

int solution(vector<int> &A)
{
	int inputSize = A.size();
	unordered_set<int> fib = GetFibonacci(inputSize);
	vector<JUMP> frogJump;

	int initLeaf = -1;

	for (int i = 0; i < inputSize; ++i)
	{
		for (int j = 0; j < frogJump.size(); ++j)
			frogJump[j].accDistance += 1;

		if (0 == A[i])
			continue;

		// 잎이 있는 경우
		for (int j = 0; j < frogJump.size(); ++j)
		{
			// 그때까지 간 거리가 fib 수인 경우
			if (fib.end() != fib.find(frogJump[j].accDistance))
			{
				frogJump.emplace_back(JUMP(frogJump[j].jumpCount + 1, 0));
			}
		}
	}

	// 마지막 도착지

	int minJumpCnt = 0;
	for (int j = 0; j < frogJump.size(); ++j)
	{
		// 그때까지 간 거리가 fib 수인 경우
		if (fib.end() != fib.find(++frogJump[j].accDistance))
		{
			if (minJumpCnt > frogJump[j].jumpCount + 1)
				minJumpCnt = frogJump[j].jumpCount + 1;
		}
	}

	return 0 == minJumpCnt ? -1 : minJumpCnt;
}

unordered_set<int> GetFibonacci(int endNum)
{
	vector<int> fib;
	unordered_set<int> outFib;

	fib.reserve(endNum);
	fib.emplace_back(1);
	fib.emplace_back(1);
	outFib.emplace(1);

	size_t idx = 2;
	while (1)
	{
		int preSum = fib[idx - 2] + fib[idx - 1];

		if (preSum > endNum)
			return outFib;

		fib.emplace_back(preSum);
		outFib.emplace(preSum);
		++idx;
	}

	return outFib;
}
