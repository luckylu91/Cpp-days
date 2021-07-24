#pragma once
#include <cstring>
#include <exception>

template <class T>
class Array
{
private:
	T *				_array;
	unsigned int	_size;

	void _copy(Array<T> const & other)
	{
		if (_size == 0)
			_array = NULL;
		else
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
			{
				_array[i] = other._array[i];
			}
		}
	}

public:
	Array() : _array(NULL), _size(0) {}

	Array(unsigned int n) : _size(n)
	{
		this->_array = new T[n];
	}

	Array(Array<T> const & other) : _size(other._size)
	{
		_copy(other);
	}

	Array<T> & operator=(Array<T> & other)
	{
		if (_size > 0)
			delete [] _array;
		_size = other._size;
		_copy(other);
		return *this;
	}

	~Array()
	{
		if (this->_array)
			delete [] this->_array;
	}

	T & operator[](unsigned int i)
	{
		if (i >= _size)
			throw std::exception();
		return _array[i];
	}

	unsigned int size(void) const
	{
		return _size;
	}
};
