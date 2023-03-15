/**
* @author Utku Boran Torun 21901898 
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int multiplyItself(int a, int n, int p);
int cycleShortcut(int a, int n, int p);
int recursive(int a, int n, int p);
int powerOf(int& x, int y );


int main()
{

    int a, n, p, loop, u; // loop is the k in the homework instruction

    cout << "Please enter a: ";
    cin >> a;

    cout << endl;

    cout << "Please enter n: ";
    cin >> n;

    cout << endl;

    cout << "Please enter p: ";
    cin >> p;

    cout << "Please enter how many times you want to execute: ";
    cin >> loop;

    cout << endl;

    cout << endl;

    double duration;
    clock_t startTime = clock();




    for(int i = 0; i < loop; i++ )
        u = multiplyItself(a, n, p);
    
    cout << u << endl;
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;


    double duration1;
    clock_t startTime1 = clock();

    for(int i = 0; i < loop; i++ )
        u = cycleShortcut(a, n, p);

    cout << u << endl;
    duration1 = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration1 << " milliseconds." << endl;

    for(int i = 0; i < loop; i++ )
        u = recursive(a, n, p);


    double duration2;
    clock_t startTime2 = clock();
    cout << u << endl;
    duration2 = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration2 << " milliseconds." << endl;

    

    return 0;
}


int multiplyItself(int a, int n, int p)
{
    int x = a;
    int b = 0;
    if(a == 0)
        return 0;
    if(n == 0)
        if(p == 1)
            return 0;
        else
            return 1;

    if(n == 1)
        if( a < p)
            return a;
        else    
            return a % p;
        
    for(int i = 1; i < n; i++){
        a = a * x;
        b = a % p;
    }

    return b;
}

int cycleShortcut(int a, int n, int p){
    int x = a;
    int i = 0;

    while(a % p != 1){
        a = a * x;
        i++;
    }

    if( n < i ){
        return multiplyItself(a, n, p);
    }

    int c = n % i;
    int o = powerOf(a, c);

    o = o % p;

    return o;
    
}

int recursive(int a, int n, int p){
    if(n == 1){
        return a % p;
    }
    if(n % 2 == 0){
        a = powerOf(a, n/2);
        return recursive(a, n/2, p) * recursive(a, n/2, p);
    }
    else{
        int c = (n - 1) / 2;
        int m = a % p;
        int z = recursive(a, c, p) * recursive(a, c, p);
        z = z * (a % p);
        return z;
    }
}


int powerOf(int& x, int y){
    int a = x;
    if(y == 0){
        x = 1;
        return x;
    }
        
    for(int i = 1; i < y; i++){
        x = x * a;
    }

    return x;
}




