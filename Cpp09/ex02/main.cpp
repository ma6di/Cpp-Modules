#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: plz enter arguments" << std::endl;
        return 1;
    }

    try
    {
        std::vector<int> vec;
        std::deque<int> deq;

		PmergeMe sorter;
        sorter.parseInput(argc, argv, vec, deq);

        printContainer("Before: ", vec);


        clock_t start_vec = clock();
        sorter.mergeInsertSortVector(vec);
        clock_t end_vec = clock();

        clock_t start_deq = clock();
        sorter.mergeInsertSortDeque(deq);
        clock_t end_deq = clock();

        printContainer("After: ", vec);

        double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
        double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
                  << time_vec << " us" << std::endl;

        std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " 
                  << time_deq << " us" << std::endl;
		std::cout << "Vector comparisons: " << sorter.getVectorComparisons() << std::endl;
		std::cout << "Deque comparisons: " << sorter.getDequeComparisons() << std::endl;

		printOptimalComparisonTable(sorter.getVectorComparisons(), argc - 1);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
