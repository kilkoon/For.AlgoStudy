#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> &A, vector<int> &B);

void main()
{

}

int solution(vector<int>& A, vector<int>& B)
{
	stack<pair<int, int>> route;
	size_t fishSize = A.size();

	for (size_t i = 0; i < fishSize; ++i)
	{
		while (false == route.empty()
				&& 0 == B[i]
				&& 1 == route.top().second)
		{
			if (A[i] > route.top().first)
				route.pop();
			else 
				break;
		}

		if (true == route.empty()
			|| (1 == route.top().second && 1 == B[i])
			|| 0 == route.top().second)
		{
			route.push(pair<int, int>(A[i], B[i]));
		}
	}

	return route.size();
}
