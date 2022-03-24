/**
  ***********************************************************************************
  * @file   : main.cpp
  * @brief  : Main Program
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
#include "multiplym.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//======================================Methods=======================================
 /**
  * @brief The program entry point
  * 
  * @param NOT USED
  * 
  * @retval NOT USED
  */
 int main(int argc, char **argv){
    
    // Test malforned matrix
    int rowsl = 2;
    int colsl = 2;
    double *matrix_l = new double[rowsl*colsl];

    for(int i = 0; i < rowsl; i++)
        for(int j = 0; j < colsl; j++)
            matrix_l[i*colsl+j] = (double) (j+1)+3*i;
    printM(&matrix_l, rowsl, colsl);
    cout << endl;

    int rowsr = 3;
    int colsr = 2;
    double *matrix_r = new double[rowsr*colsr];

    for(int i = 0; i < rowsr; i++)
        for(int j = 0; j < colsr; j++)
            matrix_r[i*colsr+j] = (double) (j+7)+2*i;
    printM(&matrix_r, rowsr, colsr);
    cout << endl;

    try{
        multiplym(&matrix_l, rowsl, colsl, &matrix_r, rowsr, colsr);
    }
    catch(matrix_Exception& e){
        cout << e.what() << endl;
    }

    //Test proper matrix
    delete[] matrix_l;
    rowsl = 2;
    colsl = 3;
    matrix_l = new double[rowsl*colsl];

    for(int i = 0; i < rowsl; i++)
        for(int j = 0; j < colsl; j++)
            matrix_l[i*colsl+j] = (double) (j+1)+3*i;
    printM(&matrix_l, rowsl, colsl);
    cout << endl;
    printM(&matrix_r, rowsr, colsr);
    cout << endl;

    try{
        multiplym(&matrix_l, rowsl, colsl, &matrix_r, rowsr, colsr);
    }
    catch(matrix_Exception& e){
        cout << e.what() << endl;
    }

    delete[] matrix_r;
    delete[] matrix_l;
}