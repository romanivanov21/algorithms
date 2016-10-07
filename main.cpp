#include "dynamic_array.h"

#include <iostream>

int main()
{
    dynamic_array<int> v(10);
    for( int i = 0; i < 10; i++ )
    {
        v.push_back( 5 );
    }
    for( int i = 0; i < 10; i++ )
    {
        std::cout<<v[i]<<" ";
    }
    return 0;
}