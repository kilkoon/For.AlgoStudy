#include <vector>
#include <unordered_set>

using namespace std;


//typedef struct jumpInfo
//{
//	jumpInfo(size_t jumpCnt, size_t accDist)
//		:jumpCount(jumpCnt), accDistance(accDist)
//	{}
//	size_t jumpCount = 0;
//	size_t accDistance = 0;
//
//}JUMP;
//
//unordered_set<int> GetFibonacci(int endNum);
//
//int solution(vector<int> &A)
//{
//	int inputSize = A.size();
//	unordered_set<int> fib = GetFibonacci(inputSize);
//	vector<JUMP> frogJump;
//
//	int initLeaf = -1;
//
//	for (int i = 0; i < inputSize; ++i)
//	{
//		for (int j = 0; j < frogJump.size(); ++j)
//			frogJump[j].accDistance += 1;
//
//		if (0 == A[i])
//			continue;
//
//		// 잎이 있는 경우
//		for (int j = 0; j < frogJump.size(); ++j)
//		{
//			// 그때까지 간 거리가 fib 수인 경우
//			if (fib.end() != fib.find(frogJump[j].accDistance))
//			{
//				frogJump.emplace_back(JUMP(frogJump[j].jumpCount + 1, 0));
//			}
//		}
//	}
//
//	// 마지막 도착지
//
//	int minJumpCnt = 0;
//	for (int j = 0; j < frogJump.size(); ++j)
//	{
//		// 그때까지 간 거리가 fib 수인 경우
//		if (fib.end() != fib.find(++frogJump[j].accDistance))
//		{
//			if (minJumpCnt > frogJump[j].jumpCount + 1)
//				minJumpCnt = frogJump[j].jumpCount + 1;
//		}
//	}
//
//	return 0 == minJumpCnt ? -1 : minJumpCnt;
//}
//
//unordered_set<int> GetFibonacci(int endNum)
//{
//	vector<int> fib;
//	unordered_set<int> outFib;
//
//	fib.reserve(endNum);
//	fib.emplace_back(1);
//	fib.emplace_back(1);
//	outFib.emplace(1);
//
//	size_t idx = 2;
//	while (1)
//	{
//		int preSum = fib[idx - 2] + fib[idx - 1];
//
//		if (preSum > endNum)
//			return outFib;
//
//		fib.emplace_back(preSum);
//		outFib.emplace(preSum);
//		++idx;
//	}
//
//	return outFib;
//}


int solution(vector<int> &A)
{
	A.emplace_back(1);
	size_t inputSize = A.size();
	vector<int> fibNum;
	fibNum.emplace_back(1);
	fibNum.emplace_back(1);

	int dist = 0;
	int distBuffer = 0;
	int jumpNum = 0;

	for (size_t i = 0; i < inputSize; ++i)
	{
		if (i >= 2)
		{
			fibNum.emplace_back(fibNum[i-2] + fibNum[i-1]);
		}

		++dist;
		if (1 == A[i])
		{
			for (int fib : fibNum)
			{
				if (fib == dist + distBuffer)
				{
					distBuffer = dist + distBuffer;
					dist = 0;
					break;
				}
				if (fib == dist)
				{
					++jumpNum;
					distBuffer = dist;
					dist = 0;
					break;
				}
			}

			if (inputSize - 1 == i && 0 != dist)
				return -1;
		}
	}

	return jumpNum;
}