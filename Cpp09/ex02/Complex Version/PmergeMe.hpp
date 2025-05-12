#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <ctime> 
#include <vector>
#include <sys/time.h>
#include "ContainerChainManager.hpp"
#include "InsertionIndexTracker.hpp"

#define INVALID_MARKER 2147483650
#define MIL 1000000

#ifndef GLOBALS_HPP
#define GLOBALS_HPP
extern bool g_errorDetected;
#endif


template <class Container>
class PmergeMe
{
public:
    PmergeMe();                                       // Default constructor
    PmergeMe(int argc, char **argv);                  // Init + sort
    PmergeMe(const PmergeMe& other);                  // Copy constructor
    PmergeMe& operator=(const PmergeMe& other);       // Copy assignment
    ~PmergeMe();                                      // Destructor

    void print_content();                             // Output sorted content

protected:
    virtual void performMergeInsertSort(int argc, char **argv);      // Main entry

    void splitIntoPairs();                                // Step 1: pairing
    void mergeSortedPairs();                                  // Step 2: recursion
    int  calculateRecursionDepth(int argc);                   // Recursion control

    int  findPairIndex(int my_num);                         // Pairing index helpers
    int  findUpperPairIndex(int my_num, int diff);
    void generateInsertionOrder(Container& cont, Container& pair);   // Fill insertion order
    void applyInsertionOrder(Container& cont, Container& pair);   // Apply insertion order

    void mergeSortedContainers(Container& from, Container& to);    // Merge logic
    void mergeWithCopyOperation(Container& from, Container& to);          // Copy-based merge
    void updateContainerMetrics();                                     // Adjust values
    void removeSentinelMarkers(Container& cont);                   // Clean up garbage

    typename Container::iterator calculateInsertionBoundary(Container& from, int jacob_index);
    typename Container::iterator findLastInsertionPoint(Container& cont, int idx);

    // Sort control
    int maxRecursionDepth;
    int depth;
    int minRecursionLevel;
    int recursionBreakpoint;

    // Meta
    int previousContainerCount;
    int currentContainerCount;
    int maxSequenceLength;
    int originalSize;

    // State
    typename Container::iterator lastInsertionBoundary;
    Container sequence;
    Container jacobsthalSequence;
    ContainerChainManager<Container> containerChain;
    InsertionIndexTracker lookup;
    std::deque<std::pair<int, int> > insertionHistory;

public:
    int comparisonCount;  // Comparison count (for benchmarking)
};

#include "PmergeMe.tpp"
