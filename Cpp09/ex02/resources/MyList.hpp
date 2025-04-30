#pragma once

#include <iostream>

template <class Container>
struct Node
{
    Container cont;
    struct Node *next;
    struct Node *prev;
    int idx;
};

template <class Container>
class MyList
{
public:
    MyList();                                   // Default constructor
    MyList(int argc, char **argv);              // Init with input
    MyList(const MyList& other);                // Copy constructor
    MyList& operator=(const MyList& other);     // Copy assignment
    ~MyList();                                  // Destructor

    Container& operator[](int index);           // Access container at index

    void setup_next_depth();                    // Create new depth nodes
    void eliminate_empty_nodes();               // Prune empty nodes
    int  size();                                // List size
    void print_content(int index);            

private:
    void init_from_args(int argc, char **argv); // Shared initializer
    void attach_new_node(int cont_size);        // Internal: grow list
    int  get_smallest_cont_size();              // Internal: for recursion
    void clear();                               // Utility for reuse/reset

    int             old_size;
    int             internal_list_size;
    Node<Container>* internal_list_head;
};

#include "MyList.tpp"
