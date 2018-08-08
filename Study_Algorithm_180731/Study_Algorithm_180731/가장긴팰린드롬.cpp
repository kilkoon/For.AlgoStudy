#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

int GetPalindrome(int& maxLen, char* s);
int solution(char* s) {
	int answer = 0;


	return answer;
}

int GetPalindrome(int & maxLen, char * s)
{
	size_t len = strlen(s);
	
	if (len % 2 == 0)
	{
		for (size_t i = 1; i <= len / 2; ++i)
		{
			if (s[len / 2 - i] == s[len / 2 + i-1])
				return max(int(len), maxLen);
		}
	}
	else
	{
		for (size_t i = 1; i <= len / 2; ++i)
		{
			if (s[len / 2 - i] == s[len / 2 + i])
				return max(int(len), maxLen);
		}
	}

	if (1 == len)
		return 1;
	else
		return GetPalindrome(maxLen, );
}
