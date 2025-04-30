
template <class Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv) {
    sequence.resize(argc);
    do_sort(argc, argv);
}

template <class Container>
PmergeMe<Container>::~PmergeMe(void) {}

template <class Container>
void PmergeMe<Container>::do_sort(int argc, char **argv) {
    calculate_depth(argc);
    cont_chain = MyList<Container>(argc, argv);  // direct construction
    bottom = recursion_levels * (-2);
    breakpoint = recursion_levels * (-1);
    assemble();
}

template <class Container>
int PmergeMe<Container>::calculate_depth(int argc) {
    recursion_levels = 0;
    argc--;
    while (argc > 1)
    {
        argc /= 2;
        recursion_levels++;
    }
    cur_containers = 1;
    prev_containers = 0;
    depth = 0;
    seq_max = -1;
    comp = 0;
    return (recursion_levels);
}

template <class Container>
int PmergeMe<Container>::my_pair(int my_num)
{
    if (prev_containers + my_num >= cur_containers)
        return (-1);
    return (prev_containers + my_num);
}


template <class Container>
int PmergeMe<Container>::my_pair_up(int my_num, int diff)
{
    if (diff == 0)
    {
        if (prev_containers + my_num >= cur_containers
            || prev_containers + my_num == my_num)
            return (-1);
        return (prev_containers + my_num);
    }
    if ((prev_containers / 4) + my_num >= cur_containers
        || (prev_containers / 4) + my_num == my_num)
        return (-1);
    return ((prev_containers / 4) + my_num);
}

template <class Container>
void PmergeMe<Container>::reassess_size()
{
    prev_containers = cur_containers;
    cur_containers = cont_chain.size();
}

template <class Container>
void PmergeMe<Container>::create_sequence(Container& cont, Container& pair)
{

    int idx = 0;
    int max_idx = cont.size() - 1;
    int ctr = 0;
    og_size = max_idx;

    pair.resize(max_idx + 1);
    sequence.clear();
    sequence.resize(max_idx + 1);
    while (idx < max_idx)
    {
        
        comp++;
        if (cont[idx] < cont[idx + 1])
        {
            pair[ctr] = cont[idx];
            sequence[ctr] = idx;
            cont[idx] = DUMMY_VAL;
        }
        else
        {
            pair[ctr] = cont[idx + 1];
            sequence[ctr] = idx + 1;
            cont[idx + 1]  = DUMMY_VAL;
        }
        idx += 2;
        ctr++;
    }
    if (idx == max_idx) //we had uneven numbers
    {
        pair[ctr] = cont[idx];
        sequence[ctr] = idx;
        cont[idx] = DUMMY_VAL;
        ctr++;
    }
    pair.resize(ctr);
    sequence.resize(ctr);
    seq_max = ctr;
    clear_dummy_vals(cont);
}

template <class Container>
void PmergeMe<Container>::clear_dummy_vals(Container& cont)
{
    typename Container::iterator cur = cont.begin();
    while (cur != cont.end())
    {
        if (*cur == DUMMY_VAL)
            cur = cont.erase(cur);
        else
            cur++;
    }
}

template <class Container>
void PmergeMe<Container>::follow_sequence(Container& cont, Container& pair)
{
    int idx = 0;
    int max_idx = cont.size() - 1;
    int ctr = 0;

    pair.resize(seq_max);
    while (idx <= max_idx)
    {
        if (ctr < seq_max && idx == sequence[ctr])
        {
            pair[ctr] = cont[idx];
            cont[idx] = DUMMY_VAL;
            ctr++;
        }
        else if (idx > og_size)
        {
            pair.push_back(cont[idx]);
            cont[idx] = DUMMY_VAL;
        }
        idx++;
    }
    clear_dummy_vals(cont);
}

template <class Container>
void PmergeMe<Container>::take_apart()
{
    depth--;
    if (depth > bottom)
        take_apart();

    cont_chain.setup_next_depth();
    reassess_size(); //needed for calc of my_pair

    create_sequence(cont_chain[0], cont_chain[my_pair(0)]);
    int my_num = 1;
    while (my_pair(my_num) != -1)
    {
        follow_sequence(cont_chain[my_num], cont_chain[my_pair(my_num)]);
        my_num++;
    }

    if (my_num == 1) //no "follow" happened
        sequence.clear();
    depth++;

    return ;
}

template <class Container>
typename Container::iterator PmergeMe<Container>::recalc_bounds(Container& from, int jacob_index)
{
    typename Container::iterator target;
    int res = 0;
    
    last_bound = from.begin() + (pow(2, jacob_index) + pow(-1, (jacob_index - 1))) / 3;
    if (last_bound >= from.end())
		throw std::logic_error("Iterator out of valid range (last_bound >= end).");
    target = last_bound - 1;
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
typename Container::iterator PmergeMe<Container>::calc_last(Container& cont, int idx)
{
    typename Container::iterator res = cont.begin();
    res += lookup.pairIndex(idx);
    return (res);
}

template <class Container>
void PmergeMe<Container>::merge_containers(Container& from, Container& to)
{
    inserted.clear();
    lookup.initialize(from.size());

    last_bound = from.begin();
    typename Container::iterator target = from.begin();
    typename Container::iterator first = to.begin();
    typename Container::iterator last = calc_last(to, target - from.begin());
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
            comp++;
        if (*mid == *target)
        {
            store.first = target - from.begin(); //save target index
            store.second = mid - to.begin(); //save insert pos
            lookup.adjustPositions(mid - to.begin());
            to.insert(mid, *target);
            inserted.push_back(store);
            goto insertion_done;
        }
        else if (*mid > *target)
            last = mid - 1;
        else
            first = mid + 1;
    }
    store.first = target - from.begin(); //save target index
    store.second = first - to.begin(); //save insert pos
    lookup.adjustPositions(first - to.begin());
    to.insert(first, *target);
    inserted.push_back(store);
    
    insertion_done:

    if (--target >= last_bound)
    {
        first = to.begin();
        last = calc_last(to, target - from.begin());
    }
    else
    {
        try
        {
            jacob_index++;
            target = recalc_bounds(from, jacob_index);
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
void PmergeMe<Container>::copy_merge(Container& from, Container& to)
{
    size_t idx = 0;

    while (idx < inserted.size())
    {
        to.insert(to.begin() + inserted[idx].second, from[inserted[idx].first]);
        from[inserted[idx].first] = DUMMY_VAL;
        idx++;
    }
    clear_dummy_vals(from);
    typename Container::iterator target = from.begin();
    while (target < from.end())
    {
        to.push_back(*target);
        target++;
    }
    from.clear();
}

template <class Container>
void PmergeMe<Container>::assemble()
{
    depth--;
    if (depth > breakpoint)
        assemble();
    else if (depth <= breakpoint)
        take_apart();

    int diff = depth - breakpoint;
    merge_containers(cont_chain[my_pair_up(0, diff)], cont_chain[0]);
    int my_num = 1;
    while (my_pair_up(my_num, diff) != -1)
    {
        copy_merge(cont_chain[my_pair_up(my_num, diff)], cont_chain[my_num]);
        my_num++;
    }

    depth++;
    cont_chain.eliminate_empty_nodes();
    reassess_size();
    
    return ;
}

template <typename Container>
void PmergeMe<Container>::print_content() {
    cont_chain.print_content(0); // or your preferred index
}
