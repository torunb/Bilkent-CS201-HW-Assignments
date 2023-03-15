/**
* @author Utku Boran Torun 21901898
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

#include "Solutions.h"

using namespace std;

int calculateSubsetCandidates(int length)
{
    int noOfCandi = 0;
    if(length == 2)
        return 1;
    for(int i = 0; i < length; i++)
    {
        noOfCandi = noOfCandi + i;
    }

    return noOfCandi;
}

bool isComma(string exp)
{
    if(exp[0] == ',')
        return true;
    else
        return false;
}

string reverseString(string exp, int length)
{
    string temp;

    for(int i = length-1; i >= 0; i--)
    {
        temp = temp + exp[i];
    }

    return temp;
}
/**
* Function to determine priority of the operands
*/
int priority(string operand)
{
    char c = operand[0];
    switch(c)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        default: return 0;
    }
}

/**
 * Function to check whether the string is operator or not 
 */
bool isItOperator(string str)
{
    char ch[1];
    string holder = str;
    strcpy(ch, holder.c_str());

    if(isspace(ch[0]) || isdigit(ch[0]))
        return false;
    else
        return true;
}



void fantabulous(string list, int length)
{
    bool isFantab = false;

    int commaCnt;
    Stack myStack;

    Stack token1;
    Stack token2;
    Stack token3;

    stringstream holder(list);

    string temp;
    string temp2;

    string sontemp;
    

    

    string lastOneToBePushed;


    //int cnt;
    if(length <= 0)
        return;

    for(int i = 0; i < length; i++)
    {
        if(list[i] == ',')
            commaCnt++;
    }

    string reversedExp = reverseString(list, length + commaCnt);
    stringstream holder2(reversedExp);

    while(getline(holder, temp, ','))
    {
        token1.push(temp);
    }

    //cout << "Son item olmadan size: " << token1.getSize() << endl;

    token1.getTop(sontemp);

    //cout << "Son item da aha bu: " << sontemp << endl;

    //cout << "reverse: " << reversedExp << endl;
    
    if(getline(holder2, lastOneToBePushed, ','))
    {
        temp2 = lastOneToBePushed;
    }

    //cout << temp2 << endl;

    reverse(temp2.begin(), temp2.end());
    //cout << temp2 << endl;

    //token1.push(temp2);

    while( (token1.isEmpty()) == false)
    {
        token2.push(token1.getItem());
        token3.push(token1.getItem());
        token1.pop();
    }

    //cout << token2.getSize() << endl;

    string hfg;
    //token2.pop(hfg);

    // cout << token2.getTop(hfg) << endl;
    // cout << token2.getItem() << endl;
    // cout << "Abi top: " << hfg << endl; 

    //cout << "Değer: " << stoi(hfg) << endl;
    
    
    while((token2.isEmpty()) == false)
    {
        int val1, val2 = 0;
        string val1str, val2str;

        token2.pop(val1str);
        val1 = stoi(val1str);

        token2.pop(val2str);
        val2 = stoi(val2str);

        if(val2 > val1)
        {
            
        }
        //cout << val1 << endl;
        
    }
    //cout << endl;

    //cout << "\n" << endl;
    
    return;
}

void subset(string intervals, int length)
{
    IntStack intStack;
    IntStack intStack2;
    IntStack intStack3;
    IntStack intStack4;
    IntStack intStack5;

    Stack token1;
    Stack token2;
    Stack token3;

    stringstream hold(intervals);

    string temp;

    int noOfSubsets;

    if(length <= 0)
        return;

    while(getline(hold, temp, ','))
    {
        token1.push(temp);
    }

    while(token1.isEmpty() == false)
    {
        string temp2;
        token1.pop(temp2);
        token2.push(temp2);
        token3.push(temp2); // in order not to lost string stack
    }

    if(token2.isEmpty())
        return;


    while(token2.isEmpty() == false)
    {
        intStack.sort(intervals, length, token2);

    }

    while(token3.isEmpty() == false)
    {
        intStack3.pushFromStringStack(token3);
    }

    while(intStack3.isEmpty() == false)
    {
        int val;
        intStack3.pop(val);
        intStack4.push(val);
        intStack5.push(val);
    }


    while(intStack.isEmpty() == false)
    {
        int tempo;
        intStack.pop(tempo);
        intStack2.push(tempo);
    }

    
    
    // INTSTACK2 HOLDS SORTED IMTERVAL AND INTSTACK4 - INTSTACK5 HOLDS UNSORTED INTERVAL

    int popVal1, popVal2;

    while(intStack4.isEmpty() == false)
    {
        intStack4.pop(popVal1);
        intStack4.pop(popVal2);

        int diff = popVal2- popVal1;

        for(int i = 0; i < diff; i++)
        {
            int x;
            x = popVal1 + i;
            intStack5.push(x);
        }
    }

    
    IntStack intStack6;
    IntStack intStack7;

    intStack5.sort();
    intStack5.removeDuplicate();

    while(intStack5.isEmpty() == false)
    {
        int inter1;
        intStack5.pop(inter1);
        intStack6.push(inter1);
    }

    int counter = 0;
    cout << "Joined subsets: ";
    while(intStack6.isEmpty() == false)
    {
        int tempVal1;
        intStack6.pop(tempVal1);
        intStack7.push(tempVal1);
        counter++;
        int diff3 = intStack6.getItem() - intStack7.getItem();
        if(diff3 != 1)
        {
            int otherTop = intStack7.getItem();
            int val;
            /*
            for(int i = 0; i < counter + 1; i++)
            {
                intStack7.pop();
            }
            */
            while(intStack7.isEmpty() == false)
            {
                intStack7.pop(val);
            }
            cout << "(" << val << ":" << otherTop << "), ";


        }
    }
    cout << endl;
}



