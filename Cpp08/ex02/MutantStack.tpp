
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

// copy constructor
/*
 Why the : std::stack<T>(other)?
That’s the member initializer list. It tells C++:
“Use the std::stack copy constructor to initialize the base class part of this object.”
Since MutantStack inherits from std::stack, the base class (std::stack<T>) needs to be 
constructed as well — and this is how you do that cleanly.*/
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
    std::stack<T>::operator=(other);
    return *this;
}

/*this->c: std::stack has a protected member c, which holds the actual container (like deque or vector).
You call begin() and end() on it to access iterators.*/
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
    return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
    return this->c.rend();
}
