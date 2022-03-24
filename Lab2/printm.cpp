/**
  ***********************************************************************************
  * @file   : printm.cpp
  * @brief  : matrix printer
  *         : Lab 2: Arrays and Matrices
  *         : CS-3210/021 
  * @date   : MAR 23 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  *
  * 
  * 
  ***********************************************************************************
**/

#include "printm.h"
#include <cfloat>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//=======================================Methods=====================================
/**
 * @brief Prints the contents of a matrix (2-D array)
 * 
 * @param: **m: Pointer to a double matrix
 * @param: rows: How many rows the matrix has
 * @param: cols: How many columns the matrix has
 * 
 * @retval NONE
 */
void printm(double **m, int rows, int cols){
    for(int i = 0; i < rows; i++){
        cout << "|";
        for(int j = 0; j < cols; j++){
            double temp = m[i][j];
            cout << temp << "|";
        }
        cout << endl;
    }
}