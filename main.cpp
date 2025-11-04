#include "sorting-algorithms/bubbleSort.h"
#include "sorting-algorithms/heapSort.h"
#include "sorting-algorithms/insertionSort.h"
#include "sorting-algorithms/mergeSort.h"
#include "sorting-algorithms/quickSort.h"
#include "sorting-algorithms/radixSort.h"
#include "sorting-algorithms/selectionSort.h"
#include "stability-test/contactsList.h"
#include <iomanip>
#include "readCSV.h"
#include <algorithm>
#include <random>
using namespace std;

void stabilityTest();

int main() {
    // TODO: Get your vector of custom data type objects ready
    vector<csvData> csvDataV;
    string filePath = "../Bella_Beats_Analysis_Master_Dataset_Cleaned.csv";
    getDataFromFile(csvDataV, filePath);
    shuffle(csvDataV.begin(), csvDataV.end(), mt19937(random_device{}()));

    // TODO: loop through vector sizes from 1000 to 100 in decrements of 100
    for (int i = 1000; i >= 100; i -= 100)
    {
        csvDataV.resize(i);

        unsigned long reads = 0, allocations = 0;
        cout<< "Vector Size = " << csvDataV.size()<< ": ";
        bubbleSort(csvDataV, reads, allocations);

    }
    // TODO: sort the vector in four different ways (bubble, ?, heap, ?)
    // TODO: record the number of reads and allocations for each sort

    //stabilityTest();
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