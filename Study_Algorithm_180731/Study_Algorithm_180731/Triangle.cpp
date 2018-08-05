#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int solution(vector<int> &A);

void main()
{

}

int solution(vector<int> &A)
{
	size_t inputSize = A.size();
	sort(A.begin(), A.end(), greater<int>());

	if (inputSize < 3)
		return 0;

	for (size_t i = 0; i < inputSize-2; ++i)
	{
		if (A[i] < 0)
			continue;
		for (size_t j = inputSize - 1; j > i+1; --j)
		{
			if (A[j] < 0)
				continue;
			for (size_t k = j-1; k > i; --k)
			{
				if (A[k] < 0)
					continue;

				size_t sum = size_t(A[j])+ size_t(A[k]);
				if (size_t(A[i])< sum)
					return 1;
			}
		}
	}
	return 0;
}
