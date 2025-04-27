#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <chrono>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    static void parseInput(int argc, char **argv, std::vector<int>& vec, std::deque<int>& deq);
    static void mergeInsertSortVector(std::vector<int>& vec);
    static void mergeInsertSortDeque(std::deque<int>& deq);

private:
    static void insertVector(std::vector<int>& vec, int element);
    static void insertDeque(std::deque<int>& deq, int element);
};

#endif
