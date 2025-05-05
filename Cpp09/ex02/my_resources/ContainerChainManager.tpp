
template <class Container>
ContainerChainManager<Container>::ContainerChainManager()
{
    chainLength = 0;
    containerChainHead = NULL;
}

template <class Container>
ContainerChainManager<Container>::ContainerChainManager(int argc, char **argv) {
    containerChainHead = new ContainerNode<Container>;
    containerChainHead->cont.resize(argc - 1);
    containerChainHead->prev = NULL;
    containerChainHead->next = NULL;
    containerChainHead->idx = 0;

    for (int i = 0; i < argc - 1; ++i)
        containerChainHead->cont[i] = std::atoi(argv[i + 1]);

    chainLength = 1;
}

template <class Container>
ContainerChainManager<Container>::~ContainerChainManager()
{
    clear();
}

template <class Container>
ContainerChainManager<Container>& ContainerChainManager<Container>::operator=(const ContainerChainManager<Container>& other) {
    if (this != &other) {
        clear();
        if (!other.containerChainHead) {
            containerChainHead = NULL;
            chainLength = 0;
            return *this;
        }
        containerChainHead = new ContainerNode<Container>(*other.containerChainHead);
        containerChainHead->prev = NULL;
        containerChainHead->next = NULL;
        containerChainHead->idx = 0;
        chainLength = 1;
        // If you later support multiple nodes, copy them here
    }
    return *this;
}

template <class Container>
void ContainerChainManager<Container>::clear() {
    ContainerNode<Container>* current = containerChainHead;
    while (current) {
        ContainerNode<Container>* next = current->next;
        delete current;
        current = next;
    }
    containerChainHead = NULL;
    chainLength = 0;
}

template <class Container>
Container& ContainerChainManager<Container>::operator[](int index) {
    ContainerNode<Container> *cur = containerChainHead;
    if (!cur)
        throw std::out_of_range("Accessing element in an empty list");

    int idx = 0;
    while (cur && idx != index)
    {
        cur = cur->next;
        idx++;
    }
    if (idx < index || cur == NULL)
        throw std::out_of_range("Index out of bounds");
    return cur->cont;
}

template <class Container>
void ContainerChainManager<Container>::createNextRecursionLevel() {
    int sm_size = findMinimumContainerSize();
    int next_cont_size = (sm_size / 2);
    old_size = chainLength;
    while (chainLength < (old_size * 2))
    {
        appendContainerNode(next_cont_size);
    }
}

template <class Container>
void ContainerChainManager<Container>::pruneEmptyNodes() {
    ContainerNode<Container> *cur = containerChainHead;
    ContainerNode<Container> *empty;
    ContainerNode<Container> *before;
    bool first = true;
    while (cur)
    {
        if (cur->cont.empty())
        {
            empty = cur;
            before = cur->prev;
            cur = cur->next;
            delete empty;
            if (before)
                before->next = cur;
            if (cur)
                cur->prev = before;
        }
        else
        {
            if (first == true)
            {
                containerChainHead = cur;
                first = false;
            }
            cur = cur->next;
        }
    }
    if (first == true)
        containerChainHead = NULL;
    size(); //updates list size and indexes
}



template <class Container>
void ContainerChainManager<Container>::appendContainerNode(int cont_size)
{
    ContainerNode<Container> *to_add = new ContainerNode<Container>;
    ContainerNode<Container> *cur = containerChainHead;
    while (cur && cur->next)
        cur = cur->next;
    cur->next = to_add;
    to_add->next = NULL;
    to_add->prev = cur;
    to_add->cont.resize(cont_size);
    to_add->idx = chainLength;
    chainLength++;
}

//updates internal__list_size variable. reindexes all nodes in the chain.
template <class Container>
int ContainerChainManager<Container>::size()
{
    chainLength = 0;
    ContainerNode<Container> *cur = containerChainHead;
    if (cur == NULL)
        return (-1);
    while (cur)
    {
        cur->idx = chainLength;
        chainLength++;
        cur = cur->next;
    }
    return (chainLength);
}

template <class Container>
int ContainerChainManager<Container>::findMinimumContainerSize()
{
    ContainerNode<Container> *cur = containerChainHead;
    if (cur == NULL)
        return (-1);
    while (cur && cur->next)
        cur = cur->next;
    return (cur->cont.size());
}

template <class Container>
void ContainerChainManager<Container>::print_content(int index)
{
    ContainerNode<Container> *cur = containerChainHead;
    while (cur && cur->idx != index)
        cur = cur->next;
    if (!cur)
    {
        std::cout << "no content for index " << index << std::endl;
        return ;
    }
    typename Container::iterator iter = cur->cont.begin();
    while (iter != cur->cont.end())
    {
        std::cout << *iter << " ";
        iter++;
    }
    std::cout << std::endl;
}