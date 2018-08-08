#include <vector>

using namespace std;

int GetGDC(int a, int b);

int solution(vector<int> arr) 
{
	size_t inputSize = arr.size();

	int prevNum = arr[0];
	for (size_t i = 1; i < inputSize; ++i)
	{
		prevNum = GetGDC(prevNum, arr[i]);
		prevNum = (arr[i - 1] * arr[i])/ prevNum;
		arr[i] = prevNum;
	}
		
	return prevNum;
}

int GetGDC(int a, int b)
{
	return (0 == a%b ? b : GetGDC(b, a%b));
}

