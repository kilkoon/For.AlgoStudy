#include <string>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(char* s);

void main()
{
	cout << solution("abacde")<< endl;
}



int solution(string s) {
	
	size_t len = s.length();
	string str = s;

	for (size_t i = 0; i < len; ++i)
	{
		bool bEven = 0 == (len - i) % 2;
		for (size_t j = 0; j <= i; ++j)
		{
			string sub = str.substr(j, len-i);
			size_t subLen = sub.length();
			bool bPelin = false;

			for (size_t k = 1; k <= subLen / 2; ++k)
			{
				if (bEven)
				{
					if (true == (sub[subLen / 2 - k] == sub[subLen / 2 + k - 1]))
						bPelin = true;
					else
						break;
				}
				else
				{
					if (true == (sub[subLen / 2 - k] == sub[subLen / 2 + k]))
						bPelin = true;
					else
						break;
				}
			}
			if (bPelin)
				return subLen;
		}
	}

	return 1;
}