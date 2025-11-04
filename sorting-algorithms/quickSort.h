#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "printVec.h"

template<typename Comparable>
void quickSortUnstableRec(vector<Comparable> &vec, int startIndex, int endIndex, Comparable& partition, int& i, int& largerElementIndex, Comparable& temp, unsigned long& reads, unsigned long& allocations) {
    // Recursive base case
    if (startIndex >= endIndex) {
        return;
    }

    // Choose a partition element
    partition = vec[startIndex]; reads+= 1;

    // Loop through vec from startIndex to endIndex
    // Keep track of where the > partition elements start
    largerElementIndex = startIndex+1;
    for (i = startIndex+1; i <= endIndex; ++i) {
        reads += 1;
        if (vec[i] <= partition) {
            // Swap the smaller/equal item to the left of the larger items
            temp = vec[i]; reads += 1;
            vec[i] = vec[largerElementIndex]; reads += 1;
            vec[largerElementIndex] = temp;
            // Update largerElementIndex
            ++largerElementIndex;
        }
    }
    // Swap the partition element into place
    if (startIndex != largerElementIndex-1) {
        temp = vec[startIndex]; reads += 1;
        vec[startIndex] = vec[largerElementIndex - 1]; reads += 1;
        vec[largerElementIndex - 1] = temp;
    }

    // Recursive calls for two halves
    quickSortUnstableRec(vec, startIndex, largerElementIndex-2, partition, i, largerElementIndex, temp,reads, allocations);
    quickSortUnstableRec(vec, largerElementIndex, endIndex, partition, i, largerElementIndex, temp,reads, allocations);
}

template<typename Comparable>
vector<Comparable> quickSortUnstable(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    Comparable partition, temp;
    int i, largerElementIndex;
    allocations += sizeof(partition) + sizeof(temp) + sizeof(i) + sizeof(largerElementIndex);
    quickSortUnstableRec(vec, 0, vec.size() - 1, partition, i, largerElementIndex, temp, reads, allocations);
    cout << "Quick (unstable): Allocations: " << allocations << ", Reads: " << reads << endl;
    return vec;
}

template<typename Comparable>
void quickSortStableRec(vector<Comparable> &vec, unsigned long& reads, unsigned long& allocations, Comparable& partition, int& i) {
    // Recursive base case
    if (vec.size() <= 1) {
        return;
    }

    // Choose a partition element
    partition = vec[0];

    vector<Comparable> smaller, equal, larger;
    // Loop through vec and populate smaller, equal, larger
    for (i = 0; i < vec.size(); ++i) {
        if (vec[i] < partition) {
            smaller.push_back(vec[i]);
        } else if (vec[i] > partition) {
            larger.push_back(vec[i]);
        } else {
            equal.push_back(vec[i]);
        }
    }

    // Recursive calls
    quickSortStableRec(smaller, reads, allocations, partition, i);
    quickSortStableRec(larger, reads, allocations, partition, i);

    // Copy elements from smaller, equal, and larger back into vec
    for (i = 0; i < vec.size(); ++i) {
        if (i < smaller.size()) {
            vec[i] = smaller[i];
        } else if (i < smaller.size() + equal.size()) {
            vec[i] = equal[i - smaller.size()];
        } else {
            vec[i] = larger[i - smaller.size() - equal.size()];
        }
    }
}

template<typename Comparable>
vector<Comparable> quickSortStable(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    Comparable partition;
    int i;
    quickSortStableRec(vec, reads, allocations, partition, i);
    return vec;
}

#endif
