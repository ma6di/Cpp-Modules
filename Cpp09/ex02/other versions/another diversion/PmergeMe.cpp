#include "PmergeMe.hpp"

void printOptimalComparisonTable(int actualComparisons, int n) {
	int totalComparisons = 0;
	for (int k = 1; k <= n; ++k) {
		totalComparisons += std::ceil(std::log(3.0 * k / 4.0) / std::log(2.0));
	}
	
    std::cout << "Element count: " << n << std::endl;
    std::cout << "Your comparisons: " << actualComparisons << std::endl;
    std::cout << "Optimal comparisons (Ford–Johnson): " << totalComparisons << std::endl;
}
