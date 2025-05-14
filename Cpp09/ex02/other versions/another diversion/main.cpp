#include <vector>
#include <deque>
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
		std::vector<int> vec;
		PmergeMe<std::vector<int> > vecSorter;
		std::vector<int> print;
		vecSorter.parseInput(argc, argv, print);
		printContainer("Before: ", print);

		clock_t start_vec = clock();
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
		// for (int n = 1; n <= 30; ++n) {
		// 	std::vector<int> v(n);
		// 	// C++98: fill with 0,1,2,…,n−1
		// 	for (int i = 0; i < n; ++i)
		// 		v[i] = i;
		// 	std::random_shuffle(v.begin(), v.end());
			
			
		// 	PmergeMe<std::vector<int> >::resetComparisons();
		// 	PmergeMe<std::vector<int> >::mergeInsertSort(v);
		// 	int got = PmergeMe<std::vector<int> >::getComparisons();
			
		// 	int optimal = 0;
		// 	for (int k = 1; k <= n; ++k)
		// 		optimal += std::ceil(std::log(3.0*k/4.0)/std::log(2.0));
			
		// 	if (got != optimal)
		// 		std::cerr << "n="<<n<<" got="<<got<<" opt="<<optimal<<"\n";
		// }
		

	} catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
