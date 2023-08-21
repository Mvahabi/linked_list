/*
 * Mahyar Mike Vahabi
 * mvahabi
 * Winter 22 - CSE101 - pa5
 * Shuffle.cpp - The Perfect Shuffle
 * 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cmath>
#include "List.h"

using namespace std;

void shuffle(List& D) {

    List left, right;
    int i = 0;
    D.moveFront();
    while (D.position() < D.length()) {
        if (i < floor(D.length() / 2)) {
            left.insertBefore(D.moveNext());
        } else {
            right.insertBefore(D.moveNext());
        }
        i++;
    }
    
    bool odd = false;
    if (D.length() % 2){
        odd = true;
    }

    D.clear();
    left.moveFront();
    right.moveFront();
    while (right.position() < right.length() && left.position() < left.length()) {
        D.insertBefore(right.moveNext());
        D.insertBefore(left.moveNext());
    }
    if (odd) {
        D.insertAfter(right.peekNext());
    }
}

int main(int argc, char * argv[]){
    int num, i, j, l;
    List deck, shuff;

    if( argc != 2 ){
       cerr << "Usage: " << argv[0] << " <positive integer> " << endl;
       return(EXIT_FAILURE);
    }

    num = stoi(argv[1]);
    if (num < 0) {
        cerr << "Invalid number of deck size; Can not operate on negative numbers" << endl;
        return(EXIT_FAILURE);
    }

    cout << "deck size\tshuffle count" << endl;
    cout << "------------------------------" << endl;
    cout << "1\t\t1" << endl;

    for (j = 2; j <= num; j++) {
        for (i = 0; i < j; i++) {
            deck.insertBefore(i);
        }
        shuff = List(deck);
        l = 0;
        while (1) {
            shuffle(shuff);
            l++;
            if (shuff == deck) {
                break;
            }
        }
        cout << j << "\t\t" << l << endl;
        shuff.clear();
        deck.clear();
    }

    return(EXIT_SUCCESS);
}

