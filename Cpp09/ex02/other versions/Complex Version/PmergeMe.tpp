
template <class Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv) {
    sequence.resize(argc);
    performMergeInsertSort(argc, argv);
}

template <class Container>
PmergeMe<Container>::~PmergeMe(void) {}

template <class Container>
void PmergeMe<Container>::performMergeInsertSort(int argc, char **argv) {
    calculateRecursionDepth(argc);
    containerChain = ContainerChainManager<Container>(argc, argv);  // direct construction
    minRecursionLevel = maxRecursionDepth * (-2);
    recursionBreakpoint = maxRecursionDepth * (-1);
    mergeSortedPairs();
}

template <class Container>
int PmergeMe<Container>::calculateRecursionDepth(int argc) {
    maxRecursionDepth = 0;
    argc--;
    while (argc > 1)
    {
        argc /= 2;
        maxRecursionDepth++;
    }
    currentContainerCount = 1;
    previousContainerCount = 0;
    depth = 0;
    maxSequenceLength = -1;
    comparisonCount = 0;
    return (maxRecursionDepth);
}

template <class Container>
int PmergeMe<Container>::findPairIndex(int my_num)
{
    if (previousContainerCount + my_num >= currentContainerCount)
        return (-1);
    return (previousContainerCount + my_num);
}


template <class Container>
int PmergeMe<Container>::findUpperPairIndex(int my_num, int diff)
{
    if (diff == 0)
    {
        if (previousContainerCount + my_num >= currentContainerCount
            || previousContainerCount + my_num == my_num)
            return (-1);
        return (previousContainerCount + my_num);
    }
    if ((previousContainerCount / 4) + my_num >= currentContainerCount
        || (previousContainerCount / 4) + my_num == my_num)
        return (-1);
    return ((previousContainerCount / 4) + my_num);
}

template <class Container>
void PmergeMe<Container>::updateContainerMetrics()
{
    previousContainerCount = currentContainerCount;
    currentContainerCount = containerChain.size();
}

template <class Container>
void PmergeMe<Container>::generateInsertionOrder(Container& cont, Container& pair)
{

    int idx = 0;
    int max_idx = cont.size() - 1;
    int ctr = 0;
    originalSize = max_idx;

    pair.resize(max_idx + 1);
    sequence.clear();
    sequence.resize(max_idx + 1);
    while (idx < max_idx)
    {
        
        comparisonCount++;
        if (cont[idx] < cont[idx + 1])
        {
            pair[ctr] = cont[idx];
            sequence[ctr] = idx;
            cont[idx] = INVALID_MARKER;
        }
        else
        {
            pair[ctr] = cont[idx + 1];
            sequence[ctr] = idx + 1;
            cont[idx + 1]  = INVALID_MARKER;
        }
        idx += 2;
        ctr++;
    }
    if (idx == max_idx) //we had uneven numbers
    {
        pair[ctr] = cont[idx];
        sequence[ctr] = idx;
        cont[idx] = INVALID_MARKER;
        ctr++;
    }
    pair.resize(ctr);
    sequence.resize(ctr);
    maxSequenceLength = ctr;
    removeSentinelMarkers(cont);
}

template <class Container>
void PmergeMe<Container>::removeSentinelMarkers(Container& cont)
{
    typename Container::iterator cur = cont.begin();
    while (cur != cont.end())
    {
        if (*cur == INVALID_MARKER)
            cur = cont.erase(cur);
        else
            cur++;
    }
}

template <class Container>
void PmergeMe<Container>::applyInsertionOrder(Container& cont, Container& pair)
{
    int idx = 0;
    int max_idx = cont.size() - 1;
    int ctr = 0;

    pair.resize(maxSequenceLength);
    while (idx <= max_idx)
    {
        if (ctr < maxSequenceLength && idx == sequence[ctr])
        {
            pair[ctr] = cont[idx];
            cont[idx] = INVALID_MARKER;
            ctr++;
        }
        else if (idx > originalSize)
        {
            pair.push_back(cont[idx]);
            cont[idx] = INVALID_MARKER;
        }
        idx++;
    }
    removeSentinelMarkers(cont);
}

template <class Container>
void PmergeMe<Container>::splitIntoPairs()
{
    depth--;
    if (depth > minRecursionLevel)
        splitIntoPairs();

    containerChain.createNextRecursionLevel();
    updateContainerMetrics(); //needed for calc of findPairIndex

    generateInsertionOrder(containerChain[0], containerChain[findPairIndex(0)]);
    int my_num = 1;
    while (findPairIndex(my_num) != -1)
    {
        applyInsertionOrder(containerChain[my_num], containerChain[findPairIndex(my_num)]);
        my_num++;
    }

    if (my_num == 1) //no "follow" happened
        sequence.clear();
    depth++;

    return ;
}

