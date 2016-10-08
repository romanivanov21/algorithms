#include "algorithms.h"

#include <string>


int fibonacci_numbers( size_t i )
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
	for( size_t i = 2; i * i <= n; i++ )
	{
		if( n % i == 0 )
		{
			return false;
		}
	}
	return true;
}

double power( double a, int n )
{
	double res = 1;
	double current_value = a; // a^1
	while( n > 0 )
	{
		if( n & 1 == 1 )
		{
			res = current_value * res; // a^1 * 1; 
		}
		current_value = current_value * current_value;
		n = n >> 1;
	}
	return res;
}

void str_invert( char* str, size_t len )
{
	for( size_t i = 0; i < ( size_t ) len/2; i++ )
	{
		std::swap( str[i], str[len - i - 1] );
	}
}

bool is_binary_pow( int n )
{
	return ( ( n ) && ( ( n & ( n - 1 ) ) == 0 ) );
}

size_t units_count( int n )
{
	return 0;
}

size_t zero_count( int n )
{
	return 0;
}

std::vector<int> prime_factors( int n )
{
	std::vector<int> res( 0 );
	if( n == 1 )
	{
		res.push_back( 1 );
		return res;
	}
	for( int i = 2;  i <= n; )
	{
		if( n % i == 0 )
		{
			res.push_back( i );
			n = n / i;
			i = 2;
		}
		else
		{
			i++;
		}
	}
	return res;
}

int greatest_common_division( int a, int b )
{
	int res = 0;
	return res;
}