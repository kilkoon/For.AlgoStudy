#include <vector>

using namespace std;

// binary search tree를 이중 for문으로 돌리자!

int solution(int K, int M, vector<int> &A)
{
	size_t inputSize = A.size();
	vector<int> partialSum;
	partialSum.reserve(inputSize);

	int acc = 0;
	for (int num : A)
	{
		acc += num;
		partialSum.emplace_back(acc);
	}


	size_t begin = 0;
	size_t end = inputSize-1;

	for (size_t i = 0; i < inputSize - 1; ++i)
	{	
		int preSum = partialSum[i];
		int postSum = partialSum[inputSize-1] - partialSum[i];

		if (preSum > postSum)
		{

		}
		else if (preSum < postSum)
		{
		}
		else if (preSum == postSum)
		{

		}
	}
}