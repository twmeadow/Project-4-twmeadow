#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H

#include "printVec.h"

template<typename Comparable>
vector<Comparable> insertionSort(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    int unsortedStartIndex, insertIndex;
    Comparable toBeInserted;

    allocations += sizeof(unsortedStartIndex) + sizeof(insertIndex) + sizeof(toBeInserted);

    for (unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        toBeInserted = vec[unsortedStartIndex]; reads +=1;
        // Loop to shift over the larger elements
        insertIndex = unsortedStartIndex - 1;

        while (insertIndex >= 0 && vec[insertIndex] > toBeInserted) {
            reads += 2;
            vec[insertIndex + 1] = vec[insertIndex]; reads += 1;
            --insertIndex;
        }
        // Put toBeInserted back into vec
        vec[insertIndex + 1] = toBeInserted;
    }
    cout << "Insertion: Allocations: " << allocations << ", Reads: " << reads << endl;
    return vec;
}

#endif
