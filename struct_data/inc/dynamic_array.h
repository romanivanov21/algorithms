#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

template <typename T>
class dynamic_array
{
public:
	dynamic_array( void );
	~dynamic_array( );

	//Доступ по индексу
	T  at( unsigned int i ) const;
	T  operator[]( unsigned int i ) const;
	T* operator&( unsigned int i )const;

	void set_initial_size( unsigned int initial_size );

	void push_back( T value );

private:
	void grow( void );
private:
	T *buffer_;               //буффер
	unsigned int buffer_size_;//размер буффера
	unsigned int real_size_;  //количество элементов в массиве
	unsigned int initial_size_; //размер амортизированности массива
};

#include "dynamic_array_impl.h"

#endif //_DYNAMIC_ARRAY_H_