#include <iostream>
#include "algorithms.h"

int main( void )
{
	for(int i = 0; i < 47; i++)
	{
		std::cout<<i<<": ";
		std::cout<<fibonacci_numbers(i)<<std::endl;
	}
	for(int i = 0; i < 47; i++)
	{
		std::cout<<i<<": ";
		if( is_number_prime(i) )
		{
			std::cout<<"простое число"<<std::endl;
		}
		else
		{
			std::cout<<"число не простое"<<std::endl;
		}
	}
	for( int i = 0; i < 5; i++ )
	{
		for(int j = 5; j != 0; j-- )
		{
			std::cout<<i<<"^"<<j<<": ";
			std::cout<<power(i,j)<<std::endl;
		}
	}
	return 0;
}
