#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <ctime> 
#include <vector>
#include <sys/time.h>
#include "MyList.hpp"
#include "PairKeeper.hpp"

#define DUMMY_VAL 2147483650
#define MIL 1000000

#ifndef GLOBALS_HPP
#define GLOBALS_HPP
extern bool g_errorPrimed;
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
    virtual void do_sort(int argc, char **argv);      // Main entry

    void take_apart();                                // Step 1: pairing
    void assemble();                                  // Step 2: recursion
    int  calculate_depth(int argc);                   // Recursion control

    int  my_pair(int my_num);                         // Pairing index helpers
    int  my_pair_up(int my_num, int diff);
    void create_sequence(Container& cont, Container& pair);   // Fill insertion order
    void follow_sequence(Container& cont, Container& pair);   // Apply insertion order

    void merge_containers(Container& from, Container& to);    // Merge logic
    void copy_merge(Container& from, Container& to);          // Copy-based merge
    void reassess_size();                                     // Adjust values
    void clear_dummy_vals(Container& cont);                   // Clean up garbage

    typename Container::iterator recalc_bounds(Container& from, int jacob_index);
    typename Container::iterator calc_last(Container& cont, int idx);

    // Sort control
    int recursion_levels;
    int depth;
    int bottom;
    int breakpoint;

    // Meta
    int prev_containers;
    int cur_containers;
    int seq_max;
    int og_size;

    // State
    typename Container::iterator last_bound;
    Container sequence;
    Container infiniteJakob;
    MyList<Container> cont_chain;
    PairKeeper lookup;
    std::deque<std::pair<int, int> > inserted;

public:
    int comp;  // Comparison count (for benchmarking)
};

#include "PmergeMe.tpp"
