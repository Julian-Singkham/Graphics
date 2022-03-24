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
//row col
void multiplym(double ** lhs, int rowsl,int colsl, double ** rhs, int rowsr,int colsr){
	if (colsl != rowsr)
		throw matrix_Exception("Size mixmatch - The column of the left matrix does not"
                              "match therow of the right matrix:");

    double* matrix_m = new double[rowsl*colsr];
    double* matrix_l = *lhs;
    double* matrix_r = *rhs;

	for (uint i = 0; i < rowsl; ++i)
		for (uint j = 0; j < colsr; ++j)
			for (uint k = 0; k < colsl; ++k)
                matrix_m[i*colsr+j] += matrix_l[i*colsl+k] * matrix_r[k*colsr+j];

    printM(&matrix_m, rowsl, colsr);
    delete[] matrix_m;
	return;
}