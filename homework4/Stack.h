/**
* @author Utku Boran Torun 21901898
*/

#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_STACK = 55;
typedef string StackItemType;

class Stack{
public:
    Stack();

    bool isEmpty();
    bool push(StackItemType newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop);

    int getSize();
    string getItem();

    //int topVal() const;

private:
    StackItemType items[MAX_STACK];
    int top;
};

#endif