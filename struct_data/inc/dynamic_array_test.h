#ifndef _DYNAMIC_ARRAY_TEST_H_
#define _DYNAMIC_ARRAY_TEST_H_

#include "dynamic_array.h"
#include <string>
#include <iostream>

class dynamic_array_test
{
public:
	dynamic_array_test( void );
	~dynamic_array_test( void );

	void keys1( void );
	void keys2( void );
	void keys3( void );
	void keys4( void );
	void keys5( void );
private:
	template<typename T>
	void print( const dynamic_array<T> &v, const std::string &title )const
	{
		std::cout<<title<<std::endl;
		for( unsigned int i = 0; i < v.size(); i++ )
		{
			std::cout<<"v["<<i<<"] = "<<v[i]<<std::endl;
		}
	}
private:
};
#endif //_DYNAMIC_ARRAY_TEST_H_