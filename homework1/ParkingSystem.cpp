/**
* @author Utku Boran Torun 21901898
*/

#include <iostream>
#include <string>

#include "ParkingSystem.h"
#include "Lot.h"
#include "Car.h"

using namespace std;

ParkingSystem:: ParkingSystem()
{
    size = 0;
    parkLot = new Lot*[size]; // used pointer pointer in order to manipulate the lots
}


ParkingSystem:: ~ParkingSystem()
{
    for(int i = 0; i < size; i++)
    {
        delete parkLot[i];
    }

    delete [] parkLot;
}

void ParkingSystem:: createLot(int id, int rows, int columns)
{
    Lot** temp = parkLot;

    if(rows <= 0 || rows > 12 || columns <= 0 || columns > 12)
    {
        cout << "Cannot create the parking lot " << id << ", dimensions exceed acceptable bounds" << endl;
        return;
    }

    
    for(int i = 0; i < size; i++)
    {
        if(id == parkLot[i]->getID())
        {
            cout << "Cannot create the parking lot " << id << ", a lot with this ID already exists" << endl;
            return;
        }
    }

    if(size > 0)
    {
        
        Lot* lotPointer = new Lot(id, rows, columns); // deleting this causes problem

        parkLot = new Lot*[size + 1]; 

        for(int i = 0; i < size; i++)
        {
            parkLot[i] = temp[i];
        }

        

        //for(int i = 0; i == size + 1; i++)
            parkLot[size] = lotPointer;


        delete[] temp; 
        //delete[] lotPointer;

        size++;

        cout << "Parking lot with ID "<< id << " and dimensions " << "(" << rows << ", " << columns << ")" <<" has been added to the system" << endl;
        return;
    }

    else    
    {   
        parkLot[0] = new Lot(id, rows,columns); // same problem
        cout << "Parking lot with ID "<< id << " and dimensions " << "(" << rows << ", " << columns << ")" <<" has been added to the system" << endl;
        size++;
        return;
    }


}

void ParkingSystem:: listLots()
{
    if(size <= 0)
    {
        cout << "No lots to list." << endl;
        return;
    }

    else   
    {
        cout << "List of lots:" << endl;

        for(int i = 0; i < size; i++)
        {       
            cout << "ID: " << parkLot[i]->getID() << ", Dim: (" << parkLot[i]->getRow() << "," << parkLot[i]->getCol() << "), number of empty parking spaces: " 
            << parkLot[i]->getEmptySpaces() << endl;
        }
        return;
    }
}

void ParkingSystem:: parkCar(int lotId, string location, string carType, int plateNumber)
{
    if(size <= 0)
    {
        cout << "Lot " << lotId << " is not in the system" << endl;
        return;
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < parkLot[i]->getRow(); j++)
        {
            for(int k = 0; k < parkLot[i]->getCol(); k++)
            {
                if(parkLot[i]->getCar(j, k).getPlateNumber() == plateNumber)
                {
                    if(carType == "b")
                    {
                        cout << "Cannot park heavy-duty car with number plate " << plateNumber << " at location "
                        << location << ", there already car exists with this plate number." << endl;
                        return;
                    }
                    if(carType == "a")
                    {
                        cout << "Cannot park light-duty car with number plate " << plateNumber << " at location "
                        << location << ", there already car exists with this plate number." << endl;
                        return;
                    }
                }
            }
        }

        if(parkLot[i]->getID() == lotId)
        {
            char* temp = new char[parkLot[i]->getRow() * parkLot[i]->getCol()];

            for(int j = 0; j < parkLot[i]->getRow() * parkLot[i]->getCol(); j++)
            {
                temp[i] = parkLot[i]->getPlaces()[i];
            }

            for (int j = 0; j < parkLot[i]->getRow(); j++)
            {
                for (int k = 0; k < parkLot[i]->getRow(); k++)
                {
                    parkLot[i]->parkCarForLot(size, lotId, carType, plateNumber, j, k, temp);

                    for(int a = 0; a < parkLot[i]->getRow() * parkLot[i]->getCol(); a++)
                    {
                        parkLot[i]->getPlaces()[a] = temp[a]; // problem 
                    }

                    delete[] temp;
                    temp = NULL;
                    cout << parkLot[i]->getCar(j, k).getCarType() << " car with number plate " <<  parkLot[i]->getCar(j, k).getPlateNumber()
                    << " has been parked at location " << location << ", " <<  "lot " << lotId << endl;
                    return;
                }
            }
        }
    }
    cout << "Lot " << lotId << " is not in the system" << endl;
    return;


}

