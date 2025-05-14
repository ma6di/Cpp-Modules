/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:18:35 by mcheragh          #+#    #+#             */
/*   Updated: 2025/05/14 11:26:47 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void display_time(clock_t start, clock_t end)
{
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    int sec = static_cast<int>(duration);
    int msec = static_cast<int>((duration - sec) * 1000);
    int usec = static_cast<int>(((duration - sec) * 1000000)) % 1000;

    std::cout << sec << "s " << msec << "ms " << usec << "µs" << std::endl;
}

int main(int argc, char** argv) {
    try {
		
		PmergeMe<std::vector<int> > vecSorter;
		std::vector<int> print;
		vecSorter.parseInput(argc, argv, print);
		printContainer("Before: ", print);
		
		clock_t start_vec = clock();
		std::vector<int> vec;
		vecSorter.parseInput(argc, argv, vec);
		vecSorter.mergeInsertSort(vec);
		clock_t end_vec = clock();

		printContainer("After : ", vec);
		
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : ";
		display_time(start_vec, end_vec);

		#ifdef NDEBUG
		std::deque<int> deq;
		PmergeMe<std::deque<int> > deqSorter;
		clock_t start_deq = clock();
		deqSorter.parseInput(argc, argv, deq);
		deqSorter.mergeInsertSort(deq);
		clock_t end_deq = clock();
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : ";
		display_time(start_deq, end_deq);
		#endif

		#ifndef NDEBUG
		printOptimalComparisonTable( vecSorter.getComparisons(), argc - 1);
		#endif

	} catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
