/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:10:10 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/22 15:21:28 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}
Span::~Span() {}

void Span::addNumber(int num)
{
    if (_container.size() >= _N)
        throw SpanIsFullException();
    _container.push_back(num);
}

//container.insert(position_iterator, start_iterator, end_iterator);
void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_container.size() + std::distance(begin, end) > _N)
        throw SpanIsFullException();
    _container.insert(_container.end(), begin, end);
}

void Span::addNumbersRange(int start, int end)
{
    if (start > end)
        std::swap(start, end);  // Ensure ascending order

    for (int i = start; i <= end; ++i)
    {
        if (_container.size() >= _N)
            throw SpanIsFullException();
        _container.push_back(i);
    }
}

int Span::shortestSpan() const {
    if (_container.size() < 2)
        throw NoSpanFoundException();

    std::vector<int> temp = _container;
    std::sort(temp.begin(), temp.end());

    int minSpan = temp[1] - temp[0];
    for (size_t i = 1; i < temp.size() - 1; ++i) {
        int span = temp[i + 1] - temp[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_container.size() < 2)
        throw NoSpanFoundException();

    int min = *std::min_element(_container.begin(), _container.end());
    int max = *std::max_element(_container.begin(), _container.end());
    return max - min;
}

const char* Span::SpanIsFullException::what() const throw() {
    return "Span is full";
}

const char* Span::NoSpanFoundException::what() const throw() {
    return "Not enough elements to find a span";
}
