/**
  ***********************************************************************************
  * @file   : matrixm.cpp
  * @brief  : matrix multiplier
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

#include "multiplym.h"
#include "printm.h"
#include <cfloat>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//=======================================Methods=====================================

// mxn * nxp = mxp
// inner values must equal
void multiplym(double ** lhs, int rowsl,int colsl, double ** rhs, int rowsr,int colsr){
	if (colsl != rowsr)
		throw matrix_Exception("Size mismatch - The column of the left matrix does not"
                              "match the row of the right matrix:");

  double **matrix_m = new double*[rowsl];//Allocates memory to the # of rows

  //Allocate memory for each row of the array to the # of columns
  for(int i = 0; i < rowsl; i++)
      matrix_m[i] = new double[colsr];

	for (int i = 0; i < rowsl; ++i)
		for (int j = 0; j < colsr; ++j)
			for (int k = 0; k < colsl; ++k)
                matrix_m[i][j] += lhs[i][k] * rhs[k][j];

  printm(matrix_m, rowsl, colsr);

  for (int i = 0; i <  rowsl; i++)
        delete[] matrix_m[i];
  delete[] matrix_m;
  
	return;
}