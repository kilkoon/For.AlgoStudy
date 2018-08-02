#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int solution(vector<int> &A);

void main()
{
	vector<int> input;

	input.emplace_back(-3000);
	input.emplace_back(1000);
	input.emplace_back(1000);
	input.emplace_back(-3000);
	input.emplace_back(5000);
	input.emplace_back(6000);

	cout << solution(input)<< endl;
}

int solution(vector<int> &A)
{
	size_t inputSize = A.size();
	sort(A.begin(), A.end(), greater<int>());

	int sumPlus = A[0] * A[1] * A[2];
	int sumMinus = A[inputSize-1] * A[inputSize - 2] * A[0];

	return max(sumPlus, sumMinus);
}

