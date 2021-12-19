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


#include "Puzzle.h"
#include "Square.h"

#include <cstring>
#include <vector>

using namespace std;

/** Constructor
 *   Method used to allocate memory for row, column and block
 *   inside of Sudoku grid */
Puzzle::Puzzle()
{
    memset(rowHash, 0, sizeof(rowHash));
    memset(columnHash, 0, sizeof(columnHash));
    memset(blockHash, 0, sizeof(blockHash));
}

/** Method used to get value from corresponding cell location
*   @param int row Locates cell at integer row
*   @param int column Locates cell at integer column
*   @pre Sudoky grid is implemented
*   @post If sucessful, locates cell value at corresponding row/column location
*   @returns Integer value from corresponding cell location */
int Puzzle::get(int row, int column) 
{ 
    return grid[row][column].getValue(); 
}

/** Method used to set value to corresponding cell location
*    @param int row Locates cell at integer row
*    @param int column Locates cell at integer column
*    @param inputs integer value
*    @pre Sudoku grid is implemented
*    @post If succesfull, inputs integer value at integer row/column
*    @return True if value has sucessfully been placed inside of grid of
*        corresponding row/column. False if value cannot be placed inside of Sudoku grid. */
bool Puzzle::set(int row, int column, int value)
{
    // If there is no duplicate of value in the same row, column, or block
    if (!rowHash[row][value] && !columnHash[column][value] && !blockHash[row / 3][column / 3][value])
    {
        rowHash[row][value] = 1;
        columnHash[column][value] = 1;
        blockHash[row / 3][column / 3][value] = 1;
        grid[row][column].setValue(value);
        return true;
    }
    else
    {
        // Cannot set corresponding cell to value
        return false;
    }
}

/** Method used to determine size - number of variable entries within
*    Sudoku grid
*   @pre Sudoku grid is implemented
*   @post Number variable entries within the Sudoku grid is determined
*   @returns If successful, integer count of number of variables within 
*       Sudoky grid. */
int Puzzle::size() 
{ 
    int variable_entries = 0;
    // Count number of cell values set to VARIABLE
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j].getFlag() == "VARIABLE")
                variable_entries++;

    return variable_entries;
}

/** Method used to keep track of empty cells within the Sudoky Grid
*   @pre Sudoku grid is implemented
*   @post Counts number of empty cells within 9x9 Sudoku grid
*   @returns integer count of empty cells within the 9x9 Sudoku grid */
int Puzzle::numEmpty() {
    // Store count for empty entries 
    int empty_entries = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j].getValue() == 0)
                empty_entries++;

    return empty_entries;
}

/** Vector pair method of type integer used to store the 
*   value of next cell location
*   @param int row Locates cell at determined row
*   @param int column Locates cell at determined column
*   @pre Sudoku grid is implemented
*   @post If successful, stores cell value of next cell
*   @return cell at int row/column */
pair<int, int> Puzzle::nextSquare(int row, int column)
{
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            // If cell at location is empty
            if (grid[r][c].getValue() == -1)
            {
                if (r == row && c == column) {
                    continue;
                }
                return { r, c };
            }
        }
    }
    return { 9, 9 };
}

/** Method used to remove values in 9x9 Sudoky grid.
*   @pre Sudoku is not empty
*   @post If successful, values inside of Sudoku are set to 0
*   @return No return */
void Puzzle::erase(int row, int column)
{
    int value = grid[row][column].getValue();
    rowHash[row][value] = 0;
    columnHash[column][value] = 0;
    blockHash[row / 3][column / 3][value] = 0;
    grid[row][column].setValue(0);

}

/** Friend operator to Puzzle class
*   Overloaded output used to display 9x9 cell grid containing a sequence
*   of 81 digit sequence ranging from 0-9 unsolved or 1-9 when succesfully solved.
*   @param out Output stream object where characters are inserted
*   @param p Puzzle object is inserted in the form of a Sudoku
*   @post if output is succesful, 9x9 cell grid containing a sequence of 81 digits
*       randing from 0-9 unsolves or 1-9 when sucesfully solved. If 81 digit sequence
*       cannot be solved, output should display "Sudoku cannot be solved".
*   @return Display output stream */
ostream& operator << (ostream& out, Puzzle p) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // Place block dividers
            if (j == 3 || j == 6) {
                out << "|";
            }
            if (j == 0 || j == 3 || j == 6)
                out << max(p.grid[i][j].getValue(), 0);
            else
                out << " " << max(p.grid[i][j].getValue(), 0);

        }
        out << endl;
        // Place block dividers
        if (i == 2 || i == 5) {
            for (int i = 0; i < 18; i++) {
                if (i == 5 || i == 11)
                    cout << "+";
                else
                    cout << "-";
            }
            out << endl;
        }
    }
    return out;
}

/** Friend operator to Puzzle class
*   Overloaded input used to accept 81 digit sequence ranging from 0-9
*   @param istream& in input stream object where string is inserted
*   @param Puzzle* p pointer to Puzzle object
*   @post if output is succesful, 81 digits ranging from 0-9 is inserted
*       as single digits. If integer equals to 0, flag is set as variable which allows
*       for solving. If integer ranges from 1-9, flag is set as fixed which doesnt allow for 
*       changing in order to solve
*   @return input */
istream& operator>>(istream& in, Puzzle* p) {
    string s;
    in >> s;
    int counter = 0;
    int i = 0;
    // While string length is larger than 0 and smaller than 81 digits
    while (i < s.length() && counter != 81)
    {
        if (int(s[i] - '0') >= 0 && int(s[i] - '0') <= 9)
        {
            bool res = (*p).set(counter / 9, counter % 9, int(s[i] - '0'));
            // If digit is equiv. to 0, set flag as VARIABLE
            if (int(s[i] - '0') == 0)
            {
                (*p).grid[counter / 9][counter % 9].setFlag("VARIABLE");
            }
            // If digit is equiv. to digit between 1-9, set flag as FIXED
            else
            {
                (*p).grid[counter / 9][counter % 9].setFlag("FIXED");
            }
            counter++;
        }
        i++;
    }
    return in;
}

/** Method used to solve Sudoku puzzle with a backtracking algorithm
*   @param int row Used to traverse through individual row cell
*   @param int column Used to traverse through individual column cell
*    @pre Sudoku grid is not empty
*    @post If Sudoku puzzle can be solved, it is succesfully solved with the numbers
*        1 – 9 exactly one in each row and column
*   @returns True if Sudoku puzzle is successfully solved - False otherwise */
bool Puzzle::solve(int row = 0, int column = 0)
{
    // If the cell provided is out of bound
    if (row == 9 && column == 9)
    {
        // Then Sudoku is solved
        return true;
    }

    pair<int, int> nextCell = nextSquare(row, column);
    int nextRow = nextCell.first;
    int nextColumn = nextCell.second;

    if (grid[row][column].getFlag() == "FIXED")
    {
        // Current location has a fixed value
        return solve(nextRow, nextColumn);
    }

    // Try all numbers
    for (int c = 1; c <= 9; c++)
    {
        bool res = set(row, column, c);

        // Set unsuccessful
        if (res == false) 
        {
            continue;
        }

        bool result = solve(nextRow, nextColumn);

        if (result == true)
            return true;

        // Revert all changes
        erase(row, column);
    }
    return false;
}
