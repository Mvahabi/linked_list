# Assignment pa5 : Shuffles and Linked List in C++ 

In this project we will create a new List ADT, this time in C++. 
use this List to perform shuffling operations, and determine how 
many shuffles are necessary to bring a List back into its original order. 
This project will utilize a List ADT (List.h and List.cpp), in order to 
perform deck shuffling operations. The main program for this project is 
called Shuffle.cpp. List.h and List.cpp,  will export its services to the 
client module ListTest.cpp and ListClient.cpp.

## Build
    
    $ make

## Running

### ./Shuffle "input"
### ./ListTest
### ./ListClient

./Shuffle will take 2 command line arguments:
giving the names of the input and output file. The "input"
will contain a single integer that determines the max number of cards. 
For each 𝑛 in the range 1 up to this maximum, the program will 
perform shuffles until the list (0, 1, 2, … , 𝑛 − 1) is brought back 
to its original order, counting the number of shuffles as it goes. 
It will print a table to the standard output, giving this count, for each
value of 𝑛.

No need to do anything for ./ListTest
