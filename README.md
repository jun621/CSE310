#CSE310 
##2022 FALL Data Structures & Algorithms 

#Project 1: Sorting Algorithm Application 
###Modular Design 
There is one module for InsertionSort, MergeSort, and QuickSort written in C++ including a header extension. 
In addtion, to the abovegiven modules a main file is implemented in main.cpp. 
### Project Flow
A valid execution of your project has the following form:
./PJ1 alg flag
where ./PJ1 tells the system to search for the executable file PJ1 in the current directory, alg ∈{InsertionSort, MergeSort, QuickSort} 
indicates which sorting algorithm to use, and flag ∈ {0, 1} indicates whether each EWC (element-wise comparison) made in the sorting
process should be printed out (print EWC if and only if flag = 1).


# Project 2: Max Heap / Min Heap , Double Ended Heap operation 
###Modular Design 
The project consists of max heap data structure and the basic max heap functions Heapify, BuildHeap, ExtractMax, IncreaseKey, and Insertion. 
Symmetrically, we have the min heap data structure (in which the key value at a node cannot be smaller than the value at its parent)
and the corresponding basic min heap functions Heapify, BuildHeap, ExtractMin, DecreaseKey, and Insertion. 
The Double Ended Heap will complete both MaxHeap and MinHeap operations. 
### Project Flow 
A valid execution of your project has the following form:
./PJ2 DataStructure Capacity
where ./PJ2 tells the system to search for the executable file PJ2 in the current directory, The value
of DataStructure should be in the set {MaxHeap, MinHeap, DoubleHeap}, indicating which data
structure to use, and Capacity is a positive integer, indicating the capacity of the corresponding
heap. 

#Project 3: Simple Navigation System  
###Modular Design 
This project is the essential part of a navigation system. It reads in a directed graph or an undi-
rected graph G with n vertices and m edges from a file specified by the command-line arguments. It
then takes corresponding actions for given commands. Besides the Stop command, the valid com-
mands include (A) path computation commands (SinglePair or SingleSource), (B) path printing
commands, and (C) length printing commands.
Both SinglePair and SingleSource path computations should have worst-case time complexity
O(mlog n). Path printing should have worst-case time complexity O(n). Length printing should
have worst-case time complexity O(1). Memory should be allocated when needed, and release when
it is no longer needed. Memory leaks should be avoided.
### Project Flow 
A valid execution of your project has the following form:
./PJ3 <GraphType> <InputFile>
where PJ3 is the exe file of your project, <GraphType> should be substituted by either Directed or Undirected,
<InputFile> should be the exact name of the input file.





