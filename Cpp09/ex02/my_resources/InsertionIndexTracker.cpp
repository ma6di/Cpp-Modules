#include "InsertionIndexTracker.hpp"
#include "PmergeMe.hpp"

bool g_errorDetected = false;

InsertionIndexTracker::InsertionIndexTracker(void) {}
InsertionIndexTracker::~InsertionIndexTracker(void) {}

// Initializes the InsertionIndexTracker with a given size, clearing and resizing internal containers.
void InsertionIndexTracker::initialize(int size) {
    int pos = 0;

    // Clear and resize the containers: insertionIndices and temporaryStorage.
    // Resize both containers to the size provided in the argument.
    insertionIndices.clear();                 // Clear any previous data in insertionIndices
    insertionIndices.resize(size);            // Resize insertionIndices to hold 'size' elements
    temporaryStorage.resize(size);         // Resize temporaryStorage to hold 'size' elements

    // Initialize the containers with default values
    while (pos < size) {
        insertionIndices[pos] = pos;          // Set the index at position 'pos' to be 'pos'
        temporaryStorage[pos] = pos;       // Set the dummy container value at 'pos' to be 'pos'
        ++pos;                       // Move to the next position
    }

    // Set the 'max' and 'temporaryStorageSize' to the last index of the containers
    max = temporaryStorageSize = size - 1;      // Both max and temporaryStorageSize point to the last index (size - 1)
}

// Returns the paired index for the given index 'idx'. Throws an error if the index is out of range.
int InsertionIndexTracker::getInsertionIndex(int idx) {
    // Check if the index is within the valid range.
    if (idx < 0 || idx > max || idx >= static_cast<int>(insertionIndices.size())) {
        g_errorDetected = true;  // Set the error flag
        // Throw an exception if index is out of range
        throw std::out_of_range("Index out of valid range in getInsertionIndex()");
    }

    // Return the index from the 'insertionIndices' container at the provided index
    return insertionIndices[idx];
}

void InsertionIndexTracker::updateInsertionPositions(int insertionHistory_at) {
    int actual_idx = 0;
    int iternums = 0;

    // Early exit if insertionHistory_at is beyond the max value (no need to adjust)
    if (insertionHistory_at > temporaryStorageSize)
        return;
    
    // Increase the max index
    temporaryStorageSize++;

    // Start the iterator from the beginning of temporaryStorage
    std::deque<long int>::iterator iter = temporaryStorage.begin();

    // Move the iterator to the correct insertion position
    while (iternums < insertionHistory_at) {
        if (*iter != INVALID_MARKER)
            actual_idx++; // Update actual index if not INVALID_MARKER
        iternums++;
        ++iter;
    }

    // Insert the INVALID_MARKER at the correct position
    temporaryStorage.insert(iter, INVALID_MARKER);
    
    // After insertion, update the iterator and increment elements if necessary
    iter = temporaryStorage.begin() + iternums;
    
    while (iter != temporaryStorage.end()) {
        if (*iter < INVALID_MARKER)
            (*iter)++;  // Increment value if it is not INVALID_MARKER
        ++iter;
    }

    // Now adjust insertionIndices after the insertion
    while (actual_idx <= max) {
        insertionIndices[actual_idx]++;  // Increment index if necessary
        actual_idx++;
    }
}

void InsertionIndexTracker::print_content(char flag) {
    std::deque<long int>::iterator cur; 
    if (flag == 'D')
    {
        cur = temporaryStorage.begin();
        while (cur != temporaryStorage.end())
        {
            std::cout << *cur << " ";
            if (*cur < 10)
                std::cout << " ";
            cur++;
        }
    }
    else
    {
        cur = insertionIndices.begin();
        while (cur != insertionIndices.end())
        {
            std::cout << *cur << " ";
            if (*cur < 10)
                std::cout << " ";
            cur++;
        }
    }
    std::cout << std::endl;
}
