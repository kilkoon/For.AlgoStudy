#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> &A)
{
	size_t inputSize = A.size();

	int max_ending = 0;
	int max_slice = 0;
	int preMaxSlice = 0;

	int smallNum= A[1];
	int smallBuffer = 0;

	for (size_t i = 1; i < inputSize - 1; ++i)
	{
		if (A[i] < smallBuffer)
			smallBuffer = A[i];

		max_ending = max(0, max_ending + A[i]);
		max_slice = max(max_slice, max_ending);

		if (preMaxSlice != max_slice)
			smallNum = smallBuffer;
		else
			smallBuffer = A[i];

		preMaxSlice = max_slice;
	}

	return max_slice - smallNum;
}

int solution(vector<int> &A)
{
	size_t inputSize = A.size();

	int max_ending = 0;
	int max_slice = 0;

	for (size_t i = 1; i < inputSize - 1; ++i)
	{
		max_ending = max(0, max_ending + A[i]);
		max_slice = max(max_slice, max_ending);
	}

	return max_slice;
}