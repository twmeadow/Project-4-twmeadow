# Project 4 Report

Answer the following prompts directly in this file:
* Information about your dataset (you will be assigned a different grader for this project).

My data is a several stats from fitbit users, such as calories burned in a day, hours slept, steps, and heart beat rate. The data is very extensive and has lots of entries.


* Analyze the data. Graph the number of reads and allocations for each sorting algorithm and look at how the number of reads and allocations grows when the size of the data set grows. Compare and contrast the different sorting algorithms and draw conclusions about which sorting algorithms are more efficient. Discuss complexities and their effects.

First the graph of the reads can be seen below. 

![read graph.png](read%20graph.png)

The reads show that bubble is the worst sorting algorithm, followed by insertion, then heap, then quick sort as the best. 
This tracks with the time complexities that were discussed in class, as that is essentially what the reads are measuring. 

Bubble and insertion sort are both O(n^2) which is why they are the two worst. 
After that Heap and quick are both O(n * log(n)) which is noticeably better than the other two. 
Heap and quick sort are the more time efficient algorithms, with quick sort beig the best. 

The allocations graph can be seen below: 

![allocations graph .png](allocations%20graph%20.png)

Here it can be seen that quick sort has by far the most allocations, with all the other functions being constant. 
This directly reflects the space complexity of these algorithms, as only quick sort has a non-constant auxilary complexity, which is exactly what the graph illustrates. 

In direct contrast to the previous section, now quick sort is the least officient, with regards to memory. This is the price one pays for the 
time efficiency of quick sort, by compromising with the space allocation. 

* Look at the output from the stabilityTest function and answer the following questions:
  * How are the names sorted by default?

  * How is the output from the two stable sorting algorithms different from the two unstable ones? Be specific in your answer, and use what you know about how each sorting algorithm works to justify your observations.

By default, the names have the following arrangement:
![default stablility ordering.png](default%20stablility%20ordering.png)

The stable sorting algorithms, bubble and insertion sort, maintain the ordering of the names, within the now sorted order of the last name. 
For example, the last name 'black' has been sorted to be first. The order of first names within the group of people with the last name Black is sorting is Blake, Jordan, Sam. This is identical to the order that the same first names appear in the original vector, just with the last names out of order
This exact behaviour is mimicked for both bubble and insertion sort. 
This is the very definition of what stability means and measured, which confirms that these vectors are indeed stable. 

For the unstable sorting algorithms the order is not preserved. Reusing the example from the previous paragraph, of the first name ordering for people with the last name black, we see the following result. Heap sort has the order Jordan, Sam, Blake, which is clearly not in line with the origianl ordering in the unsorted vector.
While quick sort actually does preserve this order for the last name Black, moving one name down the list to the last name Brown, the ordering is once again unstable. The bubble sort has the order Kelsey, Jamie, Skylar, where as the unsorted vector has the order Jame, Kelsey, Skylar which is clearly not the same. 
This further proves the unstability of these functions, which was theorized to begin with. 

* Answers to the following questions: 
  * If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why? 
  
I would use the radix sort for this case. Radix sort is basically just repeated bucket sort, which only works if there is a finite, known number of possibilities for each digit. Here there is, as it must be one of the letters in the alphabet, or some other numeric symbol.
Additionally this algorithm is stable and has a great time complexity of O(n). I think it would be good for these reasons. 

  * What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud?

Here any of the O(n^2) algorithms are strictly off limits, as the amount of time it would take to sort that many items would be astronomical. Additionally its safe to assume that bucket sort and radix sort are also off the table, due to the ambiguity as to what the data is. 

For these reasons I think I would choose merge sort, because it has both a time and space complexity of O(n * log(n)). Quick sort could also be an option here, but has a chance to have worse efficiency depending on how the data is aranged. For that reason I think merge sort is the best option. 

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**