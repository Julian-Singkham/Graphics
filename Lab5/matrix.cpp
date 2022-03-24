/**
  ***********************************************************************************
  * @file   : matrixm.cpp
  * @brief  : Matrix
  *         : Lab 5: Shapes Classes and Shapes Container
  *         : CS-3210/021 
  * @date   : MAR 23 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  * This API handles the creation, deletion, and =,+,* operators of a matrix as well
  * as retrieving matrix values using []. In essence the double matrix used in this
  * API is an array of arrays where the **double matrix points to rows *double arrays
  * that then point to col elements.
  ***********************************************************************************
**/
#include "matrix.h"
#include <string>
#include <cmath>

//=======================================Public======================================
/**
 * @brief Makes the insertion operator a friend so it can access matrix.
 * Basically allows the matrix to be printed to std.
 * 
 * @param os: Stream to write to.
 * @param rhs: Reference to the matrix that is being printed.
 *  
 * @retval Stream containing the matrix printout.
 */
std::ostream& operator<<(std::ostream& os, const matrix& rhs){
	for(int i = 0; i < rhs.rows; i++){
        os << "|";
        for(int j = 0; j < rhs.cols; j++){
            double temp = rhs.the_matrix[i][j];
            os << temp << "|";
        }
        os << std::endl;
    }
	return os;
}

/**
 * @brief Matrix constructor, it creates a matrix of given dimensions
 * with clear (zeroed) cells. Throws error if dimensions are not possible (<1).
 * 
 * @param rows: How many rows in the matrix.
 * @param cols: How many columns in the matrix.
 * 
 * @retval NONE
 */
matrix::matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols){  
	if(rows < 1 || cols < 1)
		throw matrix_Exception("p-constructor has bad arguments.");

	the_matrix = new double*[rows];//Allocates memory to the # of rows

	//Allocate memory for each row of the array to the # of columns
	//Basically creates a 1-D array of 1-D arrays
    for(int i = 0; i < rows; i++)
        the_matrix[i] = new double[cols];

	clear(); //Fill matrix with zeroes
}

/**
 * @brief Copy constructor that makes a new matrix from a given one.
 * 
 * @param from: matrix to copy into the new matrix.
 * 
 * @retval A copy of the given matrix.
 */
matrix::matrix(const matrix& from) : rows(from.rows), cols(from.cols){
	the_matrix = new double*[rows];//Allocates memory to the # of rows

	//Allocate memory for each row of the array to the # of columns
	//Basically creates a 1-D array of 1-D arrays
    for(int i = 0; i < rows; i++)
        the_matrix[i] = new double[cols];

	//Copy values from "from" into new matrix
	for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            the_matrix[i][j] = from[i][j];
}

/**
 * @brief Frees allocated memory form matrix
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
matrix::~matrix(){
	for(int i = 0; i <  rows; i++)
        delete[] the_matrix[i]; //Delete each row of the matrix
    delete[] the_matrix; //Delete the matrix itself
}

/**
 * @brief Named constructor, it creates a square identity matrix 
 * of given size.
 * 
 * Identity matrix is a matrix that is all zeros expect when 
 * row#=col#, then it is 1.
 * // 1 0 0 [0][0] = 1
 * // 0 1 0 [1][1] = 1
 * // 0 0 1 [2][2] = 1
 * 
 * @param size: Square dimensions of the matrix.
 * 
 * @retval The square identity matrix.
 */
matrix matrix::identity(unsigned int size){
	if(size == 0)
		throw matrix_Exception("Can not create an identity matrix of size 0.");

	matrix return_matrix(size, size);
	for(int i = 0; i < size; i++)
		return_matrix[i][i] = 1.0;
	return return_matrix;
}

/**
 * @brief Assigns the matrix to the value stored in the given matrix.
 * 
 * @param rhs: The given matrix to copy from.
 * 
 * @retval A copy of the given matrix.
 */
