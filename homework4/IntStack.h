/**
* @author Utku Boran Torun 21901898
*/

#ifndef __INTSTACK_H
#define __INTSTACK_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>

#include "Stack.h"

using namespace std;

const int INT_MAX_STACK = 55;
typedef int IntStackItemType;

class IntStack{
public:
    IntStack();

    bool isEmpty();
    bool push(IntStackItemType newItem);
    bool pop();
    bool pop(IntStackItemType& stackTop);
    bool getTop(IntStackItemType& stackTop);

    int getSize();
    IntStackItemType getItem();

    void sort(string exp, int length, Stack& stringStack);
    void pushFromStringStack(Stack& stringStack);
    void sort();
    void removeDuplicate();
   // void pushFromIntStack(IntStack& intStack);

    //int topVal() const;

private:
    IntStackItemType items[MAX_STACK];
    int top;

    //Stack stringStack;
};

#endif