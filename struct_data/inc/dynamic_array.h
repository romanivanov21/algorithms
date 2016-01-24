#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

template <typename T>
class dynamic_array
{
public:
	dynamic_array( void );
	dynamic_array( unsigned int real_size );

	//конструктор копирования
	// dynamic_array v(100);
	// dynamic_array v_copy( v );
	dynamic_array( const dynamic_array &copy );
	//оператор присваивания
	// dynamic_array v(100);
	// dynamic_array v_copy;
	// v_copy = v;
	dynamic_array<T>& operator=( const dynamic_array<T> &copy );

	//деструктор
	~dynamic_array( );


	//реальный размер массива
	const unsigned int size( void ) const;
	//выделенный объём для эементов
	const unsigned int copacity( void ) const;
	void resize( unsigned int real_size );
	void reserve( unsigned int buffer_size );

	void insert( unsigned int i, T value );
	void erase( unsigned int i );

	//Доступ по индексу
	T  at( unsigned int i ) const;
	T  operator[]( unsigned int i ) const;
	T* operator&( unsigned int i )const;

	void push_back( T value );
	void pop_back( void );
	void clear( void );

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