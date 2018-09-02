#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

string makeString(vector<string>& vecStr, int openCnt, int closeCnt, int pairNum);

vector<string> solution(int N)
{
	vector<string> answer = {};

	//stack<char> check;

	makeString(answer, N, N);

	return answer;
}

string makeString(vector<string>& vecStr, int openCnt, int closeCnt, int pairNum)
{
	if (0 == vecStr.size() 
		|| pairNum * 2 == (--vecStr.end())->length())
	{
		string str = "";
		vecStr.emplace_back(str);
	}
	
	if (0 != openCnt)
	{
		if (openCnt == closeCnt)
		{
			// 무조건 ( 먼저 넣기
			string& curStr = *(--vecStr.end());

			curStr.append(")");
			--openCnt;

			return makeString(vecStr, openCnt, closeCnt, pairNum);
		}
		else if (openCnt < closeCnt)
		{
			// ( 먼저 넣기
			string& curStr = *(--vecStr.end());

			curStr.append("(");
			--openCnt;
		
			string result1 = makeString(vecStr, openCnt, closeCnt, pairNum);
		

			// ) 먼저 넣기
			string& curStr = *(--vecStr.end());

			curStr.append(")");
			--closeCnt;

			string result2 = makeString(vecStr, openCnt, closeCnt, pairNum);

		}
	}




	return string();
}
