#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <map>
#include <cmath>
#include <cstdlib>
#include <algorithm>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& other);
	PmergeMe(const PmergeMe& other);
	
    static void parseInput(int argc, char **argv, std::vector<int>& vec, std::deque<int>& deq);
    static void mergeInsertSortVector(std::vector<int>& vec);
    static void mergeInsertSortDeque(std::deque<int>& deq);
	int getVectorComparisons() const;
	int getDequeComparisons() const;

private:
	static int _vectorComparisons;
	static int _dequeComparisons;
    static void insertVector(std::vector<int>& vec, int element);
    static void insertDeque(std::deque<int>& deq, int element);
};

template<typename T>
void printContainer(const std::string& label, const T& container)
{
    typename T::const_iterator it;
    std::cout << label;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void printOptimalComparisonTable(int actualComparisons, int n);
#endif


/*
Input = [7,3,6,2,9,1,8,5]

First Pair:
mainChain = [7,6,9,8]
pendingElements = [3,2,1,5]

	Recursively sort mainChain [7,6,9,8]
	Pair:
	mainChain = [7,9]
	pendingElements = [6,8]

		Recursively sort mainChain [7,9]
		Pair:
		mainChain = [9]
		pendingElements = [7]
        
			Recursively sort mainChain [9] → returns
			Insert 7 into [9] → [7,9]

    Insert 6 into [7,9] → [6,7,9]
    Insert 8 into [6,7,9] → [6,7,8,9]

Insert pendingElements [3,2,1,5] into [6,7,8,9]
Insert 3 → [3,6,7,8,9]
Insert 2 → [2,3,6,7,8,9]
Insert 1 → [1,2,3,6,7,8,9]
Insert 5 → [1,2,3,5,6,7,8,9]
*/

//duplicate