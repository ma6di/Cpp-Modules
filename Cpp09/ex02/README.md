
# 🧩 PmergeMe: Ford-Johnson Merge-Insertion Sort in C++98

This project implements the **Ford-Johnson algorithm**, also known as the **Merge-Insertion Sort**, using a template-based approach in C++98.

> 📌 This sort is one of the few known sorting algorithms that can approach the theoretical lower bound of comparisons (`log₂(n!)`) for comparison-based sorting.

---

## 🚀 Features

* Fully generic: works with any STL-compatible container (`std::vector`, `std::deque`, etc.)
* Compares and sorts elements using **minimal comparisons**
* Recursively builds a main sorted chain and then inserts remaining elements using **Jacobsthal-based insertion order**
* Tracks the number of comparisons and recursion levels
* Includes detailed debugging output (enabled by removing `#define NDEBUG`)

---

## 🧠 Algorithm Overview

The **Ford-Johnson algorithm** proceeds in three phases:

1. **Pairing**:

   * Adjacent elements are grouped into pairs.
   * Each pair is sorted, and the **larger element** goes into list `A` (main chain), while the **smaller element** goes into list `B` (pending insertions).

2. **Recursive Sort**:

   * The list `A` is recursively sorted using the same method.

3. **Insertion Phase**:

   * Elements from `B` are inserted into the sorted `A` chain using a calculated **upper bound** for each, minimizing comparisons.
   * The order of insertions is guided by **Jacobsthal numbers** to further optimize efficiency.

---

## 🔍 Key Concepts

### 1. **Pairing & Companion Indexing**

In `recursiveSort()`:

```cpp
for (size_t i = 0; i + 1 < n; i += 2) {
    value_type x = data[i], y = data[i + 1];
    if (y < x) std::swap(x, y);
    aList.push_back(y);         // larger
    pendings.push_back(x);      // smaller
}
```

* Pairs are created from adjacent elements.
* `aList` becomes the **main chain** to sort.
* `pendings` are remembered for later insertion.
* Each element in `pendings` keeps track of the **companion index** in `mainChain` to guide where it can be safely inserted.

```cpp
compIdx[i] = std::lower_bound(mainChain.begin(), mainChain.end(), aList[i]) - mainChain.begin();
```

This means `pendings[i]` must be inserted **before or at** this index.

---

### 2. **Jacobsthal Numbers and Insertion Order**

The Jacobsthal sequence:

```
J(n) = J(n−1) + 2 * J(n−2),  with J(0) = 0, J(1) = 1
```

Used in `generateJacobsthalInsertionOrder()`:

```cpp
std::vector<size_t> J;
J.push_back(0); J.push_back(1);
while (true) {
    size_t next = J.back() + 2 * J[J.size() - 2];
    if (next >= n) break;
    J.push_back(next);
}
```

These numbers determine the **optimal insertion order** to reduce comparisons:

```cpp
for (size_t k = 2; k < J.size(); ++k) {
    for (size_t idx = J[k]; idx >= J[k-1] + 1; --idx)
        order.push_back(idx);
}
```

📈 The Jacobsthal sequence is a critical optimization technique for minimizing the number of comparisons during insertions.

---

### 3. **Bounded Insertion**

Elements from `pendings` are inserted using **binary search** within a limited range (`[0, companionIndex]`):

```cpp
insertBounded(mainChain, pendings[i], compIdx[i]);
```

```cpp
while (left < right) {
    typename Container::iterator mid = left + (right - left) / 2;
    if (v < *mid) right = mid;
    else left = mid + 1;
}
```

---

## 🛠️ Key Methods Explained

| Method                               | Description                                                      |
| ------------------------------------ | ---------------------------------------------------------------- |
| `mergeInsertSort()`                  | Entry point: starts the recursive sort                           |
| `recursiveSort()`                    | Handles pairing, recursive call, and Jacobsthal-guided insertion |
| `insertBounded()`                    | Performs bounded binary insertion                                |
| `generateJacobsthalInsertionOrder()` | Returns optimal index order for insertion phase                  |
| `countRecursionLevels()`             | Utility to track depth for debugging                             |
| `parseInput()`                       | Validates CLI arguments and populates container                  |

---

## 🧪 Debug Mode

You'll get logs like:

```
Recursion level 2
Original Pairs: (3 8), (1 4), (2 5)
A list (Main Chain): 4 5 8
B list (Pending): 1 2 3
B List companion index of A list: 0 1 2
Jacobsthal insertion order: 0 1 2
```

---

## 📦 Usage

### Compile

```bash
make
```

### To enable debug mode (step-by-step output):

```bash
make MODE=debug
```

### Run

```bash
./PmergMe 5 2 8 3 1 4
```

---