template <class Container>
typename Container::iterator PmergeMe<Container>::calculateInsertionBoundary(Container& from, int jacob_index)
{
    typename Container::iterator target;
    int res = 0;
    
    lastInsertionBoundary = from.begin() + (pow(2, jacob_index) + pow(-1, (jacob_index - 1))) / 3;
    if (lastInsertionBoundary >= from.end())
		throw std::logic_error("Iterator out of valid range (lastInsertionBoundary >= end).");
    target = lastInsertionBoundary - 1;
    res = ((pow(2, jacob_index + 1) + pow(-1, jacob_index)) / 3);
    if (res < 0 || (unsigned long)res > from.size())
        res = from.size();
    target = from.begin() + res - 1;
    if (target > from.end() - 1)
        target = from.end() - 1;
    return (target);
}
// target = from.begin() + ((pow(2, jacob_index + 1) + pow(-1, jacob_index)) / 3) - 1;

template <class Container>
typename Container::iterator PmergeMe<Container>::findLastInsertionPoint(Container& cont, int idx)
{
    typename Container::iterator res = cont.begin();
    res += lookup.getInsertionIndex(idx);
    return (res);
}

template <class Container>
void PmergeMe<Container>::mergeSortedContainers(Container& from, Container& to)
{
    insertionHistory.clear();
    lookup.initialize(from.size());

    lastInsertionBoundary = from.begin();
    typename Container::iterator target = from.begin();
    typename Container::iterator first = to.begin();
    typename Container::iterator last = findLastInsertionPoint(to, target - from.begin());
    typename Container::iterator mid;
    typename Container::iterator pair;
    int jacob_index = 1;
    std::pair<int, int> store;

    merge_next:

    if (last == to.end())
        last--;
    pair = last;
    while (first <= last)
    {
        mid = first + ((last - first) / 2);
        if (mid != pair)
            comparisonCount++;
        if (*mid == *target)
        {
            store.first = target - from.begin(); //save target index
            store.second = mid - to.begin(); //save insert pos
            lookup.updateInsertionPositions(mid - to.begin());
            to.insert(mid, *target);
            insertionHistory.push_back(store);
            goto insertion_done;
        }
        else if (*mid > *target)
            last = mid - 1;
        else
            first = mid + 1;
    }
    store.first = target - from.begin(); //save target index
    store.second = first - to.begin(); //save insert pos
    lookup.updateInsertionPositions(first - to.begin());
    to.insert(first, *target);
    insertionHistory.push_back(store);
    
    insertion_done:

    if (--target >= lastInsertionBoundary)
    {
        first = to.begin();
        last = findLastInsertionPoint(to, target - from.begin());
    }
    else
    {
        try
        {
            jacob_index++;
            target = calculateInsertionBoundary(from, jacob_index);
            target++;
            goto insertion_done;
        }
        catch (const std::logic_error& e)
        {
            from.clear();
            return ;
        }
    }
    goto merge_next;
}

template <class Container>
void PmergeMe<Container>::mergeWithCopyOperation(Container& from, Container& to)
{
    size_t idx = 0;

    while (idx < insertionHistory.size())
    {
        to.insert(to.begin() + insertionHistory[idx].second, from[insertionHistory[idx].first]);
        from[insertionHistory[idx].first] = INVALID_MARKER;
        idx++;
    }
    removeSentinelMarkers(from);
    typename Container::iterator target = from.begin();
    while (target < from.end())
    {
        to.push_back(*target);
        target++;
    }
    from.clear();
}

template <class Container>
void PmergeMe<Container>::mergeSortedPairs()
{
    depth--;
    if (depth > recursionBreakpoint)
        mergeSortedPairs();
    else if (depth <= recursionBreakpoint)
        splitIntoPairs();

    int diff = depth - recursionBreakpoint;
    mergeSortedContainers(containerChain[findUpperPairIndex(0, diff)], containerChain[0]);
    int my_num = 1;
    while (findUpperPairIndex(my_num, diff) != -1)
    {
        mergeWithCopyOperation(containerChain[findUpperPairIndex(my_num, diff)], containerChain[my_num]);
        my_num++;
    }

    depth++;
    containerChain.pruneEmptyNodes();
    updateContainerMetrics();
    
    return ;
}

template <typename Container>
void PmergeMe<Container>::print_content() {
    containerChain.print_content(0); // or your preferred index
}
