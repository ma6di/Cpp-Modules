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

        PmergeMe::parseInput(argc, argv, vec, deq);

        printContainer("Before: ", vec);

        typedef std::clock_t clock_type;

        clock_type start_vec = std::clock();
        PmergeMe::mergeInsertSortVector(vec);
        clock_type end_vec = std::clock();

        clock_type start_deq = std::clock();
        PmergeMe::mergeInsertSortDeque(deq);
        clock_type end_deq = std::clock();

        printContainer("After: ", vec);

        double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
        double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
                  << time_vec << " us" << std::endl;

        std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " 
                  << time_deq << " us" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
