#include <iostream>
#include <vector>

#include "dynamic_array.h"

int main( void )
{
	dynamic_array<int> v(1);
	v[0] = 5;
	std::cout<<"v[0] = "<<v[0]<<std::endl;
	for( unsigned int i = 50; i > 0; i-- )
	{
		v.push_back( i );
	}
	for( unsigned int i = 0; i < 25; i++ )
	{
		std::cout<<"v.at("<<i; std::cout<<") = "<<v.at(i)<<std::endl;
	}
	for( unsigned int i = 25; i < 50; i++ )
	{
		std::cout<<"v["<<i; std::cout<<"] = "<<v[i]<<std::endl;
	}
	return 0;
}
