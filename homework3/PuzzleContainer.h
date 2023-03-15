/**
* @author Utku Boran Torun 21901898
*/

#ifndef __PUZZLECONTAINER_H
#define __PUZZLECONTAINER_H


class PuzzleRow{
private:
    struct PuzzlePiece{
    char shape;
    int rowindex;
    int colindex;
    PuzzlePiece* next;
};
    PuzzlePiece* head;
    PuzzleRow* next;
    int rowindex;
    int maxSize; //equals to puzzleContainer width

    int length;
    PuzzlePiece* find(int index);

public:
    PuzzleRow( int size, int rowindex);
    PuzzleRow();
    ~PuzzleRow();
    int getRowIndex();
    void setNext( PuzzleRow* next );
    PuzzleRow* getNext();
    bool insert( int index, char shape );
    bool remove( int index );
    bool isEmpty();
    char getPiece(int index );
    void printRow();

    int getLength();
};

class PuzzleContainer{
private:
    PuzzleRow* rowLists;
    int height;
    int width;

    int emptyHeight;
    int emptyWidth;

    //PuzzleRow* findRow(int index);
public:
    PuzzleContainer( int h, int w); // done
    ~PuzzleContainer(); // done
    PuzzleRow* getRow( int index ); // done
    bool insertRow( int index ); // done herhalde
    bool removeRow( int index ); // done herhalde
    bool addPiece( int row, int col , char shape ); 
    bool removePiece(int row, int col);
    int getHeight(); // done
    int getWidth(); // done
    void showPiece(int row, int col); 
    void displayContainer(); // done gibimsi
    void showColumn(int col); 
    void showRow(int row); // done sanırım
    void findPiece(char shape);
};



#endif