
#pragma once
#include <stdexcept> // For std::out_of_range

template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;

public:
    // Default constructor: creates empty array
    Array() : _data(NULL), _size(0) {}

    // Constructor with size parameter
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // Copy constructor (deep copy)
    Array(const Array& other) : _data(new T[other._size]), _size(other._size)
    {
        for (unsigned int i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }

    // Assignment operator (deep copy)
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
        return *this;
    }

    // Destructor
    ~Array()
    {
        delete[] _data;
    }

    // Access operator with bounds check
	/*The access operator refers to the subscript operator operator[], 
	which lets you access elements of your class like an array*/
    T& operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return _data[index];
    }

    // Const version of access operator
    const T& operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return _data[index];
    }

    // Size getter
    unsigned int size() const
    {
        return _size;
    }
};
