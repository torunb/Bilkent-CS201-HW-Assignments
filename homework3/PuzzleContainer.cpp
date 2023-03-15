/**
* @author Utku Boran Torun 21901898
*/

#include "PuzzleContainer.h"
#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

void shapeConverter(unsigned char shape, int& down, int& up, int& right, int& left){
    down = shape % 4;
    up = (shape / 4) % 4;
    right= (shape / 16) % 4;
    left= shape / 64;
}

// PuzzleRow:: PuzzlePiece:: PuzzlePiece()
// {
//     shape = 'O';
//     rowindex = 1;
//     colindex = 1;
//     next = NULL;
// }

////////////////////////////////////////// PuzzleRow //////////////////////////////////////////////////


PuzzleRow:: PuzzleRow(int size, int rowindex)
{
    head = NULL; // PuzzlePiece
    next = NULL; // PuzzleRow
    this->rowindex = rowindex;
    maxSize = 0;
    length = 0;
}

PuzzleRow:: PuzzleRow()
{
    head = NULL;
    next = NULL;
}

PuzzleRow:: ~PuzzleRow()
{
    while(!isEmpty())
    {
        remove(1);
    }
}

int PuzzleRow:: getLength() 
{
    return length;
}

int PuzzleRow:: getRowIndex()
{
    return rowindex;
}

void PuzzleRow:: setNext(PuzzleRow* next)
{
    this->next = next;
}

PuzzleRow* PuzzleRow:: getNext()
{
    return next;
}

bool PuzzleRow:: isEmpty()
{
    return head == NULL;
}

