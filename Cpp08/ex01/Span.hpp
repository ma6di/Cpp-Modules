/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:10:14 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/22 14:10:15 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

class Span {
private:
    unsigned int _N;
    std::vector<int> _container;

public:
    Span(unsigned int N);
    ~Span();

    void addNumber(int num);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;
	void addNumbersRange(int start, int end);

    class SpanIsFullException : public std::exception {
        const char* what() const throw();
    };

    class NoSpanFoundException : public std::exception {
        const char* what() const throw();
    };
};
