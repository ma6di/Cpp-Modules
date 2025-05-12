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
size_t PmergeMe<Container>::comparisons = 0;


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

	// printContainer("subSorted: ", subSorted);
	// printContainer("levelPendings: ", levelPendings);

    // 3) merge pendings from subSorted + this level
    Container pendingAll = levelPendings;

    // 4) chain = sortedChain from sub
	Container chain = subSorted;
	std::vector<std::pair<value_type, size_t> > indexVec;
	for (size_t i = 0; i < chain.size(); ++i)
		indexVec.push_back(std::make_pair(chain[i], i));
	
    // 5) build companionIdx
    size_t m = pendingAll.size();
    std::vector<size_t> compIdx(m);
    // first |aList| pendings correspond to pairs; companion = index of a_i in chain
	for (size_t i = 0; i < aList.size(); ++i) {
		size_t idx = chain.size(); // default if not found
		for (size_t j = 0; j < indexVec.size(); ++j) {
			if (indexVec[j].first == aList[i]) {
				idx = indexVec[j].second;
				break;
			}
		}
		compIdx[i] = idx;
	}
	
    // leftovers
    for (size_t i = aList.size(); i < m; ++i)
        compIdx[i] = chain.size();

    // 6) get insertion order J(·)
    std::vector<size_t> order = generateJacobsthalInsertionOrder(m);
		
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
	
	if (upperBound > 0 && !less(v, *(c.begin() + upperBound - 1))) {
		++comparisons; // comparison to last element
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


template <typename Container>
std::vector<size_t> PmergeMe<Container>::generateJacobsthalInsertionOrder(size_t n) {
    std::vector<size_t> order;
    if (n == 0) return order;
    // J0 = 0, J1 = 1
    order.push_back(0);
    if (n > 1) order.push_back(1);

    size_t a = 1, b = 1, Jprev = 1;
    while (true) {
        size_t Jk = b + 2*a;  // Jacobsthal recurrence
        if (Jk > n-1) break;
        for (size_t x = Jk; x > Jprev; --x)
            order.push_back(x);
        a = b; b = Jk; Jprev = Jk;
    }
    // finish off
    for (size_t i = Jprev+1; i < n; ++i)
        order.push_back(i);

    return order;
}

template<typename Container>
void PmergeMe<Container>::printContainer(const std::string& label, const Container& container)
{
    typename Container::const_iterator it;
    std::cout << label;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

