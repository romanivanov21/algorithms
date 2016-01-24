#ifndef _DYNAMIC_ARRAY_IML_H_
#define _DYNAMIC_ARRAY_IML_H_

#include <string.h>
#include <assert.h>

template <typename T>
dynamic_array<T>::dynamic_array( void ) : buffer_( 0 ), buffer_size_( 0 ), real_size_( 0 ), initial_size_( 10 ) {  }

template <typename T>
dynamic_array<T>::dynamic_array( unsigned int real_size )
{
	assert( real_size > 0 );
	real_size_ = real_size;
	initial_size_ = 10;
	buffer_size_ = real_size_ + initial_size_;
	buffer_ = new T[buffer_size_];
}

template <typename T>
dynamic_array<T>::dynamic_array( const dynamic_array &copy)
{
	buffer_size_ = copy->buffer_size_;
	real_size_ = copy->real_size_;
	initial_size_ = copy->initial_size_;
	buffer_ = new T[buffer_size_];
}

template <typename T>
dynamic_array<T>& dynamic_array<T>::operator=( const dynamic_array<T> &copy )
{
	if( this != &(copy) )
	{
		T *new_buffer = new T[copy->buffer_size_];
		buffer_size_ = copy->buffer_size_;
		real_size_ = copy->real_size_;
		initial_size_ = copy->initial_size_;
		memcpy( new_buffer, copy->buffer_, copy->real_size_ * sizeof( unsigned int ));
		delete [] buffer_;
		buffer_ = new_buffer;
	}
	return *this;
}

template <typename T>
dynamic_array<T>::~dynamic_array( )
{
	if( buffer_ )
	{
		delete [] buffer_;
	}
}

template <typename T>
const unsigned int dynamic_array<T>::size( void )const {  return real_size_; }

template <typename T>
const unsigned int dynamic_array<T>::copacity( void ) const { return buffer_size_; }

template <typename T>
void dynamic_array<T>::resize( unsigned int real_size )
{
	if( real_size > buffer_size_ )
	{
		unsigned int new_buffer_size = real_size + initial_size_;
		T *new_buffer = new T[new_buffer_size];
		memcpy( new_buffer, buffer_, real_size_ * sizeof(real_size_));
		delete [] buffer_;
		buffer_ = new_buffer;
		buffer_size_ = new_buffer_size;
	}
	real_size_ = real_size;
}

template <typename T>
void dynamic_array<T>::reserve( unsigned int buffer_size ) 
{
	if( ( buffer_size > buffer_size_ ) && ( buffer_size_ > real_size_ ) )
	{
		unsigned int new_buffer_size = buffer_size;
		T *new_buffer = new T[new_buffer_size];
		memcpy( new_buffer, buffer_, real_size_ * sizeof(real_size_));
		delete [] buffer_;
		buffer_ = new_buffer;
		buffer_size_ = new_buffer_size;
	}
}

template <typename T>
void dynamic_array<T>::insert( unsigned int i, T value)
{
	assert( i > 0 && i < real_size_ );
	if( real_size_ < buffer_size_)
	{
		memcpy( &buffer_[i], &buffer_[i + 1], (real_size_ - i) * sizeof(T) );
	}
	else
	{
		grow();
		assert( real_size_ < buffer_size_ );
	}
	buffer_[i] = value;
	real_size_++;
}

template <typename T>
void dynamic_array<T>::erase( unsigned int i )
{
	assert( i > 0 && i < real_size_ );
	memcpy( &buffer_[i + 1], &buffer_[i], (real_size_-i -1)) ;
	real_size_--;
}

template <typename T>
T dynamic_array<T>::at( unsigned int i )const
{
	assert( ( i >= 0 ) && ( i < real_size_ ) && (buffer_ != 0) );
	return buffer_[i];
}

template <typename T>
T* dynamic_array<T>::operator&( unsigned int i ) const
{
	assert( ( i >= 0 ) && ( i < real_size_ ) && ( buffer_ != 0 ) );
	return &buffer_[i];
}

template <typename T>
T dynamic_array<T>::operator[]( unsigned int i ) const
{
	assert( ( i >= 0 ) && ( i < real_size_ ) && ( buffer_ != 0 ) );
	if( i < real_size_)
	{
		return buffer_[i];
	}
}

template <typename T>
void dynamic_array<T>::push_back( T value )
{
	if( real_size_ == buffer_size_ )
	{
		grow();
	}
	assert( real_size_ < buffer_size_ );
	buffer_[real_size_] = value;
	real_size_++;
}

template <typename T>
void dynamic_array<T>::pop_back( void )
{
	buffer_[real_size_] = 0x00;
	real_size_ --;
}

template <typename T>
void dynamic_array<T>::clear( void )
{
	memset( buffer_, 0x00, real_size_ );
	real_size_ = 0;
}

template <typename T>
void dynamic_array<T>::grow( void )
{
	unsigned int new_buffer_size = 0;
	if( ( buffer_size_ * 2 ) > initial_size_ )
	{
		new_buffer_size = buffer_size_ * 2;
	}
	else
	{
		new_buffer_size = initial_size_;
	}
	T *new_buffer = new T[new_buffer_size];
	memcpy( new_buffer, buffer_, real_size_ * sizeof( unsigned int ) );
	delete buffer_;
	buffer_ = new_buffer;
	buffer_size_ = new_buffer_size;
}

#endif //_DYNAMIC_ARRAY_IML_H_