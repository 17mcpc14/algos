# List of Algorithms

### Linear Search

Path: ~/src/`com/uoh/LinearSearch.java`

### Binary Search

Path: ~/src/`com/uoh/BinarySearch.java`

### Bubble Sort

Path: ~/src/`com/uoh/BubbleSort.java`

### Quick Sort

Path: ~/src/`com/uoh/QuickSort.java`

### Matix Multiplication

Path: ~/src/`com/uoh/MatrixMultiplication.java`

### Chained Matrix Multiplication

Path: ~/src/`com/uoh/ChainedMatrixMultiplication.java`

### Towers of Hanoi

Path: ~/src/`com/uoh/TowersOfHanoi.java`

### Prefix to Postfix conversion

Path: ~/src/`com/uoh/Prefix2PostfixTree.java`

## Time Comparision

Time taken by each algorithm for 1 million records:

| Algorithm                       	    | # of Elements                 | Time Taken (milli seconds) | Time Complexity   |
|---------------------------------------|-------------------------------|----------------------------|-------------------|
|  Linear Search                    	| 1 million                     |                        6   |       O(n)  	     |
|  Binary Search                     	| 1 million                     |                        0   |       O(log n)  	 |
|  Bubble Sort :                       	|   	                        |                            |       O(n*n)    	 |
|   	                                | 100,000 items                 |                    20748 	 |                 	 |
|   	                                | 1000,000 items                |               >5 minutes	 |                   |
|  Quick Sort :                        	|                               |                          	 |      O(n* log n)  |
|   	                                | 100,000 items                 |                       22 	 |                 	 |
|   	                                | 1000,000 items                |                      612	 |                 	 |
|  Matrix Multiplication :             	|                               |                            |      O(n *n *n) 	 |
|                                   	| 1000x1000 1000x1000 items     |                     2864   |                   |
|   	                                | 10000x10000 10000x10000 items | 	            >5 minutes   |               	 |
|  Towers of Hanoi :                   	|                             	|                            |      O(2 ^ n)   |
|                                       | 1000 items:   	            |               >5 minutes   |               	 |
|   	                                | 10000 items:                  |             Stack overflow |                 	 |
|  Chained Matrix Multiplication :    	|               	            |                  	         |      O(n *n *n)                 |
|                                       | 1000 items:   	            |               >5 minutes   |               	 |
|   	                                | 10000 items:                  |             Out of memory  |                 	 |

## Analysis

* Programs with time complexity O(n*n) work well for data elements less than 100,000 and beyond that they stop responding
* Programs with time complexity O(2 ^ n) work well for data elements less than 1000 and beyond that they throw errors
* Recursive programs use stack space extensively and so either go into "Stack overflow exception" or "Out of memory error" for data elements more than 1000
* Loop invariants for Bubble Sort and Quick Sort consume a time complexity of O(n)
* Time complexity of loop invariants have no impact on the overall time complexity of Bubble Sort, Quick Sort algorithms 

## Running the algorithms from command line

Go to `~/src` directory using command `cd ./src`
 
Compile the java programs using command `javac com/uoh/*.java`

Run any algorithm using command `java com.uoh.<Algorithm name; eg: LinearSearch>`

Running a program with additional memory settings `java -Xms2048m -Xmx4096m com.uoh.<Algorithm name; eg: LinearSearch>`

## Project Setup - using IntelliJ IDE

Install the latest stable (not beta) version of the IntelliJ

Open the project using IntelliJ: `File -> Open`

Open any of the algorithm in `src/com/uoh` directory

Right click on the opened file and click on run option
    (or)
just press `Control+Shift+F10`

