#include <vector>
using namespace std;

int solution(vector<int> &A)
{
	int sum = 0;

	size_t inputSize = A.size();
	if (1 == inputSize)
		return A[0];

	sum += A[0];
	sum += A[inputSize-1];
	for (size_t i = 1; i < inputSize-1; ++i)
	{
		if (A[i] > 0)
			sum += A[i]; 
	}

	return sum;
}