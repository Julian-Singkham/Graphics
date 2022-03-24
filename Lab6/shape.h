/**
  ***********************************************************************************
  * @file   : shape.h
  * @brief  : Outline for shape base class
  *         : Lab 6: Event Driven Drawing
  *         : CS-3210/021 
  * @date   : APR 27 2021
  * @author : Julian Singkham
  ***********************************************************************************
**/
#ifndef SHAPE_H
#define SHAPE_H

#include "matrix.h"
#include "gcontext.h"

//=====================================Base Class====================================
class Shape{
	protected:
		int color;
		matrix point1;

		/**
		 * @brief Assigns properties from the given shape to this shape
		 * 		  Made protected so that the children of shape can't be set to
		 *        eachother. A triangle should not converted into a line.
		 * 
		 * @param rhs: The given shape to copy from
		 * 
		 * @retval A copy of the given shape
		 */
		virtual Shape &operator=(const Shape &rhs);

	public:

		/**
		 * @brief Read shape properties from a text file (stream)
		 * 
		 * @param is: Stream to read from
		 * 
		 * @retval NONE
		 */
		virtual std::istream &in(std::istream &is);

		/**
		 * @brief Parameterized constructor, it creates a shape with a color.
		 * 
		 * @param color_red: 3x8-bit value for red, green, blue
		 * 
		 * @retval NONE
		 */
		Shape(int color);

		/**
		 * @brief Copy constructor that copies the paramters from the given shape
		 * 
		 * @param from: shape to copy into the current shape.
		 * 
		 * @retval NONE
		 */
		Shape(const Shape &from);

		/**
		 * @brief Virtual constructor thats used to copy a shape
		 * 
		 * @param: NONE
		 * 
		 * @retval NONE
		 */
		virtual Shape *clone() = 0; 

		/**
		 * @brief Shape destructor, frees memory allocated to shape
		 *        Not currently used due to image handling deletion
		 * 
		 * @param: NONE
		 * 
		 * @retval NONE
		 */
		virtual ~Shape();

		/**
		 * @brief Draws the given shape
		 * 
		 * @param gc: GraphicsContext object that tells the shape where to draw
		 * 
		 * @retval NONE
		 */
		virtual void draw(GraphicsContext *gc) = 0; 

		/**
		 * @brief Print contents of shape into std.
		 *        Method made const to prevent modifying when outputting
		 *        
		 *        Shape_type
		 *          Color: 0x......
		 *          Point?: x y z
		 * 
		 * @param os: Stream to write to
		 * 
		 * @retval NONE
		 */
		virtual std::ostream &out(std::ostream &os) const;
};

#endif