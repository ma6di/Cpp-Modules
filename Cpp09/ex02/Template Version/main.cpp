#include <vector>
#include <deque>
#include "PmergeMe.hpp"



int main(int argc, char** argv) {
    try {
		std::vector<int> vec;
		PmergeMe<std::vector<int> > vecSorter;
		vecSorter.parseInput(argc, argv, vec);

		printContainer("Before: ", vec);
		clock_t start_vec = clock();
		vecSorter.mergeInsertSort(vec);
		clock_t end_vec = clock();

			
		std::deque<int> deq;
		PmergeMe<std::deque<int> > deqSorter;
		deqSorter.parseInput(argc, argv, deq);

		printContainer("After : ", vec);
		// std::sort(deq.begin(), deq.end());
		// printContainer("After : ", deq);

		clock_t start_deq = clock();
		deqSorter.mergeInsertSort(deq);
		clock_t end_deq = clock();
	
        

		double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
        double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
			<< time_vec << " us" << std::endl;

		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " 
			<< time_deq << " us" << std::endl;
		
		printOptimalComparisonTable( vecSorter.getComparisons(), argc - 1);

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
