/**
  ***********************************************************************************
  * @file   : triangle.h
  * @brief  : Outline for triangle shape class
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
 * point2, and point3 are class variables as the triangle class works by drawing a 
 * line from the origin point (held by shape), to the second vertex, to the third
 * vertex, and back to the origin. 
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
//========================================Class======================================      
class triangle : public shape{
    private:
        //points to draw to
        matrix point2, point3;

         /**
         * @brief Constructor that makes a new triangle from a stream
         *        Made private so that only image can create triangles with a stream.
         *        Image will handle parsing through the file and determining what
         *        shape gets created.
         * 
         * @param is: Input stream that contains triangle parameters
         * 
         * @retval NONE
         */
		triangle(std::istream &is);

        /**
         * @brief Read triangle properties from a text file (stream)
         *        
         * @param is: Stream to read from
         * 
         * @retval NONE
         */
		std::istream &in(std::istream &is);

	public:
        friend class image; //Allows image access to the instream methods

        /**
         * @brief Parameterized constructor, it creates a triangle with a color.
         * 
         * @param color: 3x8-bit value for red, green, blue
         * 
         * @retval NONE
         */
        triangle(double x0, double y0, double x1, double y1, double x2, double y2, int color);

        /**
         * @brief Copy constructor that copies the paramters from the given triangle 
         * 
         * @param from: Triangle to copy into the current triangle.
         * 
         * @retval None
         */
		triangle(const triangle &from);

        /**
         * @brief Virtual constructor thats used to copy a shape 
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
		triangle *clone(); 

		/**
         * @brief Triangle destructor, frees memory allocated to triangle
         *        Not currently used due to image handling deletion
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
		~triangle();

        /**
         * @brief Assigns properties from the given triangle to this triangle
         * 
         * @param rhs: The given triangle to copy from
         * 
         * @retval A copy of the given triangle
         */
        triangle &operator=(const triangle &rhs);

        /**
         * @brief Draws the given triangle
         * 
         * @param gc: GraphicsContext object that tells the shape where to draw
         * 
         * @retval NONE
         */
		void draw(GraphicsContext *gc); 

        /**
         * @brief Print contents of triangle into std.
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
		 std::ostream &out(std::ostream &os) const;
};

#endif