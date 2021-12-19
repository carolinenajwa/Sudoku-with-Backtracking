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
 Sudoku puzzle user interface of Sudoku with Backtracking program
 */

#include <iostream>
#include <cstring>
#include <vector>

#include "Puzzle.h"

using namespace std;

int main()
{
    Puzzle board;
    // Request Sudoku input from user
    cout << "ENTER THE SUDOKU:" << endl;
    cin >> (&board);

    bool result = board.solve(0, 0);

    // If Sudoku input cannot be solved return false 
    if (result == false)
    {
        cout << "SUDOKU CANNOT BE SOLVED";
    }
    // If Sudoku can be solved, display solved Sudoku puzzle
    else
    {
        cout << endl << board << endl;
    }

    return 0;
}
