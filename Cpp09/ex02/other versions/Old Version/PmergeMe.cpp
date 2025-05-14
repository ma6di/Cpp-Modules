#include "PmergeMe.hpp"

int PmergeMe::_vectorComparisons = 0;
int PmergeMe::_dequeComparisons = 0;

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {}
    return *this;
}

void PmergeMe::parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq) {
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        for (size_t j = 0; j < arg.size(); ++j) {
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

void PmergeMe::insertVector(std::vector<int>& vec, int element) {
    int left = 0;
    int right = vec.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        ++_vectorComparisons;
        if (vec[mid] < element)
            left = mid + 1;
        else
            right = mid;
    }
    vec.insert(vec.begin() + left, element);
}

void PmergeMe::insertDeque(std::deque<int>& deq, int element) {
    int left = 0;
    int right = deq.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        ++_dequeComparisons;
        if (deq[mid] < element)
            left = mid + 1;
        else
            right = mid;
    }
    deq.insert(deq.begin() + left, element);
}

std::vector<size_t> generateJacobsthalInsertionOrder(size_t n) {
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n) {
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    }

    std::vector<size_t> order;
    for (size_t i = 1; i + 1 < jacob.size(); ++i) {
        size_t a = jacob[i];
        size_t b = jacob[i + 1];
        for (int j = static_cast<int>(b) - 1; j >= static_cast<int>(a) && j >= 0 && static_cast<size_t>(j) < n; --j) {
            order.push_back(static_cast<size_t>(j));
        }
    }
    if (n > 0 && std::find(order.begin(), order.end(), n - 1) == order.end()) {
        order.push_back(n - 1);
    }
    return order;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec) {
    if (vec.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> pending;

    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        ++_vectorComparisons;
        if (vec[i] > vec[i + 1])
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
        else
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    if (vec.size() % 2 != 0)
        pending.push_back(vec.back());

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].second);

    mergeInsertSortVector(mainChain);

    for (size_t i = 0; i < pairs.size(); ++i)
        pending.push_back(pairs[i].first);

    std::vector<size_t> insertionOrder = generateJacobsthalInsertionOrder(pending.size());
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        if (insertionOrder[i] < pending.size())
            insertVector(mainChain, pending[insertionOrder[i]]);
    }

    vec = mainChain;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    std::deque<int> pending;

    for (size_t i = 0; i + 1 < deq.size(); i += 2) {
        ++_dequeComparisons;
        if (deq[i] > deq[i + 1])
            pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
        else
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
    }
    if (deq.size() % 2 != 0)
        pending.push_back(deq.back());

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].second);

    mergeInsertSortDeque(mainChain);

    for (size_t i = 0; i < pairs.size(); ++i)
        pending.push_back(pairs[i].first);

    std::vector<size_t> insertionOrder = generateJacobsthalInsertionOrder(pending.size());
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        if (insertionOrder[i] < pending.size())
            insertDeque(mainChain, pending[insertionOrder[i]]);
    }

    deq = mainChain;
}

int PmergeMe::getVectorComparisons() const {
    return _vectorComparisons;
}

int PmergeMe::getDequeComparisons() const {
    return _dequeComparisons;
}

void printOptimalComparisonTable(int actualComparisons, int n) {
    int totalComparisons = 0;
    for (int k = 1; k <= n; ++k) {
        totalComparisons += std::ceil(std::log(3.0 * k / 4.0) / std::log(2.0));
    }
    std::cout << "Element count: " << n << std::endl;
    std::cout << "Your comparisons: " << actualComparisons << std::endl;
    std::cout << "Optimal comparisons (Ford–Johnson): " << totalComparisons << std::endl;
}
