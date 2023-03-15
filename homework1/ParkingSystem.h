/**
* @author Utku Boran Torun 21901898
*/

#ifndef __PARKINGSYSTEM_H
#define __PARKINGSYSTEM_H 

#include <string>
#include <iostream>

#include "Lot.h"
#include "Car.h"

using namespace std;

class ParkingSystem
{
public:
    ParkingSystem();
    ~ParkingSystem();
    void createLot(int id, int rows, int columns); 
    void removeLot(int id); 
    void listLots(); 
    void lotContents(int id); 
    void parkCar(int lotId, string location, string carType, int plateNumber);
    void findCar(int plateNumber); 
    void removeCar(int plateNumber);

private:
    Lot** parkLot; 
    int size;
};

#endif