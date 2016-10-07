#include "sorting.h"

#include <cassert>
#include <algorithm>

void selection_sort( int* a, size_t n )
{
    assert( a );
    assert( n > 0 );
    //цикл от 1 элемента массива до предпосследнего
    for( size_t i = 0; i < n - 1; i++ )
    {
        size_t min_index = i;
        for( size_t j = i + 1; j < n; j++ )
        {
            if( a[j] < a[min_index] )
            {
                min_index = j;
            }
        }
        std::swap( a[i], a[min_index] );
    }
}