#include <string>
#include <vector>

using namespace std;

int solution(int n);
int Get_NumberOne(int input);

void main()
{


}

int solution(int n) {
	
	int answer = n;
	int oneCount = 0;

	oneCount = Get_NumberOne(n);
	
	while (1)
	{
		++answer;

		if (oneCount == Get_NumberOne(answer))
			return answer;
	}

	return 0;
}

int Get_NumberOne(int input)
{
	int quotient = input;
	int count = 0;

	do
	{
		int remainder = quotient % 2;
		if (1 == remainder)
			++count;
		quotient /= 2;

		if (1 == quotient)
			++count;
	} while (1 != quotient);

	return count;
}


/**
* Counts number of 1 bits in a 32 bit unsigned number.
*
* @param x unsigned 32 bit number whose bits you wish to count.
*
* @return number of 1 bits in x.
* @author Roedy Green email
*/
//static int countBits(int x) {
//	// collapsing partial parallel sums method
//	// collapse 32x1 bit counts to 16x2 bit counts, mask 01010101
//	x = (x >> 1 & 0x55555555) + (x & 0x55555555);
//	// collapse 16x2 bit counts to 8x4 bit counts, mask 00110011
//	x = (x >> 2 & 0x33333333) + (x & 0x33333333);
//	// collapse 8x4 bit counts to 4x8 bit counts, mask 00001111
//	x = (x >> 4 & 0x0f0f0f0f) + (x & 0x0f0f0f0f);
//	// collapse 4x8 bit counts to 2x16 bit counts
//	x = (x >> 8 & 0x00ff00ff) + (x & 0x00ff00ff);
//	// collapse 2x16 bit counts to 1x32 bit count
//	return(x >> 16) + (x & 0x0000ffff);
//}