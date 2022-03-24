/**
  ***********************************************************************************
  * @file   : stlFileReader.h
  * @brief  : Outline for the matrix multiplier
  *         : Lab 2: Arrays and Matrices
  *         : CS-3210/021 
  * @date   : MAR 23 2021
  * @author : Julian Singkham
  ***********************************************************************************
**/
#ifndef MULTIPLYM
#define MULTIPLYM

#include <stdexcept>

using namespace std;


class matrix_Exception:public runtime_error{
	public:
		matrix_Exception(string message):
		    runtime_error((string("A Matrix Error has occured: ") + 
		        message).c_str()) {}
};

void multiplym(double ** lhs, int rowsl,int colsl, double ** rhs, int rowsr,int colsr);

#endif