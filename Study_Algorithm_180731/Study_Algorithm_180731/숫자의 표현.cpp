#include <string>
#include <vector>

using namespace std;

//int solution(int n) {
//	
//	size_t count = 0;
//	int sum = 0;
//
//	for (size_t i = 1; i <= n/2; ++i)
//	{
//		for (size_t j = i; j <= n; ++j)
//		{
//			sum += j;
//
//			if (sum == n)
//			{
//				++count;
//				break;
//			}
//		}
//	}
//
//	return answer;
//}

int solution(int n) {

	size_t count = 0;

	size_t max = sqrt(n);
	for (size_t i = 1; i <= n; ++i)
	{
		if (0 == n%i)
			++count;
	}

	return count;
}
