#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<int> &H);

void main()
{

}

int solution(vector<int> &H) {
	
	stack<int> parts;
	vector<int> lowPoints;

	for (int num : H)
	{
		if (true == parts.empty())
		{
			parts.push(num);
			continue;
		}

		if (parts.top() == num)
			continue;

		if (parts.top() < num)
		{
			parts.push(num);
			lowPoints.emplace_back(num);
			continue;
		}
		else if (parts.top() > num)
		{
			bool bSame = false;
			for (int low : lowPoints)
			{
				if (low == num)
				{
					bSame = true;
					break;
				}
			}

			if (bSame)
				continue;
			
			vector<int>::iterator iterBegin = lowPoints.begin();
			vector<int>::iterator iterEnd = lowPoints.end();

			for (; iterBegin != iterEnd; ++iterBegin)
			{
				if ((*iterBegin) > num)
				{
					iterBegin = lowPoints.erase(iterBegin);
					iterEnd = lowPoints.end();
				}
				else
					++iterBegin;
			}
			lowPoints.emplace_back(num);
			parts.push(num);
		}
	}

	return parts.size();
}