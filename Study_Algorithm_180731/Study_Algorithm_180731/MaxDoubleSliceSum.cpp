#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> &A)
{
	size_t inputSize = A.size();

	int max_ending = A[1];
	int max_slice = 0;
	int preSlice = 0;

	bool bMax = false;
	size_t BeginIdx = 0;
	size_t EndIdx = 0;

	for (size_t i = 1; i < inputSize - 1; ++i)
	{
		if (bMax && max(0, max_ending + A[i]) == max_ending + A[i])
		{
			EndIdx = i;
		}
		max_ending = max(0, max_ending + A[i]);
		max_slice = max(max_slice, max_ending);

		if (preSlice != max_slice)
		{
			preSlice = max_slice;
			BeginIdx = i;
			bMax = true;
		}
	}

	int small = A[BeginIdx];

	for (size_t i = BeginIdx; i < EndIdx + 1; ++i)
		small = min(small, A[i]);

	return max_slice - small;
}
