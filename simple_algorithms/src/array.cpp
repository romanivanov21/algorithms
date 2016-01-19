#include "array.h"
#include <assert.h>

int find_item( const int *array, unsigned int size, int item )
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

int find_max( const int *array, unsigned int size )
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