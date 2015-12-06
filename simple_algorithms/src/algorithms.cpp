#include "algorithms.h"


int fibonacci_numbers( const unsigned int &i )
{
	//результат
	int res = -1;
	//нулевой элемент
	int item0 = 0;
	//первый элемент
	int item1 = 1;

	if( i == 0 )
	{
		return item0;
	}
	//номер текущего вычисленного элемента
	int n = 1;
	//текущее значение
	int current = 1;
	while( n != i )
	{
		current = item0 + item1;
		item0 = item1;
		item1 = current;
		n++;
	}
	res = current;
	return res;
}