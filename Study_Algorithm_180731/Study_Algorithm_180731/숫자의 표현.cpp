#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// 둘다 시간 초과

int solution(int n)
{
	size_t count = 0;

	for (size_t i = 1; i <= n/2; ++i)
	{
		for (size_t j = i+1; j <= n / 2 + 1; ++j)
		{
			size_t sum = (pow(j, 2) - pow(i, 2) + i + j) / 2;
			if (sum > n)
				break;
			if (n == sum)
				++count;
		}
	}

	return count+1;
}

int solution(int n) {

	size_t count = 0;
	size_t max = n / 2 + 1;

	unordered_set<int> sum;
	sum.reserve(max);

	for (size_t i = 1; i <= max; ++i)
	{
		int partialSum = int(((1 + i) * i)*0.5f);
		sum.emplace(partialSum);
		
		int minus = partialSum - n;
		if ((minus > 0 && sum.end() != sum.find(minus))
			|| partialSum == n)
		{
			++count;
		}
	}

	return count+1;
}

int solution(int n) {

	size_t count = 0;
	size_t max = n / 2 + 1;

	int* sum = new int[int(((1 + max) * max) >> 1)];
	memset(sum, 0, sizeof(int(((1 + max) * max) >> 1)));

	for (size_t i = 1; i <= max; ++i)
	{
		int partialSum = int(((1 + i) * i)*0.5f);
		sum[partialSum] = 1;

		int minus = partialSum - n;
		if ((minus > 0 && sum[minus] == 1)
			|| minus == 0)
		{
			++count;
		}
	}

	return count + 1;
}