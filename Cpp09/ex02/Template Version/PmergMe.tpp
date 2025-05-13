// PmergeMe_t.tpp
// ------------------
// C++98 Ford–Johnson (merge-insertion) sort with Jacobsthal sequence
// Implements PmergeMe<Container> defined in PmergeMe_t.hpp

#include <algorithm>  // for std::find
#include <cmath>      // for std::ceil, std::log
#include <vector>     // for generateJacobsthalInsertionOrder

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& other) 
{
    (void)other;
}

template <typename Container>
PmergeMe<Container>&
PmergeMe<Container>::operator=(const PmergeMe<Container>& other) 
{
    (void)other;
    return *this;
}

template <typename Container>
void printContainer(const std::string& label, const Container& c) {
    std::cout << label;
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename Container>
void printPairs(const std::string& label, const Container& c) {
    std::cout << label;
	size_t count = 0;
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
	{
		if (count == 0)
		{
			std::cout << "(";
		}
        std::cout << *it ;
		count++;
		if (count % 2 != 0 )
			std::cout << " ";
		if (count % 2 == 0 && count != c.size())
			std::cout << "), (";
	}
	std::cout << ")";
	
    std::cout << std::endl;
}

template <typename Container>
size_t PmergeMe<Container>::comparisons = 0;

template <typename Container>
int PmergeMe<Container>::totalRecursionLevels;

template <typename Container>
size_t PmergeMe<Container>::getComparisons() {
    return comparisons;
}

template <typename Container>
void PmergeMe<Container>::resetComparisons() {
    comparisons = 0;
}

template <typename Container>
void PmergeMe<Container>::parseInput(int argc, char** argv, Container& container) {
    for (int i = 1; i < argc; ++i) {
        std::istringstream ss(argv[i]);
        value_type num;
        ss >> num;
        if (ss.fail() || !ss.eof())
            throw std::runtime_error("Error: Invalid input.");
        container.push_back(num);
    }
}

template <typename Container>
void PmergeMe<Container>::mergeInsertSort(Container& container) {
    if (container.size() <= 1)
        return;
	totalRecursionLevels = countRecursionLevels(container.size());
    Container sorted = recursiveSort(container);

    container = sorted;
}

template <typename Container>
Container PmergeMe<Container>::recursiveSort(const Container& data) {
    // Base
    if (data.size() <= 1)
        return data;

    size_t n = data.size();
    // 1) form pairs and collect b_i (smaller) into levelPendings
    Container aList;
    Container levelPendings;

	// size_t recurisonCount = 1;

    for (size_t i = 0; i + 1 < n; i += 2) {
        value_type x = data[i], y = data[i+1];
        ++comparisons;
        if (less(y, x)) std::swap(x,y);
        // x = b_i, y = a_i
        aList.push_back(y);
        levelPendings.push_back(x);
    }
    if (n % 2 != 0) {
        levelPendings.push_back(data.back());
    }

    // 2) recurse on all a_i
    Container subSorted = recursiveSort(aList);


    // 3) merge pendings from subSorted + this level
    Container pendingAll = levelPendings;

    // 4) chain = sortedChain from sub
	Container chain = subSorted;

    // 5) build companionIdx
    size_t m = pendingAll.size();
    std::vector<size_t> compIdx(m);
    // first |aList| pendings correspond to pairs; companion = index of a_i in chain
	for (size_t i = 0; i < aList.size(); ++i) {
		size_t idx = std::lower_bound(chain.begin(), chain.end(), aList[i]) - chain.begin();
		compIdx[i] = idx;
	}


    // leftovers
    for (size_t i = aList.size(); i < m; ++i)
        compIdx[i] = chain.size();

    // 6) get insertion order J()
    std::vector<size_t> order = generateJacobsthalInsertionOrder(m);
	#ifdef DEBUG
	size_t remLevels = countRecursionLevels(chain.size());
	size_t depth = totalRecursionLevels - remLevels;

	std::cout << "Recursion level " << depth << std::endl;

	printPairs("Pairs: ", data);
	printContainer("A lisr (Main Chain): ", chain);
	printContainer("B list (Pending): ", pendingAll);
	printContainer("B List companion index of A list: ", compIdx);
	printContainer("Jacobsthal insertion order: ", order);
	std::cout << std::endl;
	#endif
    // 7) insert each pending in J-order, bounded by compIdx
	for (size_t t = 0; t < order.size(); ++t) {
		size_t k = order[t];
		size_t bound = compIdx[k];
		const value_type& v = pendingAll[k];
	
		// Do the bounded insert
		size_t insPos = insertBounded(chain, v, bound);
	
		// Update companion indices after insert
		for (size_t j = 0; j < m; ++j) {
			if (compIdx[j] >= insPos)
				++compIdx[j];
		}
	}	

    return chain;
}

template <typename Container>
size_t PmergeMe<Container>::insertBounded(Container& c,
                                          const value_type& v,
                                          size_t upperBound)
{
    // special‐case b₀ at front
    if (upperBound == 0) {
        c.insert(c.begin(), v);
        return 0;
    }
	
	if (upperBound > 0 && v >= c[upperBound - 1]) {
		++comparisons;
		c.insert(c.begin() + upperBound, v);
		return upperBound;
	}
	

    typename Container::iterator left  = c.begin();
    typename Container::iterator right = c.begin() + upperBound;

    while (left < right) {
        ++comparisons;
        typename Container::iterator mid = left + (right - left) / 2;
        if (less(v, *mid))
            right = mid;
        else
            left = mid + 1;
    }

    // `left` is the insertion point
    size_t idx = std::distance(c.begin(), left);
    c.insert(left, v);
    return idx;
}

template <typename Container>
bool PmergeMe<Container>::less(const value_type& a, const value_type& b) {
    return a < b;
}

template <typename Container>
size_t PmergeMe<Container>::countRecursionLevels(size_t n) {
    size_t levels = 0;
    while (n > 1) {
        n /= 2;  // Only the 'a_i' elements (bigger ones) are recursed
        ++levels;
    }
    return levels;
}


// template <typename Container>
// std::vector<size_t> PmergeMe<Container>::generateJacobsthalInsertionOrder(size_t n) {
//     std::vector<size_t> order;
//     if (n == 0) return order;
//     // J0 = 0, J1 = 1
//     order.push_back(0);
//     if (n > 1) order.push_back(1);

//     size_t a = 1, b = 1, Jprev = 1;
//     while (true) {
//         size_t Jk = b + 2*a;  // Jacobsthal recurrence
//         if (Jk > n-1) break;
//         for (size_t x = Jk; x > Jprev; --x)
//             order.push_back(x);
//         a = b; b = Jk; Jprev = Jk;
//     }
//     // finish off
// 	for (size_t i = Jprev + 1; i < n; ++i) {
// 		order.push_back(i);
// 	}
	

//     return order;
// }

template <typename Container>
std::vector<size_t> PmergeMe<Container>::generateJacobsthalInsertionOrder(size_t n) {
    std::vector<size_t> order;
    if (n == 0) return order;
    if (n >= 1) order.push_back(0);
    if (n >= 2) order.push_back(1);

    // 1) build Jacobsthal numbers up to n
    std::vector<size_t> J;
    J.push_back(0);
    J.push_back(1);
    while (true) {
        size_t next = J[J.size()-1] + 2 * J[J.size()-2];
        if (next >= n) break;
        J.push_back(next);
    }

    // 2) for each k >= 2, append indices J[k] down to J[k-1]+1
    for (size_t k = 2; k < J.size(); ++k) {
        size_t hi = J[k];
        size_t lo = J[k-1] + 1;
        // ensure hi < n
        if (hi >= n) hi = n-1;
        for (size_t idx = hi; idx >= lo; --idx) {
            order.push_back(idx);
            if (idx == lo) break;  // prevent underflow
        }
    }

    // 3) finally append any remaining indices > J.back()
    size_t lastJ = J.back();
    for (size_t idx = lastJ + 1; idx < n; ++idx) {
        order.push_back(idx);
    }

    return order;
}


