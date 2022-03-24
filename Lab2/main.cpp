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
    double **matrix_l = new double*[rowsl];//Allocates memory to the # of rows

    //Allocate memory for each row of the array to the # of columns
    for(int i = 0; i < rowsl; i++)
        matrix_l[i] = new double[colsl];
    
    //Fill the 2D array with numbers, 0-4
    for(int i = 0; i < rowsl; i++)
        for(int j = 0; j < colsl; j++)
            matrix_l[i][j] = (j+1)+3*i;
    printm(matrix_l, rowsl, colsl);
    cout << endl;

    int rowsr = 3;
    int colsr = 2;
    double **matrix_r = new double*[rowsr]; //Allocates memory to the # of rows

    //Allocate memory for each row of the array to the amount of columns
    for(int i = 0; i < rowsr; i++)
        matrix_r[i] = new double[colsr];

    //Fill the 2D array with numbers, 5-10
    for(int i = 0; i < rowsr; i++)
        for(int j = 0; j < colsr; j++)
            matrix_r[i][j] = (j+7)+2*i;
    printm(matrix_r, rowsr, colsr);
    cout << endl;

    try{
        multiplym(matrix_l, rowsl, colsl, matrix_r, rowsr, colsr);
    }
    catch(matrix_Exception& e){
        cout << e.what() << endl;
    }

    //Test proper matrix
    for (int i = 0; i <  rowsl; i++)
        delete[] matrix_l[i];
    delete[] matrix_l;

    rowsl = 2;
    colsl = 3;
    matrix_l = new double*[rowsl]; //Allocates memory to the # of rows

    //Allocate memory for each row of the array to the amount of columns
    for(int i = 0; i < rowsl; i++)
        matrix_l[i] = new double[colsl];

    for(int i = 0; i < rowsl; i++)
        for(int j = 0; j < colsl; j++)
            matrix_l[i][j] = (double) (j+1)+3*i;
    printm(matrix_l, rowsl, colsl);
    cout << endl;
    printm(matrix_r, rowsr, colsr);
    cout << endl;

    try{
        multiplym(matrix_l, rowsl, colsl, matrix_r, rowsr, colsr);
    }
    catch(matrix_Exception& e){
        cout << e.what() << endl;
    }

    //Delete Arrays
    for (int i = 0; i <  rowsl; i++)
        delete[] matrix_l[i];
    delete[] matrix_l;

    for (int i = 0; i <  rowsr; i++)
        delete[] matrix_r[i];
    delete[] matrix_r;
}