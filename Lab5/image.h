/**
  ***********************************************************************************
  * @file   : image.h
  * @brief  : Outline for image container class
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
 * Draw is made const so that the shapes within the image don't get modified during
 * the drawing process
 * 
 * In general, only functions that access data, and not modify, are made const to
 * protect the data they are accessing.
 * 
 * Shapes is a class variable that stores all the shapes within the image class.
 * A vector was chosen for easier data manipulation as vectors do not have fixed
 * sizes.
 * 
*/
 
#ifndef IMAGE_H
#define IMAGE_H

#include <vector> //Shape verticies are stored in a vector

#include "shape.h"
#include "triangle.h"
#include "line.h"

//=======================================Class========================================
class image{
    private:
        std::vector<shape *> shapes; //List of shapes in the container

	public:
        /**
         * @brief Constructor
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
        image();

        /**
         * @brief Copy constructor that copies the contents from the given image
         * 
         * @param from: Image to copy into the current image.
         * 
         * @retval NONE
         */
		image(const image &from);

		/**
         * @brief Image destructor, frees memory allocated to image
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
		~image();

        /**
         * @brief Delete all shapes within the image
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
        void erase();

        /**
         * @brief Assigns the image to another image
         * 
         * @param rhs: The given image to copy from
         * 
         * @retval A copy of the given image
         */
        image &operator=(const image &rhs);

        /**
         * @brief Adds a shape to the container
         * 
         * @param shape: Shape to add
         * 
         * @retval NONE
         */
		void add(shape *shape); 

        /**
         * @brief Draws shapes in the image
         *        Method made const to prevent modifying when outputting
         * 
         * @param gc: GraphicsContext object that tells the shape where to draw
         * 
         * @retval NONE
         */
		void draw(GraphicsContext *gc) const; 

        /**
         * @brief Print contents of image into std.
         *        Method made const to prevent modifying when outputting
         * 
         * @param os: Stream to write to
         * 
         * @retval NONE
         */
		std::ostream &out(std::ostream &os) const;

        /**
         * @brief Read shape properties from a text file (stream)
         * 
         * @param is: Stream to read from
         * 
         * @retval NONE
         */
		std::istream &in(std::istream &is);

        /**
         * @brief Shapes vector getter
         * 
         * @param: NONE
         * 
         * @retval Shapes vector
         */
        std::vector<shape *> get_shapes();
};

#endif
