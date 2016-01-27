#include "dynamic_array_test.h"

dynamic_array_test::dynamic_array_test( )
{

}
dynamic_array_test::~dynamic_array_test( )
{

}

void dynamic_array_test::keys1( )
{
	dynamic_array<int> v(10);
	print( v, "keys1" );
}

void dynamic_array_test::keys2( )
{
	dynamic_array<int> v;
	std::cout<<v.size()<<std::endl;
	v.resize( 5 );
	print( v, "keys2" );
}

void dynamic_array_test::keys3()
{
	dynamic_array<int> v;
	for( unsigned int i = 0; i < 10; i++ )
	{
		v.push_back(i);
	}
	print( v, "keys3");
	for ( unsigned int i = 0; i <5; i++ )
	{
		v.pop_back();
	}
	v.erase(0);
	print(v, "keys3:pop_back");
}

void dynamic_array_test::keys4()
{
	dynamic_array<int> v(1);
	v[0] = 5;
	print( v, "keys4" );
}
