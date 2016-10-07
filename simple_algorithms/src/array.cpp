#include "array.h"

#include <assert.h>

int find_item( const int *array, size_t size, int item )
{
	assert( array );
	assert( size > 0);

	for( unsigned int i = 0; i < size; i++ )
	{
		if( item == array[i] )
		{
			return i;
		}
	}
	return -1;
}

int find_max( const int *array, size_t size )
{
	assert( array );
	assert( size > 0);

	int max = array[0];
	for ( unsigned int i = 1; i < size; i++ )
	{
		if( array[i] > max )
		{
			max = array[i];
		}
	}
	return max;
}

int binary_find( const int *array, unsigned int size, int item )
{
	assert( array );
	assert( size > 0 );

	int first = 0;
	int last  = size;
	while( first < last )
	{
		int mid = ( first + last ) / 2;
		if( item <= array[mid] )
		{
			last = mid;
		}
		else
		{
			first = mid + 1;
		}
	}
	return ( first == size || array[first] != item ) ? -1 : first; 
}