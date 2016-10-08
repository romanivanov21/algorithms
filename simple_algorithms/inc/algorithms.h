#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include <stdlib.h>
#include <vector>

/**
 * @berif Поиск чисел Фибоначчи O(n)
 * 		 F(0) = 0
 * 		 F(1) = 1
 * 		 F(i) = F(i - 1) + F(i - 2)
 * @param i - номер элемента
 * @return соответсувующее, заданному номеру число Фибоначчи
 */
int fibonacci_numbers( size_t i );

/**
 * @berif Проверка чисел на простоту
 *        Время работы алгоритма: T = O(sqrt(n))
 *        Объём дополнительной памяти: M = O(1)
 *
 * @parem n - натуральное число, которое следует проверить
 *
 * @return true  - n является простым
 *		   false - n не является простым
 */
bool is_number_prime( int n );


/**
 * @berif Быстрое возведение в степень
 *
 * @param a - основание, n - степень
 *        Время работы алгоритма: T = O(log n)
 *        Объём дополнительной памяти: M = O(1)
 * @return  a^n
 */
double power( double a, int n );

/**
 * @brief Переворот строки, не продя всю строку
 *
 * @param str указатель на строку
 * @param len длина строки без '\0'
 */
void str_invert( char* str, size_t len );

/**
 * @brief Является ли число степенью 2
 *
 * @param проверяемое число
 *
 * @return true если число явялется стпенью 2
 *         false иначе
 */
bool is_binary_pow( int n );

size_t units_count( int n );

size_t zero_count( int n );

/**
 *  @brief разложение числа на простые множители
 *
 *  @param входное чило
 *
 *  @return вектор с множителями
 */
std::vector<int> prime_factors( int n );

int greatest_common_division( int a, int b );

#endif //ALGORITHMS_H_