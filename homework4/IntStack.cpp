/**
* @author Utku Boran Torun 21901898
*/

#include <iostream>
#include <string>
#include <cstddef>
#include <bits/stdc++.h>

#include "IntStack.h"

using namespace std;


IntStack:: IntStack()
{
    top = -1;
}


bool IntStack:: isEmpty()
{
    return top < 0;
}

bool IntStack:: push(IntStackItemType newItem)
{
    if(top >= INT_MAX_STACK-1)
        return false;
    
    else
    {
        top++;
        items[top] = newItem;
        return true;
    }
}

bool IntStack:: pop()
{
    if(top < 0)
        return false;

    else
    {
        --top;
        return true;
    }
}

bool IntStack:: pop(IntStackItemType& stackTop)
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

bool IntStack:: getTop(IntStackItemType& stackTop)
{
    if(top < 0)
        return false;

    else
    {
        stackTop = items[top];
        return true;
    }
}

int IntStack:: getSize()
{
    return top;
}

// int IntStack:: topVal() const
// {
//     return top;
// }

int IntStack:: getItem()
{
    //cout << "This is top: " << top << endl;
    return items[top];
}

void IntStack:: sort(string exp, int length, Stack& stringStack)
{
    int commaCnt;
    string tempStr;
    stringstream holder(exp);

    //Stack stringStack2;
    

    for(int i = 0; i < length + (length - 1); i++)
    {
        if(exp[i] == ',')
            commaCnt++;
    }

    while(stringStack.isEmpty() == false)
    {
        //cout << "Bakim" << endl;
        int values;
        string valuesStr;
        stringStack.pop(valuesStr);

        values = stoi(valuesStr);
        this->push(values);
    }

    int temp;
    for(int i = 0; i < length; i++)
    {
       for(int j = 0; j < length - 1; j++)
        {
            if(items[i] < items[j])
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }    
}

void IntStack:: pushFromStringStack(Stack& stringStack)
{
    while(stringStack.isEmpty() == false)
    {
        int values;
        string valueStr;

        stringStack.pop(valueStr);
        values = stoi(valueStr);
        this->push(values);
    }
}

void IntStack:: sort()
{
    int temp;
    for(int i = 0; i < top + 1; i++)
    {
        for(int j = 0; j < top; j++)
        {
            if(items[i] < items[j])
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

void IntStack:: removeDuplicate()
{
    int tempItems [top + 1];
    int tempTop = top + 1;

    int j = 0;

    for(int i = 0; i < tempTop - 1; i++ )
    {
        if(items[i] != items[i + 1])
            tempItems[j++] = items[i];
    }

    tempItems[j++] = items[top];

    for(int i = 0; i < j; i++)
        items[i] = tempItems[i];

    top = j - 1;
}
