#include <vector>
#include <stack>

using namespace std;

typedef struct lineInfo
{
	explicit lineInfo(int init, int end)
	{
		this->init = init;
		this->end = end;
	}

	int init = 0;
	int end = 0;
}LINE;

int solution(vector<int> &A, vector<int> &B)
{
	stack<LINE> lineStack;
	size_t lineNum = A.size();
	if (0 == lineNum)
		return 0;

	LINE firstLine(A[0], B[0]);
	lineStack.emplace(firstLine);

	for (size_t i = 1; i < lineNum; ++i)
	{
		
		LINE TopLine = lineStack.top();
		LINE curLine(A[i], B[i]);

		// 현재 라인이 밖에 있는 경우
		if (TopLine.end < curLine.init)
		{
			lineStack.emplace(curLine);
		}
	}

	return lineStack.size();
}