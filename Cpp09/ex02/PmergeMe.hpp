/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:18:58 by mcheragh          #+#    #+#             */
/*   Updated: 2025/05/14 11:22:30 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>
#include <cmath>

template <typename Container>
class PmergeMe {
public:

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

    typedef typename Container::value_type value_type;
    typedef typename Container::iterator iterator;

    static void parseInput(int argc, char** argv, Container& container);
    static void mergeInsertSort(Container& container);
	static size_t countRecursionLevels(size_t n);
	static size_t getComparisons();
	
	static size_t  totalRecursionLevels;
	

private:

	static size_t comparisons;

    // Recursive Ford-Johnson sort
    static Container recursiveSort(const Container& input);

    // Insert an element into the sorted range using binary search
	// returns the zero-based index where `v` was inserted into c
	static size_t insertBounded(Container& c, const value_type& v,
											size_t upperBound);
	// Generate the Jacobsthal insertion order	   
	static std::vector<size_t> generateJacobsthalInsertionOrder(size_t n);

};

void printOptimalComparisonTable(int actualComparisons, int n);

template <typename Container>
void printContainer(const std::string& label, const Container& container);

#include "PmergMe.tpp"
