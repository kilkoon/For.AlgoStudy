#include <string>
#include <string.h>
#include <tchar.h>
#include <iostream>
#include <Windows.h>

using namespace std;

void main()
{
	TCHAR pTmp[4] = L"asd";

	lstrcpy(pTmp, L"bc"); //����, pTmp�� rdata ������ ���ڿ� �ּ�(literal ���)�� ���� �ֱ� ������ ���⸦ �õ��ϸ� ������ ����.

	wcout << pTmp << endl;

}