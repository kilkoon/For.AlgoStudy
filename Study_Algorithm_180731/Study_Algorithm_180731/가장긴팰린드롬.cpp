#include <string>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(char* s);

void main()
{
	cout << solution("abacde")<< endl;
}

bool IsPalindrom(string& s);

int solution(string s) {
	
	size_t len = s.length();
	string str = s;

	if (0 == len)
		return 0;

	for (size_t i = 0; i < len; ++i)
	{
		for (size_t j = 0; j <= i; ++j)
		{
			string sub = str.substr(j, len-i);

			if (IsPalindrom(sub))
				return sub.length();
		}
	}

	return 1;
}

bool IsPalindrom(string & sub, bool bEven)
{
	size_t subLen = sub.length()/2;
	bool bPelin = false;

	for (size_t k = subLen; k >= 1; --k)
	{
		if (bEven)
		{
			if (true == (sub[subLen - k] == sub[subLen + k - 1]))
				bPelin = true;
			else
			{
				return false;
			}		
		}
		else
		{
			if (true == (sub[subLen - k] == sub[subLen + k]))
				bPelin = true;
			else
			{
				return false;
			}
		}
	}

	return bPelin;
}

bool IsPalindrom(string & sub)
{
	size_t size = sub.length();
	size_t halfSize = size / 2;
	string counter = sub.substr(0, halfSize);

	for (size_t i = 0; i<halfSize; ++i)
		counter[i] = sub[size - i-1];

	string half = sub.substr(0, halfSize);
	if (0 == counter.compare(half))
		return true;
	else
		return false;
}