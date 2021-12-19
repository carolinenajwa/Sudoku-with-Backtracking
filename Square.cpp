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
 The Square class will be nested within the Puzzle Class. The Square object holds all 
 of the information associated with one location in the puzzle.
*/

#include <cstring>
#include <vector>

#include "Square.h"


/** Method used to get the state of the corresponding value inside of cell
 *	@pre value located inside of cell
 *	@post gets state of value inside of cell
 *	@returns If successful, returns state of value inside of cell as
 *		NOT_DEFINED, FIXED, or VARIABLE */
string Square::getFlag() 
{ 
	return flag_; 
}
	
/** Method used to set state of the corresponding value inside of cell
 *	as NOT_DEFINED, FIXED, or VARIABLE
 *	@param input string flag NOT_DEFINED, FIXED, or VARIABLE
 *	@pre value located inside of cell
 *	@post sets state of value inside of cell
 *	@returns If successful, sets string indiciting state of value inside of cell */
void Square::setFlag(string flag) 
{ 
	this->flag_ = flag; 
}

/** Method used to get current value
 *	@pre Sudoku grid allocated 
 *	@post If successful, method gets the current value
 *	@returns if current value is set then returns current value, 
 *		if no value is set - returns -1 */
int Square::getValue() 
{ 
	return (value_ == 0 ? -1 : value_); 
}

/** Method used to set value
 *	@param int value input into location
 *	@pre Sudoku grid allocated
 *	@post if successful, value is set into cell */
void Square::setValue(int value) 
{ 
	this->value_ = value; 
}
