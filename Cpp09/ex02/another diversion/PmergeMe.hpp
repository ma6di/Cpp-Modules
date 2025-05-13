#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>
#include <string>
#include <cmath>      // for std::ceil, std::log
#include <cstdlib>   // for std::rand, std::srand
#include <ctime>     // for std::clock, std::clock_t
#include <iomanip>   // for std::setprecision
#include <limits>    // for std::numeric_limits
#include <utility>   // for std::pair
#include <functional> // for std::less




template <typename Container>
class PmergeMe {
public:

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

    typedef typename Container::value_type value_type;
    typedef typename Container::iterator iterator;

    // Parse command-line input into the container
    static void parseInput(int argc, char** argv, Container& container);

    // Entry point for sorting
    static void mergeInsertSort(Container& container);


	static size_t countRecursionLevels(size_t n);
	static size_t getComparisons();
	static void resetComparisons();

	static size_t  totalRecursionLevels;
	

private:

	static size_t comparisons;

    // Recursive Ford-Johnson sort
    static Container recursiveSort(const Container& input);

    // Insert an element into the sorted range using binary search
// returns the zero-based index where `v` was inserted into c
	static size_t insertBounded(Container& c,
		const value_type& v,
		size_t upperBound);

    static bool less(const value_type& a, const value_type& b);
			   
	static std::vector<size_t> generateJacobsthalInsertionOrder(size_t n);

};

void printOptimalComparisonTable(int actualComparisons, int n);

template <typename Container>
void printContainer(const std::string& label, const Container& container);


#include "PmergMe.tpp"
