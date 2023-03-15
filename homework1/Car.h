/**
* @author Utku Boran Torun 21901898
*/

#ifndef __CAR_H
#define __CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car
{
public:
    Car();
    Car(string type, int plateNumber);
    ~Car();


    string getCarType();
    void setCarType(string carType);

    int getPlateNumber();
    void setPlateNumber(int newPlateNum);
    string getCarLocation(int);

    int getSize();

    //Car& operator=(const Car& right);

private:
    string type;
    int plateNumber;
    int size;
};

#endif