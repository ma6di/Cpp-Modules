
#include "PmergeMe.hpp"

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
		if (argc == 2)
		{

			std::cout << "After:  " << argv[1] << std::endl;
			
			std::cout << std::endl << "Number of comparisons: 0" << std::endl;
			return 0;
		}
        t1 = std::clock();
        PmergeMe< std::deque<long int> > deq(argc, argv);
        t2 = std::clock();
		std::cout << "After:  ";
        deq.print_content();
        std::cout << "Time (deque): ";
        display_time(t1, t2);
		
        t1 = std::clock();
        PmergeMe< std::vector<long int> > vec(argc, argv);
        t2 = std::clock();
        std::cout << "Time (vector): ";
        display_time(t1, t2);
		std::cout << std::endl << "Number of comparisons: " << deq.comparisonCount << std::endl;
    }
    catch (const std::exception& e) {
        if (g_errorDetected) {
            std::cerr << "Error: " << e.what() << std::endl;
            return -1;
        }
    }
	printOptimalComparisonTable(argc - 1);
    return 0;
}


