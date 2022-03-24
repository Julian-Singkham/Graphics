/**
  ***********************************************************************************
  * @file   : main.cpp
  * @brief  : Main Program
  *         : Lab 3: Matrix
  *         : CS-3210/021 
  * @date   : MAR 30 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  *
  * This program handles the creation of a matrix and the +,=, and * operators.
  * 
  * 
  ***********************************************************************************
**/
#include<iostream>
#include "matrix.h"

using namespace std;
//======================================Methods=======================================
 /**
  * @brief The program entry point. Assume tests are successful unles otherwise stated
  * by "Failed" or error is thrown.
  * 
  * @param NOT USED
  * 
  * @retval NOT USED
  */
int main(){
	// Test malforned matrix creation
	cout << "Test malforned matrix creation" << endl;
	try{
        matrix m1(0,-2);
		cout << "Failed" << endl;
    }
    catch(matrix_Exception& e){
        cout << e.what() << endl;
    }
	cout << endl;
	cout << endl;

	// Test proper matrix creation
	cout << "Test proper matrix creation" << endl;
	matrix m_out(2,2);
	try{
		cout << m_out << endl;
		if(m_out[0][0] != 0 && m_out[0][1] != 0 && m_out[1][0] != 0 
		   && m_out[0][0] != 0)
			cout << "Failed" << endl;
    }
    catch(matrix_Exception& e){
        cout << e.what() << endl;
    }
	cout << endl;
	cout << endl;

	// Test malforned matrix multiplication
	cout << "Test malforned matrix multiplication" << endl;
    matrix m1(2,2);
	m1[0][0] = 0;
	m1[0][1] = 1;
	m1[1][0] = 2;
	m1[1][1] = 3;
	cout << m1 << endl;

	matrix m2(3,2);
	m2[0][0] = 4;
	m2[0][1] = 5;
	m2[1][0] = 6;
	m2[1][1] = 7;
	m2[2][0] = 8;
	m2[2][1] = 9;
	cout << m2 << endl;

	m_out = matrix::identity(3);

    try{
        m_out = m1*m2;
		cout << "Failed" << endl;
    }
    catch(matrix_Exception& e){
        cout << e.what() << endl;
    }
	cout << endl;
	cout << endl;

    //Test proper matrix multiplication
	cout << "Test proper matrix multiplication" << endl;
	matrix m3(2,3);
	m3[0][0] = 0;
	m3[0][1] = 1;
	m3[0][2] = 2;
	m3[1][0] = 3;
	m3[1][1] = 4;
	m3[1][2] = 5;
	cout << m3 << endl;

	cout << m2 << endl;

    try{
        m_out = m3*m2;
		cout << m_out << endl;
		if(m_out[0][0] != 6 && m_out[0][1] != 7 && m_out[1][0] != 36 
		   && m_out[0][0] != 43)
			cout << "Failed" << endl;
    }
    catch(matrix_Exception& e){
        cout << e.what() << endl;
    }
	cout << endl;
	cout << endl;

	//Test improper + operator
	cout << "Test improper + operator" << endl;
	cout << m1 << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	try{
        m_out = m1 + m3;
		cout << "Failed" << endl;
    }
    catch(matrix_Exception& e){
        cout << e.what() << endl;
    }
	cout << endl;
	cout << endl;

	//Test proper + operator
	cout << "Test proper + operator" << endl;
	cout << m1 << endl;
	m2 = matrix::identity(2);
	cout << m2 << endl;

	try{
        m_out = m1 + m2;
		cout << m_out << endl;

		if(m_out[0][0] != 1 && m_out[0][1] != 1 && m_out[1][0] != 2 
		   && m_out[0][0] != 4)
			cout << "Failed" << endl;
    }
    catch(matrix_Exception& e){
        cout << e.what() << endl;
    }
	cout << endl;
	cout << endl;

	//Test scale multiplication
	cout << "Test scale multiplication of 5" << endl;
	cout << m1 << endl;

	m_out = m1 * 5;
	cout << m_out << endl;
	if(m_out[0][0] != 0 && m_out[0][1] != 5 && m_out[1][0] != 10 
	   && m_out[0][0] != 15)
		cout << "Failed" << endl;
	cout << endl;
	cout << endl;
}
