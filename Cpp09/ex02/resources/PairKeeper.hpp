#pragma once

#include <deque>
#define DUMMY_VAL 2147483650

class PairKeeper
{
    public:

        PairKeeper(void);
        ~PairKeeper(void);

        void    initialize(int size);
        int     pairIndex(int idx);
        void    adjustPositions(int inserted_at);
    
    private:

        PairKeeper(const PairKeeper& other);
        PairKeeper& operator=(const PairKeeper& other);
        void print_content(char flag);

        std::deque<long int> indexes;
        std::deque<long int> dummy_cont;
        int max;
        int dummy_max;
};

