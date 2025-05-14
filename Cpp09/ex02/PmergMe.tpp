/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergMe.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:18:50 by mcheragh          #+#    #+#             */
/*   Updated: 2025/05/14 12:19:09 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
size_t PmergeMe<Container>::totalRecursionLevels;

template <typename Container>
size_t PmergeMe<Container>::getComparisons() {
    return comparisons;
}

template <typename Container>
void PmergeMe<Container>::parseInput(int argc, char** argv, Container& container) {
    for (int i = 1; i < argc; ++i) {
        std::istringstream ss(argv[i]);
        value_type num;
        ss >> num;
        // 1) check parse success
        if (ss.fail() || ! (ss >> std::ws).eof()) {
            throw std::runtime_error("Error: Invalid input.");
        }
        // 2) reject negative values
        if (num < 0) {
            throw std::runtime_error("Error: Invalid input.");
        }
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
Container PmergeMe <Container>::recursiveSort(const Container& data) {
    if (data.size() <= 1)
        return data;

    size_t n = data.size();
    Container aList;
    Container pendings;

    for (size_t i = 0; i + 1 < n; i += 2) {
        value_type x = data[i], y = data[i + 1];
        ++comparisons;
        if (y < x)
		{
			std::swap(x, y);
		}
        aList.push_back(y);         // larger
        pendings.push_back(x); // smaller
	}
    if (n % 2 != 0) {
        pendings.push_back(data.back());
    }

    Container mainChain = recursiveSort(aList);

    size_t m = pendings.size();
	std::vector<size_t> compIdx(pendings.size());

	for (size_t i = 0; i < aList.size(); ++i) {
		size_t idx = std::lower_bound(mainChain.begin(), mainChain.end(), aList[i]) - mainChain.begin();
		compIdx[i] = idx;
	}

	// Handle the unpaired odd element if it exists
	if (pendings.size() > aList.size())
		compIdx[pendings.size() - 1] = mainChain.size();  // or a safe default like chain.size()

	#ifndef NDEBUG
		size_t remLevels = countRecursionLevels(mainChain.size());
		size_t depth = totalRecursionLevels - remLevels;
		std::cout << std::endl << "Recursion level " << depth << std::endl;
		printPairs("Original Pairs: ", data);
		printContainer("A list (Main Chain): ", mainChain);
		printContainer("B list (Pending): ", pendings);
		printContainer("B List companion index of A list: ", compIdx);
	#endif

	bool odd = false;
	if (mainChain.size() < pendings.size())
		odd = true;

	std::vector<size_t> order = generateJacobsthalInsertionOrder(m);

	#ifndef NDEBUG
		printContainer("Jacobsthal insertion order: ", order);
		std::cout << "Comparison: " << comparisons << std::endl;
	#endif

	std::vector<bool> inserted(pendings.size(), false);
	Container tempChain = mainChain;

	for (size_t t = 0; t < order.size(); ++t) {
		size_t k = order[t];
		value_type mainVal;
		bool found = false;
		size_t i = 0;

		// Safe index access check
		if (k >= tempChain.size()) {
			if (odd && k == tempChain.size()) {
				// special case: handle the odd leftover
				i = pendings.size() - 1;
				if (!inserted[i]) {
					mainVal = 0;  // fake it to trigger last-element logic
					found = true;
				}
			} else {
				continue; // invalid index, skip
			}
		} else {
			mainVal = tempChain[k];
		}

		// Normal logic for finding the pending element corresponding to mainVal
		if (!found && mainVal) {
			for (; i < aList.size(); ++i) {
				if (i < inserted.size() && !inserted[i] && aList[i] == mainVal) {
					found = true;
					break;
				}
			}
		}

		if (!found || i >= pendings.size() || i >= compIdx.size())
			continue;

		const value_type& v = pendings[i];
		size_t bound = compIdx[i];

		#ifndef NDEBUG
		std::cout << "element to insert in first loop: " << v << std::endl;
		std::cout << "upper bound: " << bound << std::endl;
		#endif

		size_t insPos;
		if (bound == 0) {
			mainChain.insert(mainChain.begin(), v);
			insPos = 0;
		} else {
			insPos = insertBounded(mainChain, v, bound);
		}

		inserted[i] = true;

		// Update compIdx
		for (size_t j = 0; j < compIdx.size(); ++j) {
			if (!inserted[j] && compIdx[j] >= insPos)
				++compIdx[j];
		}
		
		#ifndef NDEBUG
		printContainer("B List companion index of A list: ", compIdx);
		printContainer("A list (Main Chain): ", mainChain);
		std::cout << "Comparison: " << comparisons << std::endl;
		#endif
	}

    return mainChain;
}

template <typename Container>
size_t PmergeMe<Container>::insertBounded(Container& c, const value_type& v,
                                          size_t upperBound)
{
    // special‐case b₀ at front
    if (upperBound == 0) {
        c.insert(c.begin(), v);
        return 0;
    }

    typename Container::iterator left  = c.begin();
    typename Container::iterator right = c.begin() + upperBound;

    while (left < right) {
        ++comparisons;
        typename Container::iterator mid = left + (right - left) / 2;
        if (v < *mid)
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
