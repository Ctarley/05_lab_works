// 1. Навязывание собственных спецификаторов
// 2. Дисбаланс спецификаторов
// 3. переполнение буфера-приемника, если нет проверки на длину строки

// Отключить SDL в Visual Studio, на gcc его нет!


#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// %s%s%s%s%s%s - Необработанное исключение
	// %X %X %X %X - вывод адресов
	char buf_in[32], buf_out[32];

	printf("введи имя:");
	gets(buf_in);

	sprintf(buf_out, "hello, %s!\n", buf_in);

	printf(buf_out);

	_getch();
	return 0;
}