bool PuzzleRow:: remove(int index)
{
    PuzzlePiece* cur;
    if(index < 1 || index > getLength())
        return false;
    
    length--;
    if(index == 1)
    {
        cur = head;
        head = head->next;
    }
    else
    {
        PuzzlePiece* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    
    cur->next = NULL;
    delete cur;
    cur = NULL;
    
    return true;
}

bool PuzzleRow:: insert(int index, char shape)
{
    int newLength = getLength() + 1;

    if(index < 0 || index > getLength())
        return false;

    PuzzlePiece* newPiece = new PuzzlePiece;
    length = newLength;

    newPiece->shape = shape;

    if(index == 0)
    {
        newPiece->next = head;
        head = newPiece;
    }
    else
    {
        PuzzlePiece* prev = find(index - 1);
        newPiece->next = prev->next;
        prev->next = newPiece;
    }

    return true;
    
}

PuzzleRow:: PuzzlePiece* PuzzleRow:: find(int index) 
{
    if(index < 1 || index > getLength())
        return NULL;

    else
    {
        PuzzlePiece* cur = head;
        for(int i = 1; i < index; i++)
            cur = cur->next;
        return cur;
    }
}

char PuzzleRow:: getPiece(int index )
{
    PuzzlePiece* temp = find(index - 1);
    if(temp->shape = 0)
        return 255;
    else
        return temp->shape;    
}

void PuzzleRow:: printRow()
{
    //int i = 0;
    PuzzlePiece* newPtr = head;
    for(int i = 1; i < getLength(); i++)
    {
        printf("%c", newPtr->shape);
        newPtr = newPtr->next;
    }

}


////////////////////////////////////////// PuzzleContainer ///////////////////////////////////////////////

PuzzleContainer:: PuzzleContainer(int h, int w)
{
    height = h;
    width = w;
    rowLists = NULL;
}

PuzzleContainer:: ~PuzzleContainer()
{
    delete rowLists;
}

PuzzleRow* PuzzleContainer:: getRow(int index)
{
    if(rowLists->getRowIndex() == index)
        return rowLists;
    
    else
    {
        PuzzleRow* rowPtr = rowLists;
        while (rowPtr->getRowIndex() != index)
        {
            rowPtr = rowPtr->getNext();
        }

        return rowPtr;
    }
    
}



bool PuzzleContainer:: insertRow(int index)
{
    int newHeight = height + 1;
    if(index < 1 || index > height)
        return false;
    
    PuzzleRow* newRow = new PuzzleRow(width, index);
    height = newHeight;

    if(index == 1)
    {
        newRow->setNext(rowLists);
        rowLists = newRow;
    }
    else
    {
        PuzzleRow* prevRow = getRow(index - 1);
        newRow->setNext(prevRow->getNext());
        prevRow->setNext(newRow);
    }

    return true;
}

bool PuzzleContainer:: removeRow(int index)
{
    PuzzleRow* cur;
    if(index < 1 || index > height)
        return false;
    
    height--;

    if(index == 1)
    {
        cur = rowLists;
        rowLists = rowLists->getNext();
    }
    else
    {
        PuzzleRow* prev = getRow(index - 1);
        cur = prev->getNext();
        prev->setNext(cur->getNext());
    }

    cur->setNext(NULL);
    delete cur;
    cur = NULL;

    return true;
}

int PuzzleContainer:: getWidth()
{
    return width;
}

int PuzzleContainer:: getHeight()
{
    return height;
}

void PuzzleContainer:: displayContainer()
{
    cout << "Container " << this->getHeight() << "x" << this->getWidth() << ":" << endl;
    cout << "  ";

    for(int i = 0; i < this->getWidth(); i++)
    {
        cout << (i + 1) << " ";
    }

    cout << endl;

    for(int i = 0; i < this->getHeight(); i++)
    {
        cout << (i + 1) << " ";
        for(int j = 0; j < this->getWidth(); j++ )
        {
            cout << 'o';
            //printf("%c", 'o');
            cout << " ";
        }

        //cout << " " << endl;
        cout << endl;
    }

    return;
}

bool PuzzleContainer:: addPiece(int row, int col, char shape)
{
    bool ocupied = false;
    if(row < 1 || row > height || col < 1 || col > width)
    {
        cout << "(" << row << "," << col << ")" << " is out of frame, it cannot be added." << endl;
        return false;
    }

    else
    {
        PuzzleRow* temp = rowLists;
        
        if(row == 1)
        {
            if(this->getRow(row)->getLength() < col)
            {    
                cout << "(" << row << "," << col << ")" << " is out of frame, it cannot be added." << endl;
                temp->setNext(NULL);
                delete temp;
                temp = NULL;

                return false;

            }
            else
            {
                if(this->getRow(row)->getPiece(col) == 'x')
                {
                    cout << "(" << row << "," << col << ")" << " has been already occupied, it cannot be added." << endl;
                    ocupied = true;

                    temp->setNext(NULL);
                    delete temp;
                    temp = NULL;

                    return false;
                }
                else
                {
                    this->getRow(row)->insert(col, shape);
                    cout << "A piece is added to (" << row << "," << col << ")" << endl;
                    return true;
                }
            }
        }
        else
        {
            if(this->getRow(row)->getLength() < col)
            {    
                cout << "(" << row << "," << col << ")" << " is out of frame, it cannot be added." << endl;
                temp->setNext(NULL);
                delete temp;
                temp = NULL;

                return false;

            }
            else
            {
                if(this->getRow(row)->getPiece(col) == 'x')
                {
                    cout << "(" << row << "," << col << ")" << " has been already occupied, it cannot be added." << endl;
                    ocupied = true;

                    temp->setNext(NULL);
                    delete temp;
                    temp = NULL;

                    return false;
                }
                else
                {
                    this->getRow(row)->insert(col, shape);
                    cout << "A piece is added to (" << row << "," << col << ")" << endl;
                    return true;
                }
            }
        }
    }


}

void PuzzleContainer:: showRow(int row)
{
    if(row < 1 || row > height)
    {
        cout << "Row " << row << " is out of border." << endl;
        return;
    }

    cout << "Row " << row << ":" << endl;
    PuzzleRow* shower = getRow(row);
    shower->printRow();
}

void PuzzleContainer:: showColumn(int col)
{
    if(col < 1 || col > width)
    {
        cout << "Column " << col << " is out of border." << endl;
        return;
    }

    cout << "Column " << col << endl;

    for(int i = 1; i <= height; i++)
    {
        char ch = this->getRow(i)->getPiece(col);
        printf("%c", ch);
        cout << endl;
    }
}

bool PuzzleContainer:: removePiece(int row, int col)
{
    if(row < 1 || row > height || col < 1 || col > width)
    {
        cout << "(" << row << "," << col << ") is out of frame, it cannot be removed." << endl;
        return false;
    }

    if(this->getRow(row)->getPiece(col) == 'o')
    {
        cout << "There is no piece on (" << row << "," << col << ", it cannot be removed" << endl;
        return false;
    }

    this->getRow(row)->remove(col);
    cout << "The piece on (" << row << "," << col << ") is removed" << endl;
    return true;
}

void PuzzleContainer:: findPiece(char shape)
{
    
}

void PuzzleContainer:: showPiece(int row, int col)
{

}