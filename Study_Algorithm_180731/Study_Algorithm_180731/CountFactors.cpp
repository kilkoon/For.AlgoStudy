#include <math.h>

using namespace std;


int solution(int N) 
{
	size_t endIdx = sqrt(N);
	size_t count = 0;

	for (size_t i = 1; i <= endIdx; ++i)
	{
		if (0 == N%i)
			count+=2;
	}

	if (pow(int(sqrt(N)), 2) == N)
		--count;

	return count;
}