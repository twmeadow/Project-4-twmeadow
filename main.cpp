#include "sorting-algorithms/bubbleSort.h"
#include "sorting-algorithms/heapSort.h"
#include "sorting-algorithms/insertionSort.h"
#include "sorting-algorithms/mergeSort.h"
#include "sorting-algorithms/quickSort.h"
#include "sorting-algorithms/radixSort.h"
#include "sorting-algorithms/selectionSort.h"
#include "stability-test/contactsList.h"
#include <iomanip>
using namespace std;

void stabilityTest();

int main() {
    // TODO: Get your vector of custom data type objects ready
    // TODO: loop through vector sizes from 1000 to 100 in decrements of 100
    // TODO: sort the vector in four different ways (bubble, ?, heap, ?)
    // TODO: record the number of reads and allocations for each sort

    stabilityTest();
    return 0;
}

void stabilityTest() {
    ContactsList people;
    people.readContactsFromFile("../stability-test/names.csv");
    cout << "People (Default ordering)" << endl;
    people.printList();

    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort<contact>);

    // TODO: add other stable algorithm here

    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort<contact>);

    // TODO: add other unstable algorithm here
}