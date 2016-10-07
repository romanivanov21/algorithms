#ifndef _SORTING_H_
#define _SORTING_H_

#include <stddef.h>

/**
 *  @brief сортировка выбором, сложность O(n^2)
 *         ( n - 1)/n сравнений, n - 1 перемещений
 */
void selection_sort( int* a, size_t n );

#endif //_SORTING_H_