# Assignment pa1 : List ADTs

The goal of this project is to build an Integer List ADT in C and use it to alphabetize the lines in a file.
The main program for this project is called Lex.c. The List ADT module will be contained in files called
List.h and List.c, and will export its services to the client module Lex.c and ListClient.c.

## Build
    
    $ make

## Running

### ./Lex "in1" "out1"
### ./ListClient 

For the ListClient program, there is no need to give it any arguments/commands.
For the Lex program, you need a in1 = name of a pre-written file, with a list of 
words/strings to be orgonized. The second command could be any names, which would
write the list of words in alphabetical order. 
