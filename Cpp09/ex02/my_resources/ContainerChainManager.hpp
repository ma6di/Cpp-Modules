#pragma once

#include <iostream>

template <class Container>
struct ContainerNode
{
    Container cont;
    struct ContainerNode *next;
    struct ContainerNode *prev;
    int idx;
};

template <class Container>
class ContainerChainManager
{
public:
    ContainerChainManager();                                   // Default constructor
    ContainerChainManager(int argc, char **argv);              // Init with input
    ContainerChainManager(const ContainerChainManager& other);                // Copy constructor
    ContainerChainManager& operator=(const ContainerChainManager& other);     // Copy assignment
    ~ContainerChainManager();                                  // Destructor

    Container& operator[](int index);           // Access container at index

    void createNextRecursionLevel();                    // Create new depth nodes
    void pruneEmptyNodes();               // Prune empty nodes
    int  size();                                // List size
    void print_content(int index);            

private:
    void initializeFromCommandLine(int argc, char **argv); // Shared initializer
    void appendContainerNode(int cont_size);        // Internal: grow list
    int  findMinimumContainerSize();              // Internal: for recursion
    void clear();                               // Utility for reuse/reset

    int             old_size;
    int             chainLength;
    ContainerNode<Container>* containerChainHead;
};

#include "ContainerChainManager.tpp"
