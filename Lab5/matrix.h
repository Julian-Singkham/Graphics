/**
  ***********************************************************************************
  * @file   : matrix.h
  * @brief  : Outline for matrix
  *         : Lab 5: Shapes Classes and Shapes Container
  *         : CS-3210/021 
  * @date   : MAR 30 2021
  * @author : Dr. Darrin Rothe
  * @author : Julian Singkham (modified)
  ***********************************************************************************
**/
 
#ifndef MATRIX_H
#define MATRIX_H
 
#include <iostream> 	// for std::ostream
#include <stdexcept>	// for std::runtime_error
#include <string>		// used in matrix_Exception

/**
 * @brief Custom exception used in the matrix class.
 */
class matrix_Exception:public std::runtime_error{
	public:
		matrix_Exception(std::string message):
		      std::runtime_error((std::string("A Matrix Error has occured: ") + 
		        message).c_str()) {}
};

class matrix
{
	public:
		/**
     * @brief Makes the insertion operator a friend so it can access matrix.
		 * Basically allows the matrix to be printed to std.
     * 
     * @param os: Stream to write to.
		 * @param rhs: Reference to the matrix that is being printed.
     * 
     * @retval Stream containing the matrix printout.
     */
		friend std::ostream& operator<<(std::ostream& os, const matrix& rhs);
 
		/**
     * @brief Parameterized constructor, it creates a matrix of given dimensions
		 * with clear (zeroed) cells.
     * 
     * @param rows: How many rows in the matrix.
		 * @param cols: How many columns in the matrix.
     * 
     * @retval NONE
     */
		matrix(unsigned int rows, unsigned int cols);
 
		/**
     * @brief Copy constructor that makes a new matrix from a given one.
     * 
     * @param from: matrix to copy into the new matrix.
     * 
     * @retval A copy of the given matrix.
     */
		matrix(const matrix& from);
 
		/**
     * @brief Frees allocated memory from the matrix.
     * 
     * @param: NONE
     * 
     * @retval NONE
     */
		~matrix();

		/**
     * @brief Named constructor, it creates an identity matrix of given size.
		 * 
		 * Identity matrix is a matrix that is all zeros expect when 
		 * row#=col#, then it is 1.
		 * // 1 0 0 [0][0] = 1
		 * // 0 1 0 [1][1] = 1
	 	 * // 0 0 1 [2][2] = 1
     * 
     * @param size: Square dimensions of the matrix.
     * 
     * @retval The identity matrix.
     */
		static matrix identity(unsigned int size);
		
		/**
     * @brief Assigns the matrix to the value stored in the given matrix.
     * 
     * @param rhs: The given matrix to copy from.
     * 
     * @retval A copy of the given matrix.
     */
		matrix& operator=(const matrix& rhs);
		
		/**
     * @brief Matrix addiiton. The lhs and rhs must be the same size.
     * 
     * @param rhs: The right hand side matrix.
     * 
     * @retval The resulting matrix after addition.
     */
		matrix operator+(const matrix& rhs) const;
 
		/**
     * @brief Matrix multiplication. 
     * The lhs column size and rhs row size must match.
     * 
     * @param rhs: The right hand side matrix.
     * 
     * @retval The resulting matrix after multiplication.
     * Dimension: lhs.rows x rhs.cols.
     */
		matrix operator*(const matrix& rhs) const;
 

		/**
     * @brief Matrix scaler multiplication. 
     * This only supports matrix * 5, not 5 * matrix.
     * 
     * @param scale: Value to scale the matrix.
     * 
     * @retval The scaled matrix.
     */
		matrix operator*(const double scale) const;
  
		/**
     * @brief This allows access of the matrix elements by using [].
     * 
     * @param row: The desired row of the matrix.
     * 
     * @retval A pointer to the desired element of the matrix.
     */
		double* operator[](unsigned int row);
 
		/**
     * @brief This allows access of the matrix elements by using []. 
     * Const version
     * 
     * @param row: The desired row of the matrix.
     * 
     * @retval A pointer to the desired element of the matrix.
     */
		double* operator[](unsigned int row) const;
		
		/**
     * @brief Zeroes the elements of the matrix.
     * 
     * @param: None
     * 
     * @retval None
     */
		void clear();
	private:
		//The data
		double** the_matrix;
		unsigned int rows;
		unsigned int cols;
};
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
matrix operator*(const double scale, const matrix& rhs);

#endif
