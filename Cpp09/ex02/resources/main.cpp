
#include "PmergeMe.hpp"
#include <deque>
#include <ctime> 
#include <vector>
#include "MyList.hpp"
#include <sys/time.h>

void display_time(clock_t start, clock_t end)
{
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    int sec = static_cast<int>(duration);
    int msec = static_cast<int>((duration - sec) * 1000);
    int usec = static_cast<int>(((duration - sec) * 1000000)) % 1000;

    std::cout << sec << "s " << msec << "ms " << usec << "µs" << std::endl;
}

void print_argv(int argc, char **argv)
{
    std::cout << std::endl << "Before: ";
    for (int i = 1; i < argc; ++i)
        std::cout << argv[i] << (i < argc - 1 ? " " : "\n");
}

void printOptimalComparisonTable(int n) {
    int totalComparisons = 0;
    for (int k = 1; k <= n; ++k) {
        totalComparisons += std::ceil(std::log(3.0 * k / 4.0) / std::log(2.0));
    }
	std::cout << std::endl;
    std::cout << "Element count: " << n << std::endl;
    std::cout << "Optimal comparisons (Ford_Johnson): " << totalComparisons << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return 0;

    print_argv(argc, argv);
    clock_t t1, t2;

    try {
        t1 = std::clock();
        PmergeMe< std::deque<long int> > deq(argc, argv, true);
        t2 = std::clock();
        std::cout << "Time (deque): ";
        display_time(t1, t2);

        t1 = std::clock();
        PmergeMe< std::vector<long int> > vec(argc, argv, false);
        t2 = std::clock();
        std::cout << "Time (vector): ";
        display_time(t1, t2);
    }
    catch (const std::exception& e) {
        if (g_errorPrimed) {
            std::cerr << "Error: " << e.what() << std::endl;
            return -1;
        }
    }
	printOptimalComparisonTable(argc - 1);
    return 0;
}