void ParkingSystem:: removeLot(int id)
{
    if(size <= 0)
    {
        cout << "Lot " << id << " is not is the system" << endl;
        return;
    }

    for(int i = 0; i < size; i++)
    {
        if(parkLot[i]->getID() == id)
        {
            Lot** temp = new Lot*[size];
            
            for(int j = 0; j < size; j++)
            {
                temp[j] = parkLot[j];
            }

            for(int a = 0; a < temp[i]->getRow(); a++)
            {
                for(int b = 0; b < temp[i]->getCol(); b++)
                {
                    int plateNum = temp[i]->getCar(a, b).getPlateNumber();
                    temp[i]->removeCarForLot(plateNum, a, b, size);
                }
            }

            Lot** temp2 = new Lot*[size - 1];

            for(int c = i - 1; c >= 0; c--)
            {
                temp2[c] = temp[c];
            }

            for(int d = i + 1; d < size; d++)
            {
                temp2[d - 1] = temp[d];
            }

            delete[] parkLot; // delete old lot array
            delete[] temp; // delete old lot array

            parkLot = temp2;
            cout << "Lot " << id << " has been successfully removed from the system." << endl;
            size--;
            return;
        }
    }

    cout << "Lot " << id << " is not is the system" << endl;
    return;

}



void ParkingSystem:: findCar(int plateNumber)
{
    if(size <= 0)
    {
        cout << "The car with number plate " << plateNumber << " is not in the system" << endl;
        return;
    }



    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < parkLot[i]->getRow(); j++)
        {
            for(int k = 0; k < parkLot[i]->getCol(); k++)
            {
                if( parkLot[i]->getCar(j, k).getPlateNumber() == plateNumber)
                {
                    cout << parkLot[i]->getCar(j, k).getCarType() << " car with number plate " << plateNumber << " is at the location " 
                    << parkLot[i]->getCar(j, k).getCarLocation(j) << k + 1 << " lot " << parkLot[i]->getID() << endl;
                    return;
                }
            }
        }
    }

    cout << "The car with number plate " << plateNumber << " is not in the system" << endl;
    return;
}

void ParkingSystem:: lotContents(int id)
{
    if(size <= 0)
    {
        cout << "The park lot with " << id << " does not exist in the system." << endl;
        return;
    }

    for(int i = 0; i < size; i++)
    {
        if(parkLot[i]->getID() == id)
        {
            cout << "ID: " << id << "(" << parkLot[i]->getRow() << "," << parkLot[i]->getCol() << ")" <<", empty slots: " << parkLot[i]->getEmptySpaces() << ", parked cars: ";
            for(int j = 0; j < parkLot[i]->getRow(); j++)
            {
                for( int k = 0; k < parkLot[i]->getCol(); k++)
                {
                    if(parkLot[i]->getPlaces()[j * k] != '+')
                    {
                        cout << parkLot[i]->getCar(j, k).getPlateNumber() << ", ";
                    }
                }
            }
            cout << endl;
            cout << " " << endl;
            parkLot[i]->showLotContents();
            return;
        }
    }

    cout << "The park lot with " << id << " does not exist in the system." << endl;
    return;
    
}

void ParkingSystem:: removeCar(int plateNumber)
{
    if(size <= 0)
    {
        cout << "The car with number plate " << plateNumber << " is not in the system" << endl;
        return;
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < parkLot[i]->getRow(); j++)
        {
            for(int k = 0; k < parkLot[i]->getCol(); k++)
            {
                if(parkLot[i]->getCar(j, k).getPlateNumber() == plateNumber)
                {
                    parkLot[i]->removeCarForLot(plateNumber, j, k, size);
                    cout << parkLot[i]->getCar(j, k).getCarType() << " car with number plate " << plateNumber << " has been removed from slot " 
                    << parkLot[i]->getCar(j, k).getCarLocation(j) << k + 1 << ", lot " << parkLot[i]->getID() << endl;
                    return;
                }
            }
        }
    }
    cout << "The car with number plate " << plateNumber << " is not in the system" << endl;
    return;
}




