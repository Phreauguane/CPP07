#pragma once

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREEN_BG_BLACK_FG  "\033[42;30m"

#include <stdexcept>
#include <iostream>
#include <typeinfo>

template<typename T>
class Array {
public:
    Array();
    Array(unsigned int);
    Array(const Array&);
    ~Array();

    unsigned int size(void) const;
    Array &operator=(const Array&);
    
    T &operator[](unsigned int);
    const T &operator[](unsigned int) const;

    class OutOfBoundsException: public std::exception {
        const char *what(void) const throw();
    };
private:
    unsigned int _size;
    T *_array;
};

template<typename T>
Array<T>::Array(): _size(0), _array(NULL) {}

template<typename T>
Array<T>::Array(unsigned int n): _size(n), _array(new T[n]()) {}

template<typename T>
Array<T>::Array(const Array<T> &src): _size(src._size), _array(new T[src._size]())  {
    for (unsigned int i = 0; i < _size; ++i) {
        _array[i] = src._array[i];
    }
}

template<typename T>
Array<T>::~Array() {
    std::cout << YELLOW"Destructor called"RESET << std::endl;
    if (_array)
        delete[] _array;
}

template<typename T>
unsigned int Array<T>::size(void) const {
    return _size;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &src) {
    if (this == &src)
        return *this;
    _size = src._size;
    if (_array)
        delete[] _array;
    _array = new T[_size]();
    for (unsigned int i = 0; i < _size; ++i) {
        _array[i] = src._array[i];
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= _size)
        throw OutOfBoundsException();
    return _array[i];
}

template<typename T>
const T &Array<T>::operator[](unsigned int i) const {
    if (i >= _size)
        throw OutOfBoundsException();
    return _array[i];
}

template<typename T>
const char * Array<T>::OutOfBoundsException::what(void) const throw() {
    return "array index out of bounds";
}

template<typename T>
std::ostream &operator<<(std::ostream &o, Array<T> &a) {
    o << BLUE"| -- Array object -- "RESET << std::endl <<
         BLUE"| "MAGENTA"type: "CYAN << typeid(T).name() + (std::isdigit(*(typeid(T).name())) ? 1 : 0) << RESET << std::endl <<
         BLUE"| "MAGENTA"size: "CYAN << a.size() << RESET << std::endl <<
         BLUE"|------------"RESET << std::endl <<
         BLUE"| "MAGENTA"elements :"RESET << std::endl <<
         BLUE"| ["CYAN;
    for (unsigned int i = 0; i < a.size(); ++i) {
        o << a[i];
        if (i + 1 < a.size())
            o << BLUE", "CYAN;
    }

    o << BLUE"]"RESET << std::endl <<
         BLUE"|--------------------"RESET << std::endl << std::endl; 
    return o;
}