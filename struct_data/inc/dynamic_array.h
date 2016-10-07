#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

template <typename T>
class dynamic_array
{
public:
	dynamic_array();
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
	T&  operator[]( unsigned int i ) const;
	dynamic_array<T>* operator&();
	dynamic_array<T>  operator*();

	void push_back( T value );
	void pop_back();
	void clear();

private:
	void grow( void );
private:
	const unsigned int initial_size_ = 10; // размер амортизированности массива
	unsigned int real_size_;               // количество элементов в массиве
	unsigned int buffer_size_;             // размер буффера
	T *buffer_;                            //буффер
	T *current_item_;
};

#include "dynamic_array_impl.h"

#endif //_DYNAMIC_ARRAY_H_