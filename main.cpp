#include "algorithms.h"
#include "dynamic_array.h"

#include <iostream>

int main()
{
    std::string str = "build";
    str_invert( &str[0], str.size() );
    std::cout<<str<<std::endl;
    if( is_binary_pow( 8 ) )
    {
        std::cout<<"power of 2"<<std::endl;
    }
    std::vector<int> vprime = prime_factors( 2 );
    for( auto i : vprime )
    {
        std::cout<<i<<std::endl;
    }
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