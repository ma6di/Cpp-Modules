/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:08:04 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/22 14:08:28 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This declares a function template, which means easyfind can work with any container type — 
like std::vector, std::list, std::deque, etc. — as long as it supports:
	begin()
	end()
	Iteration
	== comparison with an int*/


//T::iterator means: use the iterator type defined inside the container T.
/*But why typename?
Because T is a template, and T::iterator is a dependent type (i.e., it depends on T). 
C++ needs to be told explicitly that this is a type, not a static variable or 
something else. So we prefix it with typename.
If T is std::vector<int>, then T::iterator becomes std::vector<int>::iterator.
If T is std::list<int>, then T::iterator becomes std::list<int>::iterator.

std::find(container.begin(), container.end(), p);
std::find is an STL algorithm (from <algorithm>) that searches for p in the range [begin, end).
Returns an iterator pointing to the first match.
If p is not found, it returns container.end().
So it will now either point to the element or to .end() (not found).

if (it != container.end())
Check if the element was found.
If it == container.end(), it means std::find didn’t find p.

return std::distance(container.begin(), it);
If found, calculate the index (zero-based) of it by subtracting begin() from it.
std::distance is a standard utility that tells how many steps between two iterators.*/

#include <iterator>

template <typename T>
int easyfind(T& container, int p)
{
    typename T::iterator it = std::find(container.begin(), container.end(), p);
    if (it != container.end())
        return std::distance(container.begin(), it);
    throw ParameterNotFoundException();
}
