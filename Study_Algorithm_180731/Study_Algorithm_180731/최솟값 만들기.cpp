#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B);

void main()
{

	cout << solution()<< endl;
}

int solution(vector<int> A, vector<int> B)
{
	int size = A.size();

	vector<int> sum;
	sum.resize(size, 0);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			sum[j] = A[i] * B[j];

		}
	}

	
	return 0;
}