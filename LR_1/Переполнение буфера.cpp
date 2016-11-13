#include <stdio.h> //заголовочный файл с описанием функций для ввода/вывода
#include <conio.h>

// aa4ab В kernek32 exitprocess


void _stdcall show_array(int arrlen, char array[])
{
	char buffer[32];
	int i;

	for (i = 0; i < arrlen; i++) buffer[i] = array[i];
	printf(buffer);
}

int main() //точка входа в программу
{
	// '9' == 0x39 (т.е. символ 9 записывается в 16-ричной системе счисления как 0x39)
	//printf("%X\n", &show_array); //печатаем адрес функции show_array
	//char mystr[] = "1111122222333334444455";
	char mystr[] = "1111122222333334444455555666667777788888999990";

	//char mystr[] = "1111122222333334444455555666667777788888\xB0\x79\x1B\x76";
	/*char mystr[] = "1111122222333334444455555666667777788888"
		"\xC8\x65\xD2\x76"
		"\xCC\xCC\xCC\xCC"
		"\xCC\xCC\xCC\xCC"
		"\xCC\xCC\xCC\xCC"
		"\xCC\xCC\xCC\xCC"
		"\xCC\xCC\xCC\xCC"
		"\xB0\x79\x1B\x76";*/
	show_array(47, mystr);
	_getch();
	return 0;
}