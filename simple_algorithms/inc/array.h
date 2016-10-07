#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stddef.h>

/**
 * @berif Поиск в массиве. Линейный поиск O(n)
 * 		 Время работы алгоритма: T = O(n)
 *        Количество выделенной памяти: M = O(1)
 *
 * @param array - указатель на массив
 *        size  - размер массива
 *        item   - искомый элемент
 *
 * @return индекс найденного элемента
 */
int find_item( const int *array, size_t size, int item );

/**
 * @berif Поиск в массиве. Поиск максимума за O(n)
 * 		  Время работы алгоритма: T = O(n)
 *        Количество выделенной памяти: M = O(1)
 *
 * @param array - указатель на массив
 *        size  - размер массива
 *
 * @return индекс минимального элемента
 */
int find_max( const int *array, size_t size );

/**
 * @berif Поиск в упорядочненном массиве. Бинарный поиск эдемента за O(log n)
 * 		  Время работы алгоритма: T = O(log n)
 *        Количество выделенной памяти: M = O(1)
 *
 * @param array - указатель на массив
 *        size  - размер массива
 *		  item  - искомый элемент
 *
 * @return индекс найденного элемента
 */
int find_binary( const int *array,unsigned int size, int item );

#endif //_ARRAY_H_