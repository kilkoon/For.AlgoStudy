#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	
	bool bEnd = true;

	for (char& c : s)
	{
		if (' ' == c)
		{
			bEnd = true;
			continue;
		}

		if (true == bEnd)
		{
			bEnd = false;
			if(c >= 'a')
				c -= ('a' - 'A');
		}
		else if (false == bEnd)
		{
			if (c <= 'Z')
				c += ('a' - 'A');
		}
	}

	return s;
}