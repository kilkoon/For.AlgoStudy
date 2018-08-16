#include <unordered_set>

using namespace std;

int GetGCD(int n, int m);
int solution(int N, int M)
{
	int gcd = GetGCD(N, M);

	return (N / gcd);
}

int GetGCD(int n, int m)
{
	if (0 == n%m)
		return m;

	return GetGCD(m, n%m);
}
