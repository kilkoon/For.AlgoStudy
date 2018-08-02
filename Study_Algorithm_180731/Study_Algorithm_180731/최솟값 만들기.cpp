#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> A, vector<int> B);

void main()
{

	cout << solution()<< endl;
}

int solution(vector<int> A, vector<int> B)
{
	int sum = 0;
	size_t inputSize = A.size();

	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), less<int>());

	for (size_t i = 0; i<inputSize; ++i)
	{
		sum += A[i] * B[i];
	}
	
	return sum;
}