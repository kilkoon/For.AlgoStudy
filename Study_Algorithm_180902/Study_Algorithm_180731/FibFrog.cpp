#include <vector>
#include <unordered_set>

using namespace std;


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
				if (0 != distBuffer && fib == dist + distBuffer)
				{
					distBuffer = dist + distBuffer;
					dist = 0;
					break;
				}
				else if (fib == dist)
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