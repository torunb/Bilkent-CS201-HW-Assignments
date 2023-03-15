/**
* @author Utku Boran Torun 21901898
*/

#include <iostream>
#include <string>
#include <cstddef>

#include "Stack.h"

using namespace std;


Stack:: Stack()
{
    top = -1;
}


bool Stack:: isEmpty()
{
    return top < 0;
}

bool Stack:: push(StackItemType newItem)
{
    if(top >= MAX_STACK-1)
        return false;
    
    else
    {
        top++;
        items[top] = newItem;
        return true;
    }
}

bool Stack:: pop()
{
    if(top < 0)
        return false;

    else
    {
        --top;
        return true;
    }
}

bool Stack:: pop(StackItemType& stackTop)
{
    if(top < 0)
        return false;

    else
    {
        stackTop = items[top];
        top--;
        return true;
    }
}

bool Stack:: getTop(StackItemType& stackTop)
{
    if(top < 0)
        return false;

    else
    {
        stackTop = items[top];
        return true;
    }
}

int Stack:: getSize()
{
    return top;
}

// int Stack:: topVal() const
// {
//     return top;
// }

string Stack:: getItem()
{
    //cout << "This is top: " << top << endl;
    return items[top];
}