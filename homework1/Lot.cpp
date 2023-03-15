#include <iostream>
#include <string>

#include "Lot.h"
#include "Car.h"

using namespace std;

Lot:: Lot()
{
    ID = 0;
    row = 0;
    col = 0;
    emptySpaces = 0;
}


Lot:: Lot(int ID, int row, int col)
{
    places = new char[row * col];

    for(int i = 0; i < row * col; i++)
    {
        places[i] = '+';
    }

    this->ID = ID;
    this->row = row;
    this->col = col;
    cars = new Car*[row];

    emptySpaces = row * col;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cars[i] = new Car[col];
            Car newCar("+", 0);
        }
    }
}


Lot:: ~Lot()
{
    // for(int i = 0; i < this->getCol(); i++)
    // {
    //     delete cars[i];
    // }

    delete[] cars;

    delete[] places;
}

int Lot:: getID()
{
    return ID;
}

int Lot:: getRow()
{
    return row;
}


int Lot:: getCol()
{
    return col;
}




// assignment operator overload for memory leak
Lot& Lot:: operator=(const Lot& right)
{
    this->ID = right.ID;
    this->col = right.col;
    this->row = right.row;
    this->emptySpaces = right.emptySpaces;

    this->cars = new Car*[right.row];

    for(int i = 0; i < right.row; i++)
    {
        this->cars = new Car*[right.col];
    }

    for(int i = 0; i < right.row; i++)
    {
        for(int j = 0; j < right.col; j++)
        {
            this->cars[i][j] = right.cars[i][j];
        }
    }

    return *this;
}

void Lot:: parkCarForLot(int size, int lotId, string carType, int plateNumber, int row, int col, char*& places)
{
    cars[row][col].setCarType(carType);
    cars[row][col].setPlateNumber(plateNumber);

    if(carType == "b")
    {
        places[row * col - 1] = 'b';
        places[(row-1) * col - 1] = 'b';
        emptySpaces--;
        return;
    }

    if(carType == "a")
    {
        places[row * col - 1] = 'a';
        emptySpaces--;
        return;
    }
}

void Lot:: removeCarForLot(int plateNumber, int row, int col, int size)
{
    for(int i = 0; i < size; i++ )
    {
        for(int j = 0; j < this->getRow(); j++)
        {
            for(int k = 0; k < this->getCol(); k++)
            {
                cars[j][k].setCarType("+");
            }
        }
    }
    emptySpaces++;
    return;
}

int Lot:: getEmptySpaces()
{
    return emptySpaces;
}

void Lot:: showLotContents()
{
    cout << "  ";

    for(int i = 0; i < this->getCol(); i++)
    {
        cout << (i + 1) << " ";
    }


    cout << endl;

    for(int i = 0; i < this->getRow(); i++)
    {
        cout << static_cast<char>('A' + i) << " ";
        for(int j = 0; j < this->getCol(); j++)
        {
            if(j >= 9)
                cout << places[i * this->getCol() + j] << "  ";
            else
                cout << places[i * this->getCol() + j] << " ";
        }
        cout << "\n" << endl;
    }
    cout << endl;
    return;
}


Car Lot:: getCar(int row, int col)
{
    return cars[row][col];
}

char* Lot:: getPlaces()
{
    return places;
}

