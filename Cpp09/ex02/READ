# PmergeMe - Ford-Johnson Merge-Insert Sort Implementation

## Overview
PmergeMe is a C++ implementation of the Ford-Johnson merge-insert sort algorithm, also known as the merge-insertion sort. This algorithm is a hybrid sorting method that combines the efficiency of merge sort with the optimality of insertion sort for small sequences. The implementation is based on the theoretical foundations described in Donald Knuth's "The Art of Computer Programming, Volume 3: Sorting and Searching."

## Algorithm Description

### Ford-Johnson Merge-Insert Sort
The Ford-Johnson algorithm is a theoretically optimal comparison-based sorting algorithm that achieves the minimum number of comparisons possible for sorting n elements. The algorithm works in two main phases:

1. **Pairing Phase**:
   - Elements are paired and compared
   - The larger elements form a sorted sequence
   - The smaller elements are kept track of for later insertion
   - Each comparison yields one element in its final position
   - The remaining elements are stored for the insertion phase

2. **Insertion Phase**:
   - Uses the Jacobsthal sequence to determine optimal insertion order
   - Inserts elements in a specific pattern to minimize comparisons
   - Maintains optimal comparison count through careful insertion tracking
   - Each insertion is performed using binary search for optimal efficiency

### Jacobsthal Sequence
The implementation uses the Jacobsthal sequence to determine the optimal insertion order. The sequence is defined as:
- J(0) = 0
- J(1) = 1
- J(n) = J(n-1) + 2*J(n-2) for n > 1

This sequence helps determine the optimal order for inserting elements to minimize comparisons. The sequence is used to calculate insertion boundaries and optimize the insertion process.

### Theoretical Background
From Knuth's TAOCP Volume 3:
- The algorithm achieves the minimum number of comparisons possible for sorting n elements
- The number of comparisons is given by the formula: ⌈log₂(3n/4)⌉
- The algorithm is optimal for n ≤ 12 elements
- For larger n, it provides a near-optimal solution

## Implementation Details

### Key Components

1. **PmergeMe Class** (`PmergeMe.hpp`, `PmergeMe.tpp`)
   - Main sorting algorithm implementation
   - Handles the merge-insert sort process
   - Manages recursion and container operations
   - Tracks comparison counts for performance analysis
   - Implements the core Ford-Johnson algorithm logic

2. **ContainerChainManager** (`ContainerChainManager.hpp`, `ContainerChainManager.tpp`)
   - Manages the chain of containers used in the sorting process
   - Handles container creation and management
   - Maintains container relationships during recursion
   - Provides container access and manipulation methods
   - Implements efficient memory management through linked list structure

3. **InsertionIndexTracker** (`InsertionIndexTracker.hpp`, `InsertionIndexTracker.cpp`)
   - Tracks insertion positions during the sorting process
   - Manages the insertion history
   - Optimizes insertion order using the Jacobsthal sequence
   - Maintains insertion indices for optimal performance
   - Implements efficient index tracking for binary search operations

### Key Features

1. **Template-Based Implementation**
   - Supports different container types (vector, deque)
   - Flexible and reusable code structure
   - Easy to extend for other container types
   - Maintains type safety through C++ templates

2. **Performance Optimization**
   - Implements optimal comparison count
   - Uses efficient container management
   - Minimizes memory operations
   - Tracks and reports comparison counts
   - Implements binary search for efficient insertions

3. **Error Handling**
   - Robust error detection and reporting
   - Input validation
   - Exception handling for edge cases
   - Memory leak prevention
   - Resource cleanup

## Usage

### Compilation
```bash
make
```

### Running the Program
```bash
./PmergeMe [sequence of positive integers]
```

### Example
```bash
./PmergeMe 3 5 9 7 4
```

## Performance Analysis

The implementation achieves optimal comparison counts as described in Knuth's work. The number of comparisons follows the theoretical minimum:
- For n elements, the optimal number of comparisons is calculated using the formula from TAOCP
- The implementation includes comparison counting for verification
- Performance metrics are reported for both vector and deque containers
- Time complexity analysis shows O(n log n) average case
- Space complexity is O(n) for the main algorithm

### Comparison with Other Algorithms
- More efficient than standard merge sort for small sequences
- Better comparison count than quicksort in worst case
- Optimal for small to medium-sized inputs
- Competitive with other comparison-based sorts

## References

1. Knuth, D. E. (1998). The Art of Computer Programming, Volume 3: Sorting and Searching (2nd ed.). Addison-Wesley Professional.
   - Section 5.3.1: Minimum-Comparison Sorting
   - Section 5.3.2: Merge-Insertion Sort
   - Theorem 5.3.1: Optimality of Ford-Johnson algorithm
   - Table 5.3.1: Comparison counts for small n

2. Ford, L. R., & Johnson, S. M. (1959). A Tournament Problem. The American Mathematical Monthly, 66(5), 387-389.
   - Original paper introducing the algorithm
   - Proof of optimality for small n
   - Analysis of comparison counts
