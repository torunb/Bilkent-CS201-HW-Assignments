/**
* @author Utku Boran Torun 21901898
*/

#ifndef __LOT_H
#define __LOT_H

#include "Car.h"

#include <iostream>
#include <string>

class Lot
{
public:
    Lot();
    ~Lot();
    Lot(int id, int row, int col);

    int getID();
    int getRow();
    int getCol();


    Lot& operator=(const Lot& right); // assignment operator overload


    void parkCarForLot(int size, int lotId, string carType, int plateNumber, int row, int col, char*& );
    void removeCarForLot(int plateNumber, int row, int col, int size);

    int getEmptySpaces();

    Car getCar(int row, int col);

    void showLotContents();

    char* getPlaces();

private:
    int ID;
    int row;
    int col;
    int emptySpaces;
    Car** cars;
    char* places;

};


#endif