string infix2postfix(string expression)
{
    Stack stack;

    Stack tokenStack1;
    Stack tokenStack2;

    string line = expression;

    stringstream check1(line);

    string intermediate;

    for(int i = 0; i < expression.length(); i++){
        intermediate = expression[i];
        tokenStack1.push(intermediate);
    }
    
    while (!tokenStack1.isEmpty()) {
        tokenStack2.push(tokenStack1.getItem());
        tokenStack1.pop();
    }
    
    string resultExp = " ";

    while(!tokenStack2.isEmpty()) {
        string s;
        tokenStack2.pop(s);
        if (s.length() == 1) {
            if (s == "(") {
                stack.push(s);
            }
            else if (s == ")") {
                while (stack.getItem() != "(") 
                {
                    resultExp += stack.getItem() + " ";
                    stack.pop();
                }
                stack.pop();
            }
            else if (isItOperator(s) == true) 
            {
                string utr = stack.getItem();
                while (stack.isEmpty() == false && stack.getItem() != "(" && priority(s) <= priority(utr)) 
                {
                    resultExp = resultExp + stack.getItem() + " ";
                    stack.pop();
                }
                stack.push(s);
            }
            else 
                resultExp = resultExp + s + " ";
            
        }
        else 
            resultExp = resultExp + s + " ";
        
    }
    while (stack.isEmpty() == false) 
    {
        resultExp = resultExp + stack.getItem() + " ";
        stack.pop();
    }

    string toBeReturned = resultExp.substr(0, resultExp.length() - 1);
    return toBeReturned;
}


string infix2prefix(string expression)      
{
    string temp = expression;

    temp = reverseString(temp, temp.length());

    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == '(') 
        {
            temp[i] = ')';
            i++;
        }
        else if (temp[i] == ')') 
        {
            temp[i] = '(';
            i++;
        }
    }

    string result = infix2postfix(temp);

    result = reverseString(result, result.length());

    cout << "Prefix form of " << expression << " is: ";
    return result;

}

void evaluatePrefix(string expression)
{
    double eval = 0;

    Stack myStack;

    Stack token;
    Stack token2;


    string expHolder = expression;

    stringstream holder(expHolder);

    string inter;

    for(int i = 0; i < expression.length(); i++)
    {
        inter = expression[i];
        token.push(inter);
    }


    // while(token.isEmpty() == false)
    // {
    //     string you;
    //     token.pop(you);
    //     token2.push(you);
    // }

    while(token.isEmpty() == false)
    {
        string s;
        token.pop(s);


        if(isItOperator(s) && s.length() == 1)
        {
            string op1, op2;
            myStack.pop(op2);
            myStack.pop(op1);

            double res = 0;

            stringstream stream1(op1);
            stringstream stream2(op2);

            double op1val, op2val = 0.0;


            stream1 >> op1val;
            stream2 >> op2val;

            if(s == "+")
            {
                res = op1val + op2val;
            }
            else if(s == "-")
            {
                res = op1val - op2val;
            }
            else if(s == "*")
            {
                res = op1val * op2val;
            }
            else if(s == "/")
            {
                if(op2val == 0)
                {
                    cout << "Result of " << expression << " is: 0." << endl;
                    return;
                }
                res = op1val / op2val;
            }

            ostringstream ost;
            ost << res;
            string resultValue = ost.str();
            myStack.push(resultValue);
        }
        else
        {
            myStack.push(s);
        }
    }

    string realValue;
    myStack.pop(realValue);
    stringstream finalStream(realValue);

    finalStream >> eval;
    
    cout << "Result of " << expression << " is: " << eval << endl;
}