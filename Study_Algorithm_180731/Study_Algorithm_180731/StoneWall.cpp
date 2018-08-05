#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<int> &H);

void main()
{

}

int solution(vector<int> &H) 
{
	stack<int> parts;
	stack<int> compare;

	for (int height : H)
	{
		if (true == parts.empty())
		{
			parts.push(height);
			compare.push(height);
			continue;
		}

		// 이전의 높이와 같은 경우
		if (parts.top() == height)
		{
			continue;
		} // 이전의 높이보다 큰 경우
		else if (parts.top() < height)
		{
			compare.push(height);
			parts.push(height);
			continue;
		} // 이전의 높이보다 낮은 경우
		else if (parts.top() > height)
		{
			compare.pop();
			while (1)
			{
				if (true == compare.empty())
				{
					parts.push(height);
					compare.push(height);
					break;
				}

				if (compare.top() > height)
				{
					compare.pop();
					//continue;
				}
				else if (compare.top() == height)
				{
					break;
				}
				else if (compare.top() < height)
				{
					parts.push(height);
					compare.push(height);
					break;
				}
			}
		}
	}

	return parts.size();
}


//int solution(vector<int> &H) {
//	
//	stack<int> parts;
//	vector<int> lowPoints;
//
//	for (int num : H)
//	{
//		if (true == parts.empty())
//		{
//			parts.push(num);
//			lowPoints.emplace_back(num);
//			continue;
//		}
//
//		if (parts.top() == num)
//			continue;
//
//		if (parts.top() < num)
//		{
//			parts.push(num);
//			lowPoints.emplace_back(num);
//			continue;
//		}
//		
//		if (parts.top() > num)
//		{
//			bool bSame = false;
//			for (int low : lowPoints)
//			{
//				if (low == num)
//				{
//					bSame = true;
//					break;
//				}
//			}
//
//			if (bSame)
//			{
//
//				continue;
//			}
//			
//			vector<int>::iterator iterBegin = lowPoints.begin();
//			vector<int>::iterator iterEnd = lowPoints.end();
//
//			for (; iterBegin != iterEnd; ++iterBegin)
//			{
//				if ((*iterBegin) > num)
//				{
//					iterBegin = lowPoints.erase(iterBegin);
//					iterEnd = lowPoints.end();
//				}
//				else
//					++iterBegin;
//			}
//			lowPoints.emplace_back(num);
//			parts.push(num);
//		}
//	}
//
//	return parts.size();
//}