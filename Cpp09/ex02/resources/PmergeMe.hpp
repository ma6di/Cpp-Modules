/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:54:50 by mhuszar           #+#    #+#             */
/*   Updated: 2025/04/30 15:01:49 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <cmath>
#include "MyList.hpp"
#include "PairKeeper.hpp"

#define DUMMY_VAL 2147483650

#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif

#ifndef COUNT
# define COUNT 1
#endif

#define MIL 1000000

// globals.hpp
#ifndef GLOBALS_HPP
#define GLOBALS_HPP

extern bool g_errorPrimed;

#endif


template <class Container>
class PmergeMe
{

    public:

        PmergeMe(int argc, char **argv, bool print);
        ~PmergeMe(void);

    private:

        PmergeMe(void);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

    protected:

        virtual void    do_sort(int argc, char **argv);

        void            take_apart();
        void            assemble();

        void            intake_sequence(int argc, char **seq);
        int             calculate_depth(int argc);

        int             my_pair(int my_num);
        int             my_pair_up(int my_num, int diff);
        void            create_sequence(Container& cont, Container& pair);
        void            follow_sequence(Container& cont, Container& pair);
        void            merge_containers(Container& from, Container& to);
        void            copy_merge(Container& from, Container& to);
        void            reassess_size();
        void            clear_dummy_vals(Container& cont);
        void            print_content(Container& cont);
        
        typename Container::iterator recalc_bounds(Container& from, int jacob_index);
        typename Container::iterator calc_last(Container& cont, int idx);
    
    
        int             depth;
        int             recursion_levels;
        int             bottom;
        int             breakpoint;

        int             prev_containers;
        int             cur_containers;
        int             seq_max;
        int             comp;
        int             og_size;

        typename Container::iterator        last_bound;
        Container                           sequence;
        Container                           infiniteJakob;
        MyList<Container>                   cont_chain;
        PairKeeper                          lookup;
        std::deque < std::pair < int, int > > inserted;
};


#include "PmergeMe.tpp"

#endif