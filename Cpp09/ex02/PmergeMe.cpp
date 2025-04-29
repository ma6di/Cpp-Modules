#include "PmergeMe.hpp"

int PmergeMe::_vectorComparisons = 0;
int PmergeMe::_dequeComparisons = 0;

PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other) {
        return *this; 
    }
    return *this;
};
PmergeMe::PmergeMe(const PmergeMe& other){(void)(other);
};

void PmergeMe::parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        for (size_t j = 0; j < arg.size(); ++j)
        {
            if (!isdigit(arg[j]))
                throw std::runtime_error("Non digit element");
        }
		char* end;
        long num = std::strtol(arg.c_str(), &end, 10);
        if (num < 0 || num > INT_MAX)
            throw std::runtime_error("Number bigger than MAX_INT");
        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
}

void PmergeMe::insertVector(std::vector<int>& vec, int element)
{
    int left = 0;
    int right = vec.size();
    int mid;

    while (left < right)
    {
        mid = left + (right - left) / 2;
        _vectorComparisons++;  // one comparison per iteration

        if (vec[mid] < element)
            left = mid + 1;
        else
            right = mid;
    }

    vec.insert(vec.begin() + left, element);
}

void PmergeMe::insertDeque(std::deque<int>& deq, int element)
{
    int left = 0;
    int right = deq.size();
    int mid;

    while (left < right)
    {
        mid = left + (right - left) / 2;
        _dequeComparisons++;  // one comparison per iteration

        if (deq[mid] < element)
            left = mid + 1;
        else
            right = mid;
    }

    deq.insert(deq.begin() + left, element);
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pendingElements;

    // Pair elements and sort inside pairs
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        _vectorComparisons++;  // Count comparison before swap, not after
        if (vec[i] > vec[i + 1]) {
            std::swap(vec[i], vec[i + 1]);
        }
        mainChain.push_back(vec[i + 1]);
        pendingElements.push_back(vec[i]);
    }
    if (vec.size() % 2 != 0)
        pendingElements.push_back(vec.back());

    mergeInsertSortVector(mainChain);

    vec = mainChain;
    for (size_t i = 0; i < pendingElements.size(); ++i)
        insertVector(vec, pendingElements[i]);
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return;

    std::deque<int> mainChain;
    std::deque<int> pendingElements;

    // Pair elements and sort inside pairs
    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        _dequeComparisons++;  // Count comparison before swap, not after
        if (deq[i] > deq[i + 1]) {
            std::swap(deq[i], deq[i + 1]);
        }
        mainChain.push_back(deq[i + 1]);
        pendingElements.push_back(deq[i]);
    }
    if (deq.size() % 2 != 0)
        pendingElements.push_back(deq.back());

    mergeInsertSortDeque(mainChain);

    deq = mainChain;
    for (size_t i = 0; i < pendingElements.size(); ++i)
        insertDeque(deq, pendingElements[i]);
}

int PmergeMe::getVectorComparisons() const {
	return _vectorComparisons;
}

int PmergeMe::getDequeComparisons() const {
	return _dequeComparisons;
}

void printOptimalComparisonTable(int actualComparisons, int n) {
    int totalComparisons = 0;

    // Sum the comparisons for each element
    for (int k = 1; k <= n; ++k) {
        // Calculate ceil(log2(3k / 4))
        totalComparisons += std::ceil(log2(3.0 * k / 4.0));
    }

    std::cout << "Element count: " << n << std::endl;
    std::cout << "Your comparisons: " << actualComparisons << std::endl;
    std::cout << "Optimal comparisons (Ford–Johnson): " << totalComparisons << std::endl;

}