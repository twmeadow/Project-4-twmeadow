#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "printVec.h"

template<typename Comparable>
vector<Comparable> bubbleSort(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    int numPasses = 0, i;
    allocations += sizeof(i);
    Comparable temp;
    allocations += sizeof(temp);
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        allocations += sizeof(haveSwapped);
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i+1]) {
                reads +=2;
                temp = vec[i];
                reads +=1;
                vec[i] = vec[i+1];
                reads +=1;
                vec[i+1] = temp;
                // Update haveSwapped
                haveSwapped = true;
            }
        }
        // Update numPasses
        ++numPasses;
    }
    return vec;
}

#endif
