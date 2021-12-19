/**
 Caroline El Jazmi
 UW ID: 1942686
 CSS 501
 Program 3 - Sudoku with Backtracking
*/

/**
This program will implement a set of classes to represent Sudoku puzzle. 
The program will accept a user input of 81 digit sequence ignoring non integer characters, which will 
placed within a 9x9 Sudoku grid and utilize a backtracking algorithm to solve the Sudoku. The goal of the game 
is to fill the grid with the numbers 1 – 9 exactly one in each row, column and 3x3 region. 
If the Sudoku can be solved, the program will display a solved Sudoku puzzle. 
If the Sudoku cannot be solved, the program will display "SUDOKU CANNOT BE SOLVED".
 The Puzzle class holds the representation of a Sudoku puzzle and the backtracking solving algorithm
 in order to solve the Sudoku puzzle. It does this by holding Square objects. 
 It also enforces constraints among the squares in a row, column, or block. 
*/

#include "Square.h"

#pragma once

using namespace std;

class Puzzle
{
private:
    /** Sets grid/row/column/block size */
    Square grid[9][9];
    int rowHash[9][10];
    int columnHash[9][10];
    int blockHash[3][3][10];

public:
    /** Constructor
    *   Method used to allocate memory for row, column and block
    *   inside of Sudoku grid */
    Puzzle();
   
    /** Method used to get value from corresponding cell location
    *   @param int row Locates cell at integer row
    *   @param int column Locates cell at integer column
    *   @pre Sudoky grid is implemented
    *   @post If sucessful, locates cell value at corresponding row/column location
    *   @returns Integer value from corresponding cell location */
    int get(int row, int column);

    /** Method used to set value to corresponding cell location
    *   @param int row Locates cell at integer row
    *   @param int column Locates cell at integer column
    *   @param inputs integer value
    *   @pre Sudoku grid is implemented
    *   @post If succesfull, inputs integer value at integer row/column
    *   @return True if value has sucessfully been placed inside of grid of
    *        corresponding row/column. False if value cannot be placed inside of Sudoku grid. */
    bool set(int row, int column, int value);
    
    /** Method used to remove values in 9x9 Sudoky grid.
    *   @pre Sudoku is not empty
    *   @post If successful, values inside of Sudoku are set to 0
    *   @return No return */
    void erase(int row, int column);

    /** Method used to determine size - number of variable entries within
    *   Sudoku grid
    *   @pre Sudoku grid is implemented
    *   @post Number variable entries within the Sudoku grid is determined
    *   @returns If successful, integer count of number of variables within
    *      Sudoky grid. */
    int size();  

    /** Method used to keep track of empty cells within the Sudoky Grid
    *   @pre Sudoku grid is implemented
    *   @post Counts number of empty cells within 9x9 Sudoku grid
    *   @returns integer count of empty cells within the 9x9 Sudoku grid */
    int numEmpty();

    /** Method used to solve Sudoku puzzle with a backtracking algorithm
    *   @param int row Used to traverse through individual row cell
    *   @param int column Used to traverse through individual column cell
    *   @pre Sudoku grid is not empty
    *   @post If Sudoku puzzle can be solved, it is succesfully solved with the numbers
    *       1 – 9 exactly one in each row and column
    *    @returns True if Sudoku puzzle is successfully solved - False otherwise */
    bool solve(int row, int column);

    /** Vector pair method of type integer used to store the
    *   value of next cell location
    *   @param int row Locates cell at determined row
    *   @param int column Locates cell at determined column
    *   @pre Sudoku grid is implemented
    *   @post If successful, stores cell value of next cell
    *   @return cell at int row/column */
    pair<int, int> nextSquare(int row, int column);

    /** Friend operator to Puzzle class
    *   Overloaded output used to display 9x9 cell grid containing a sequence
    *   of 81 digit sequence ranging from 0-9 unsolved or 1-9 when succesfully solved.
    *   @param out Output stream object where characters are inserted
    *   @param p Puzzle object is inserted in the form of a Sudoku
    *   @post if output is succesful, 9x9 cell grid containing a sequence of 81 digits
    *       randing from 0-9 unsolves or 1-9 when sucesfully solved. If 81 digit sequence
    *       cannot be solved, output should display "Sudoku cannot be solved".
    *    @return Display output stream */
    friend ostream& operator << (ostream& out, Puzzle p);

    /** Friend operator to Puzzle class
    *   Overloaded input used to accept 81 digit sequence ranging from 0-9
    *   @param istream& in input stream object where string is inserted
    *   @param Puzzle* p pointer to Puzzle object
    *   @post if output is succesful, 81 digits ranging from 0-9 is inserted
    *       as single digits. If integer equals to 0, flag is set as variable which allows
    *       for solving. If integer ranges from 1-9, flag is set as fixed which doesnt allow for
    *       changing in order to solve
    *   @return input */
    friend istream& operator>>(istream& in, Puzzle* p);
};
