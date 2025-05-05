#pragma once

#include <deque>
#define INVALID_MARKER 2147483650

class InsertionIndexTracker
{
    public:

        InsertionIndexTracker(void);
        ~InsertionIndexTracker(void);

        void    initialize(int size);
        int     getInsertionIndex(int idx);
        void    updateInsertionPositions(int insertionHistory_at);
    
    private:

        InsertionIndexTracker(const InsertionIndexTracker& other);
        InsertionIndexTracker& operator=(const InsertionIndexTracker& other);
        void print_content(char flag);

        std::deque<long int> insertionIndices;
        std::deque<long int> temporaryStorage;
        int max;
        int temporaryStorageSize;
};

