	#include <vector>
	#include <algorithm>
	#include <functional>

using namespace std;


int solution(vector<int> &A) 
{
	size_t inputSize = A.size();
	sort(A.begin(), A.end());

	if (0 == inputSize)
		return -1;

	int preNum = A[0];
	size_t count = 0;
	for (size_t i = 0; i < inputSize; ++i)
	{
		if (A[i] == preNum)
		{
			++count;
		}
		else
		{
			count = 1;
		}

		if (count > inputSize / 2)
			return i;

		preNum = A[i];
	}

	return -1;
}