#include <iostream>

#include "dynamic_array_test.h"
#include "dynamic_array.h"

int main( void )
{
	/*dynamic_array<int> v(1);
	v[0] = 5;
	std::cout<<"v[0] = "<<v[0]<<std::endl;
	for( unsigned int i = v.size(); i > 0; i-- )
	{
		v.push_back( i );
	}
	for( unsigned int i = 0; i < 25; i++ )
	{
		std::cout<<"v.at("<<i; std::cout<<") = "<<v.at(i)<<std::endl;
	}
	for( unsigned int i = 25; i < v.size(); i++ )
	{
		std::cout<<"v["<<i; std::cout<<"] = "<<v[i]<<std::endl;
	}*/
	dynamic_array_test t;
	t.keys1();
	t.keys2();
	t.keys3();
	t.keys4();
	return 0;
}
