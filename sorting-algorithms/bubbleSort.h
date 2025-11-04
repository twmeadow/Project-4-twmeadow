#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "printVec.h"

template<typename Comparable>
vector<Comparable> bubbleSort(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    int numPasses = 0, i;
    Comparable temp;
    bool haveSwapped = true;
    allocations += sizeof(numPasses) + sizeof(i) + sizeof(temp) + sizeof(haveSwapped);
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            reads +=2;
            if (vec[i] > vec[i+1]) {
                temp = vec[i]; reads +=1;

                vec[i] = vec[i+1]; reads +=1;

                vec[i+1] = temp;
                // Update haveSwapped
                haveSwapped = true;
            }
        }
        // Update numPasses
        ++numPasses;
    }


    cout << "Bubble: Allocations: " << allocations << ", Reads: " << reads<< endl;
    return vec;
}

#endif
