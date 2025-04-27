#include "PmergeMe.hpp"

// Constructor and Destructor
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        for (size_t j = 0; j < arg.size(); ++j)
        {
            if (!isdigit(arg[j]))
                throw std::runtime_error("Error");
        }
        long num = std::stol(arg);
        if (num < 0 || num > INT32_MAX)
            throw std::runtime_error("Error");
        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
}

void PmergeMe::insertVector(std::vector<int>& vec, int element)
{
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end() && *it < element)
        ++it;
    vec.insert(it, element);
}

void PmergeMe::insertDeque(std::deque<int>& deq, int element)
{
    std::deque<int>::iterator it = deq.begin();
    while (it != deq.end() && *it < element)
        ++it;
    deq.insert(it, element);
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
        if (vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
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
        if (deq[i] > deq[i + 1])
            std::swap(deq[i], deq[i + 1]);
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
