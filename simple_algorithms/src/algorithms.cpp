#include "algorithms.h"


int fibonacci_numbers( unsigned int i )
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
	int n = item1;
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

bool is_number_prime( int n )
{
	// единица не являтеся простым числом
	if( n == 1) return false;
	//Алгоритм:
	/*
	     1. Поделить число n на другое простое число
	     2. Если остаток от деления на k не равно 0, то число явялется простым k = 1...n
	     Теорема:
	     Достаточно провериь k = 1..sqrt(n) так как,
	     n = a * b
	     a >= sqrt(n)
	     b <= sqrt(n)
	*/ 
	//проверка на простоту достаточно осуществлять до sqrt(n)
	for( int i = 2; i * i <= n; i++ )
	{
		if( n % i == 0 )
		{
			return false;
		}
	}
	return true;
}