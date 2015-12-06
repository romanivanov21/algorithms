#include <iostream>
#include "algorithms.h"

int main( void )
{
	for(int i = 0; i < 47; i++)
	{
		std::cout<<i<<": ";
		std::cout<<fibonacci_numbers(i)<<std::endl;
	}
	return 0;
}
