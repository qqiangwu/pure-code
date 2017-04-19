# What's this?
This is a project aimed to be a text-book implementation of common data structures and algorithms. It provides both demo implementation and unit tests.

# Principles
The code is intended to be **clean** and **simple**, and efficiency is not the principal goal. I will write the most efficient implementation in terms of computation complexity or provide implementation of different versions.

Code example:

```cpp
template <class Iter>
void linearInsert(Iter insertionPos, Iter p)
{
    std::rotate(insertionPos, p, p + 1);
}

template <class Iter>
void insertionSort(Iter first, Iter last)
{
    // [begin, p) sorted
    // [p, end) to be processed
    for (auto p = first; p != last; ++p) {
        auto insertionPoint = std::upper_bound(first, p, *p);

        // insert p to [insertionPoint, p)
        linearInsert(insertionPoint, p);
    }
}
```

# Usage
If you want to practice your coding skills, simply download the project and rewrite relevant algorithms and run unit tests yourself.

When you are implementing an algorithm which requires other algorithms or data structures, you can simply use existing implementation in the standard library or in the repo and concentrate on the main ideas, for example:

```c++
template <class Iter>
void quickSort(Iter first, Iter last)
{
    if (last - first <= 1) {
        return;
    }

    auto partitionPoint = partition(first, last);

    quickSort(first, partitionPoint);
    quickSort(partitionPoint, last);
}
```

In the above example, `partition` (implemented in the repo) is guaranteed to return two non-empty ranges if the length of the input range if larger than one such that we are ensured that both the following recursion calls will occur on smaller dimensions.

# Todo
You're welcomed to contribute to this project by either:

+ Providing more typical unit tests or corner cases
+ Reporting implementation bugs