#include <string>
#include <string.h>
#include <tchar.h>
#include <iostream>
#include <Windows.h>

using namespace std;

void main()
{
	TCHAR pTmp[4] = L"asd";

	lstrcpy(pTmp, L"bc"); //에러, pTmp가 rdata 영역의 문자열 주소(literal 상수)를 갖고 있기 때문에 쓰기를 시도하면 에러가 난다.

	wcout << pTmp << endl;

}