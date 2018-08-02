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

	for (size_t i = 0; i < inputSize-2; ++i)
	{
		for (size_t j = inputSize - 1; j > i+1; --j)
		{
			for (size_t k = j-1; k > i; --k)
			{
				if (A[i] < A[j] + A[k])
					return 1;
			}
		}
	}
	return 0;
}
