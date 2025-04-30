#include "PairKeeper.hpp"
#include "PmergeMe.hpp"

bool g_errorPrimed = false;

PairKeeper::PairKeeper(void) {}
PairKeeper::~PairKeeper(void) {}

// Initializes the PairKeeper with a given size, clearing and resizing internal containers.
void PairKeeper::initialize(int size) {
    int pos = 0;

    // Clear and resize the containers: indexes and dummy_cont.
    // Resize both containers to the size provided in the argument.
    indexes.clear();                 // Clear any previous data in indexes
    indexes.resize(size);            // Resize indexes to hold 'size' elements
    dummy_cont.resize(size);         // Resize dummy_cont to hold 'size' elements

    // Initialize the containers with default values
    while (pos < size) {
        indexes[pos] = pos;          // Set the index at position 'pos' to be 'pos'
        dummy_cont[pos] = pos;       // Set the dummy container value at 'pos' to be 'pos'
        ++pos;                       // Move to the next position
    }

    // Set the 'max' and 'dummy_max' to the last index of the containers
    max = dummy_max = size - 1;      // Both max and dummy_max point to the last index (size - 1)
}

// Returns the paired index for the given index 'idx'. Throws an error if the index is out of range.
int PairKeeper::pairIndex(int idx) {
    // Check if the index is within the valid range.
    if (idx < 0 || idx > max || idx >= static_cast<int>(indexes.size())) {
        g_errorPrimed = true;  // Set the error flag
        // Throw an exception if index is out of range
        throw std::out_of_range("Index out of valid range in pairIndex()");
    }

    // Return the index from the 'indexes' container at the provided index
    return indexes[idx];
}

void PairKeeper::adjustPositions(int inserted_at) {
    int actual_idx = 0;
    int iternums = 0;

    // Early exit if inserted_at is beyond the max value (no need to adjust)
    if (inserted_at > dummy_max)
        return;
    
    // Increase the max index
    dummy_max++;

    // Start the iterator from the beginning of dummy_cont
    std::deque<long int>::iterator iter = dummy_cont.begin();

    // Move the iterator to the correct insertion position
    while (iternums < inserted_at) {
        if (*iter != DUMMY_VAL)
            actual_idx++; // Update actual index if not DUMMY_VAL
        iternums++;
        ++iter;
    }

    // Insert the DUMMY_VAL at the correct position
    dummy_cont.insert(iter, DUMMY_VAL);
    
    // After insertion, update the iterator and increment elements if necessary
    iter = dummy_cont.begin() + iternums;
    
    while (iter != dummy_cont.end()) {
        if (*iter < DUMMY_VAL)
            (*iter)++;  // Increment value if it is not DUMMY_VAL
        ++iter;
    }

    // Now adjust indexes after the insertion
    while (actual_idx <= max) {
        indexes[actual_idx]++;  // Increment index if necessary
        actual_idx++;
    }
}

void PairKeeper::print_content(char flag) {
    std::deque<long int>::iterator cur; 
    if (flag == 'D')
    {
        cur = dummy_cont.begin();
        while (cur != dummy_cont.end())
        {
            std::cout << *cur << " ";
            if (*cur < 10)
                std::cout << " ";
            cur++;
        }
    }
    else
    {
        cur = indexes.begin();
        while (cur != indexes.end())
        {
            std::cout << *cur << " ";
            if (*cur < 10)
                std::cout << " ";
            cur++;
        }
    }
    std::cout << std::endl;
}
