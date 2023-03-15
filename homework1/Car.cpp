/**
* @author Utku Boran Torun 21901898
*/

#include <iostream>
#include <string>

#include "Car.h"

using namespace std;


Car::Car()
{
    setCarType("+");
    plateNumber = 0;
    size = 0;
}

Car::Car(string type, int plateNumber)
{
    setCarType(type);
    this->plateNumber = plateNumber;
}

Car:: ~Car(){}

void Car:: setCarType(string carType)
{
    if(carType == "a" )
    {
        type = "Light-duty";
        size = 1;
    }
    if(carType == "b")
    {
        type = "Heavy-duty";
        size = 2;
    }
}

string Car:: getCarType()
{
    return type;
}

int Car:: getPlateNumber()
{
    return plateNumber;
}

void Car:: setPlateNumber(int newPlateNum)
{
    plateNumber = newPlateNum;
}

int Car:: getSize()
{
    return size;
}

string Car:: getCarLocation(int row)
{
    if(row == 1)
    {
        return "A";
    }
    if(row == 2)
    {
        return "B";
    }
    if(row == 3)
    {
        return "C";
    }
    if(row == 4)
    {
        return "D";
    }
    if(row == 5)
    {
        return "E";
    }
    if(row == 6)
    {
        return "F";
    }
    if(row == 7)
    {
        return "G";
    }
    if(row == 8)
    {
        return "H";
    }
    if(row == 9)
    {
        return "I";
    }
    if(row == 10)
    {
        return "J";
    }
    if(row == 11)
    {
        return "K";
    }
    if(row == 12)
    {
        return "L";
    }

    return "";
}




