// 1. ����������� ����������� ��������������
// 2. ��������� ��������������
// 3. ������������ ������-���������, ���� ��� �������� �� ����� ������

// ��������� SDL � Visual Studio, �� gcc ��� ���!


#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// %s%s%s%s%s%s - �������������� ����������
	// %X %X %X %X - ����� �������
	char buf_in[32], buf_out[32];

	printf("����� ���:");
	gets(buf_in);

	sprintf(buf_out, "hello, %s!\n", buf_in);

	printf(buf_out);

	_getch();
	return 0;
}