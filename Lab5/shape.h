/**
  ***********************************************************************************
  * @file   : shape.h
  * @brief  : Outline for shape base class
  *         : Lab 5: Shapes Classes and Shapes Container
  *         : CS-3210/021 
  * @date   : APR 27 2021
  * @author : Julian Singkham
  ***********************************************************************************
**/

/*
 * The copy consutructor and = operator are made const so that the rhs shape does not
 * get modified during the function call. 
 * 
 * Out operator is made const so that the shape parameters can't be modified from 
 * printing to stream.
 * 
 * In general, only functions that access data, and not modify, are made const to
 * protect the data they are accessing.
 * 
 * Since all shapes have a point1 (origin) and a color, the shape class holds
 * onto those values. This allows for less code as the parent can take care of
 * assigning the color and point1 values.
*/

#ifndef SHAPE_H
#define SHAPE_H

#include "matrix.h"
#include "gcontext.h"

//=====================================Base Class====================================
class shape{
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
		virtual shape &operator=(const shape &rhs);

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
		shape(int color);

		/**
		 * @brief Copy constructor that copies the paramters from the given shape
		 * 
		 * @param from: shape to copy into the current shape.
		 * 
		 * @retval NONE
		 */
		shape(const shape &from);

		/**
		 * @brief Virtual constructor thats used to copy a shape
		 * 
		 * @param: NONE
		 * 
		 * @retval NONE
		 */
		virtual shape *clone() = 0; 

		/**
		 * @brief Shape destructor, frees memory allocated to shape
		 *        Not currently used due to image handling deletion
		 * 
		 * @param: NONE
		 * 
		 * @retval NONE
		 */
		virtual ~shape();

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

//Outline for future shapes.


// class circle : public shape{
//     private:
//         //points to draw to
//         matrix point2;

// 	public:
//         /**
//          * @brief Parameterized constructor, it creates a circle with a color.
//          * 
//          * @param color: 3x8-bit value for red, green, blue
//          * 
//          * @retval NONE
//          */
//         circle(double x0, double y0,int color);

//         /**
//          * @brief Copy constructor that copies the paramters from the given circle
//          * 
//          * @param from: Circle to copy into the current circle.
//          * 
//          * @retval None
//          */
// 		circle(const circle &from);

//          /**
//          * @brief Constructor that makes a new circle from a stream
//          * 
//          * @param is: Input stream that contains circle parameters
//          * 
//          * @retval NONE
//          */
// 		circle(std::istream &is);

//         /**
//          * @brief Virtual constructor thats used to copy a shape 
//          * 
//          * @param: NONE
//          * 
//          * @retval NONE
//          */
// 		shape *clone(); 

// 		/**
//          * @brief Circle destructor, frees memory allocated to circle
//          *        Not currently used due to image handling deletion
//          *
//          * @param: NONE
//          * 
//          * @retval NONE
//          */
// 		~circle();

//         /**
//          * @brief Draws the given circle
//          * 
//          * @param gc: GraphicsContext object that tells the shape where to draw
//          * 
//          * @retval NONE
//          */
// 		void draw(GraphicsContext *gc); 

//         /**
//          * @brief Print contents of circle into std.
//          *        Method made const to prevent modifying when outputting
//          * 
//          * @param os: Stream to write to
//          * 
//          * @retval NONE
//          */
// 		virtual std::ostream &out(std::ostream &os) const;

//         /**
//          * @brief Read circle properties from a text file (stream)
//          * 
//          * @param is: Stream to read from
//          * 
//          * @retval NONE
//          */
// 		virtual std::istream &in(std::istream &is);
// };

// class rectangle : public shape{
//     private:
//         //points to draw to
//         matrix point2; //opposite point from origin

// 	public:
//         /**
//          * @brief Parameterized constructor, it creates a rectangle with a color.
//          * 
//          * @param color: 3x8-bit value for red, green, blue
//          * 
//          * @retval NONE
//          */
//         rectangle(double x0, double y0,int color);

//         /**
//          * @brief Copy constructor that copies the paramters from the given rectangle
//          * 
//          * @param from: Rectangle to copy into the current rectangle.
//          * 
//          * @retval None
//          */
// 		rectangle(const rectangle &from);

//          /**
//          * @brief Constructor that makes a new rectangle from a stream
//          * 
//          * @param is: Input stream that contains rectangle parameters
//          * 
//          * @retval NONE
//          */
// 		rectangle(std::istream &is);

//         /**
//          * @brief Virtual constructor thats used to copy a shape 
//          * 
//          * @param: NONE
//          * 
//          * @retval NONE
//          */
// 		shape *clone(); 

// 		/**
//          * @brief Rectangle destructor, frees memory allocated to rectangle
//          *        Not currently used due to image handling deletion
//          * 
//          * @param: NONE
//          * 
//          * @retval NONE
//          */
// 		~rectangle();

//         /**
//          * @brief Draws the given rectangle
//          * 
//          * @param gc: GraphicsContext object that tells the shape where to draw
//          * 
//          * @retval NONE
//          */
// 		void draw(GraphicsContext *gc); 

//         /**
//          * @brief Print contents of rectangle into std.
//          *        Method made const to prevent modifying when outputting
//          * 
//          * @param os: Stream to write to
//          * 
//          * @retval NONE
//          */
// 		virtual std::ostream &out(std::ostream &os) const;

//         /**
//          * @brief Read rectangle properties from a text file (stream)
//          * 
//          * @param is: Stream to read from
//          * 
//          * @retval NONE
//          */
// 		virtual std::istream &in(std::istream &is);
// };

#endif