/**
  ***********************************************************************************
  * @file   : printm.h
  * @brief  : Outline for matrix printer
  *         : Lab 2: Arrays and Matrices
  *         : CS-3210/021 
  * @date   : MAR 13 2021
  * @author : JulianSingkham
  ***********************************************************************************
**/

#ifndef PRINTM
#define PRINTM

using namespace std;

/**
 * @brief Prints the contents of a matrix (2-D array)
 * 
 * @param: **m: Pointer to a double matrix
 * @param: rows: How many rows the matrix has
 * @param: cols: How many columns the matrix has
 * 
 * @retval NONE
 */
void printM(double **m, int rows, int cols);

#endif