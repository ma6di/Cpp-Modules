
#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack<T>& other);
    ~MutantStack();

    MutantStack<T>& operator=(const MutantStack<T>& other);

	/*std::stack is built on top of another container (usually std::deque).
	We access that underlying container’s iterator type and alias it as iterator.*/
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

#include "MutantStack.tpp" // Include implementation
