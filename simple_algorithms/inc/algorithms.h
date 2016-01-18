#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

/***************************************************************************
* @berif Поиск чисел Фибоначчи O(n)
* 		 F(0) = 0
* 		 F(1) = 1
* 		 F(i) = F(i - 1) + F(i - 2)
* @param i - номер элемента
* @return соответсувующее, заданному номеру число Фибоначчи
****************************************************************************/
int fibonacci_numbers( unsigned int i );

/***************************************************************************
* @berif Проверка чисел на простоту
* @parem n - натуральное число, которое следует проверить
* @return true  - n является простым
*		  false - n не является простым
****************************************************************************/
bool is_number_prime( int n );


#endif //ALGORITHMS_H_