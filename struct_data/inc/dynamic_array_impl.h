#include <string.h>
#include <assert.h>

template <typename T>
dynamic_array<T>::dynamic_array( void ) : buffer_( 0 ), buffer_size_( 0 ), real_size_( 0 ), initial_size_( 10 ) {  }

template <typename T>
dynamic_array<T>::~dynamic_array( )
{
	if( buffer_ )
	{
		delete [] buffer_;
	}
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
void dynamic_array<T>::set_initial_size( unsigned int initial_size )
{
	assert( initial_size > 0 );
	initial_size_ = initial_size;
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