matrix& matrix::operator=(const matrix& rhs){
	//Verify matrices match in size
	if(rows != rhs.rows || cols != rhs.cols){
		for(int i = 0; i <  rows; i++)
        	delete[] the_matrix[i]; //Delete each row of the matrix
    	delete[] the_matrix; //Delete the matrix itself

		rows = rhs.rows;
		cols = rhs.cols;
		the_matrix = new double*[rows];//Allocates memory to the # of rows

		//Allocate memory for each row of the array to the # of columns
		//Basically creates a 1-D array of 1-D arrays
		for(int i = 0; i < rows; i++)
			the_matrix[i] = new double[cols];
	}
	//Copy values from rhs into current matrix
	for(int i = 0; i < rows; i++)
    	for(int j = 0; j < cols; j++)
        	the_matrix[i][j] = rhs[i][j];

	return *this;
}

/**
 * @brief Matrix addiiton. The lhs and rhs must be the same size.
 * 
 * @param rhs: The right hand side matrix.
 * 
 * @retval The resulting matrix after addition.
 */
matrix matrix::operator+(const matrix& rhs) const{
	//Verify matrices match in size
	if(rows != rhs.rows || cols != rhs.cols)
		throw matrix_Exception("Size mismatch - The column/row of the left matrix does"
                              " not match the column/row of the right matrix:");

	matrix return_matrix(rows, cols);

	for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            return_matrix[i][j] = the_matrix[i][j] + rhs[i][j];

	return return_matrix;
}

/**
 * @brief Matrix multiplication. 
 * The lhs column size and rhs row size must match.
 * 
 * @param rhs: The right hand side matrix.
 * 
 * @retval The resulting matrix after multiplication.
 * Dimension: lhs.rows x rhs.cols.
 */
matrix matrix::operator*(const matrix& rhs) const{
	//Verify matrices match in size
	if(cols != rhs.rows)
		throw matrix_Exception("Size mismatch - The column of the left matrix does"
                              " not match the row of the right matrix:");

	matrix return_matrix(rows, rhs.cols);

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < rhs.cols; ++j)
			for (int k = 0; k < rhs.cols; ++k)
                return_matrix[i][j] += the_matrix[i][k] * rhs[k][j];
	return return_matrix;
}

/**
 * @brief Matrix scaler multiplication. 
 * This only supports matrix * 5, not 5 * matrix.
 * 
 * @param scale: Value to scale the matrix.
 * 
 * @retval The scaled matrix.
 */
matrix matrix::operator*(const double scale) const{
	matrix return_matrix(rows, cols);

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
            return_matrix[i][j] = the_matrix[i][j] * scale;
	return return_matrix;
}

/**
 * @brief This allows access of the matrix elements by using [].
 * 
 * @param row: The desired row of the matrix.
 * 
 * @retval A pointer to the desired element of the matrix.
 */
double* matrix::operator[](unsigned int row){
	//Verify row is within bounds
	if (row >= rows || row < 0)
		throw matrix_Exception("Size mismatch - The requested row is out of bounds.");
	
	double *ret = the_matrix[row];
	return ret;
}

/**
 * @brief This allows access of the matrix elements by using []. 
 * Const version
 * 
 * @param row: The desired row of the matrix.
 * 
 * @retval A pointer to the desired element of the matrix.
 */
double* matrix::operator[](unsigned int row) const{
	//Verify row is within bounds
	if (row >= rows || row < 0)
		throw matrix_Exception("Size mismatch - The requested row is out of bounds.");
	
	double *ret = the_matrix[row];
	return ret;
}

/**
 * @brief Zeroes the elements of the matrix.
 * 
 * @param: None
 * 
 * @retval None
 */
void matrix::clear(){
	for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            the_matrix[i][j] = 0.0;
	return;
}

//=======================================Global======================================
/**
 * @brief Matrix scaler multiplication. 
 * This only supports matrix * 5, not 5 * matrix.
 * 
 * @param scale: Value to scale the matrix.
 * @param rhs: The matrix to apply the scaling.
 * 
 * @retval The scaled matrix.
 */
matrix operator*(const double scale, const matrix& rhs){
	matrix return_matrix(rhs);
	return_matrix = rhs * scale;
	return return_matrix;
}

