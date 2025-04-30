
template <class Container>
MyList<Container>::MyList()
{
    internal_list_size = 0;
    internal_list_head = NULL;
}

template <class Container>
MyList<Container>::MyList(int argc, char **argv) {
    internal_list_head = new Node<Container>;
    internal_list_head->cont.resize(argc - 1);
    internal_list_head->prev = NULL;
    internal_list_head->next = NULL;
    internal_list_head->idx = 0;

    for (int i = 0; i < argc - 1; ++i)
        internal_list_head->cont[i] = std::atoi(argv[i + 1]);

    internal_list_size = 1;
}

template <class Container>
MyList<Container>::~MyList()
{
    clear();
}

template <class Container>
MyList<Container>& MyList<Container>::operator=(const MyList<Container>& other) {
    if (this != &other) {
        clear();
        if (!other.internal_list_head) {
            internal_list_head = NULL;
            internal_list_size = 0;
            return *this;
        }
        internal_list_head = new Node<Container>(*other.internal_list_head);
        internal_list_head->prev = NULL;
        internal_list_head->next = NULL;
        internal_list_head->idx = 0;
        internal_list_size = 1;
        // If you later support multiple nodes, copy them here
    }
    return *this;
}

template <class Container>
void MyList<Container>::clear() {
    Node<Container>* current = internal_list_head;
    while (current) {
        Node<Container>* next = current->next;
        delete current;
        current = next;
    }
    internal_list_head = NULL;
    internal_list_size = 0;
}

template <class Container>
Container& MyList<Container>::operator[](int index) {
    Node<Container> *cur = internal_list_head;
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
void MyList<Container>::setup_next_depth() {
    int sm_size = get_smallest_cont_size();
    int next_cont_size = (sm_size / 2);
    old_size = internal_list_size;
    while (internal_list_size < (old_size * 2))
    {
        attach_new_node(next_cont_size);
    }
}

template <class Container>
void MyList<Container>::eliminate_empty_nodes() {
    Node<Container> *cur = internal_list_head;
    Node<Container> *empty;
    Node<Container> *before;
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
                internal_list_head = cur;
                first = false;
            }
            cur = cur->next;
        }
    }
    if (first == true)
        internal_list_head = NULL;
    size(); //updates list size and indexes
}



template <class Container>
void MyList<Container>::attach_new_node(int cont_size)
{
    Node<Container> *to_add = new Node<Container>;
    Node<Container> *cur = internal_list_head;
    while (cur && cur->next)
        cur = cur->next;
    cur->next = to_add;
    to_add->next = NULL;
    to_add->prev = cur;
    to_add->cont.resize(cont_size);
    to_add->idx = internal_list_size;
    internal_list_size++;
}

//updates internal__list_size variable. reindexes all nodes in the chain.
template <class Container>
int MyList<Container>::size()
{
    internal_list_size = 0;
    Node<Container> *cur = internal_list_head;
    if (cur == NULL)
        return (-1);
    while (cur)
    {
        cur->idx = internal_list_size;
        internal_list_size++;
        cur = cur->next;
    }
    return (internal_list_size);
}

template <class Container>
int MyList<Container>::get_smallest_cont_size()
{
    Node<Container> *cur = internal_list_head;
    if (cur == NULL)
        return (-1);
    while (cur && cur->next)
        cur = cur->next;
    return (cur->cont.size());
}

template <class Container>
void MyList<Container>::print_content(int index)
{
    Node<Container> *cur = internal_list_head;
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