#include <string>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(char* s);

void main()
{
	cout << solution("abacde")<< endl;
}

bool IsPalindrom(string& s, bool bEven, size_t init, size_t num);

int solution(string s) {
	
	size_t len = s.length();

	if (0 == len)
		return 0;

	for (size_t i = 0; i < len; ++i)
	{
		bool bEven = 0 == (len - i) % 2;
		for (size_t j = 0; j <= i; ++j)
		{
			if (IsPalindrom(s, bEven, j, len-i))
				return len - i;
		}
	}

	return 1;
}

bool IsPalindrom(string & sub, bool bEven, size_t init, size_t num)
{
	size_t subLen = num /2;
	bool bPalin = false;

	for (size_t k = 1; k <= subLen; ++k)
	{
		if (bEven)
		{
			if (true == (sub[init+subLen - k] == sub[init + subLen + k - 1]))
				bPalin = true;
			else
				return false;	
		}
		else
		{
			if (true == (sub[init + subLen - k] == sub[init + subLen + k]))
				bPalin = true;
			else
				return false;
		}
	}

	return bPalin;
}

//bool IsPalindrom(string & sub)
//{
//	size_t size = sub.length();
//	size_t halfSize = size / 2;
//	string counter = sub.substr(0, halfSize);
//
//	for (size_t i = 0; i<halfSize; ++i)
//		counter[i] = sub[size - i-1];
//
//	string half = sub.substr(0, halfSize);
//	if (0 == counter.compare(half))
//		return true;
//	else
//		return false;
//}