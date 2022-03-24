/**
  ***********************************************************************************
  * @file   : main.cpp
  * @brief  : Main Program
  *         : Lab 1: C++ Console Program
  *         : CS-3210/021 
  * @date   : MAR 16 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  *
  * The purpose of this progarm is to print the coordinates of each facet's verticies
  * given a STL file. A Facet is a triangular polygon that makes up the 3-D object.
  * Additonally at the end the total number of facets, and the max&min values for each
  * axis are printed to stdout.
  * 
  * See Main comment for instructions.
  * 
  ***********************************************************************************
**/

#include "StlFileReader.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//======================================Methods=======================================
 /**
  * @brief The program entry point
  * 
  * @param args: Pointer to the given arguements
  *        args[1] = Name of STL file
  * 
  * @retval NOT USED
  */
 int main(int argc, char **argv){
    //Verify the name of the STL was inputted
    if (argc < 2){
        cout << "Error: Please input the name of the STL file " << endl;
    }
    else{
        char *filename = argv[1];
        stlFileReader fileReader(filename);
    }
    return 0;
}