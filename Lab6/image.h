/**
  ***********************************************************************************
  * @file   : image.h
  * @brief  : Outline for image container class
  *         : Lab 6: Event Driven Drawing
  *         : CS-3210/021 
  * @date   : APR 27 2021
  * @author : Julian Singkham
  ***********************************************************************************
**/ 
#ifndef IMAGE_H
#define IMAGE_H

#include <vector> //Shape verticies are stored in a vector

#include "shape.h"
#include "triangle.h"
#include "line.h"

//=======================================Class========================================
class Image{
    private:
        std::vector<Shape *> shapes; //List of shapes in the container

	public:
        /**
         * @brief Constructor
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
        Image();

        /**
         * @brief Copy constructor that copies the contents from the given image
         * 
         * @param from: Image to copy into the current image.
         * 
         * @retval NONE
         */
		Image(const Image &from);

		/**
         * @brief Image destructor, frees memory allocated to image
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
		~Image();

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
        Image &operator=(const Image &rhs);

        /**
         * @brief Adds a shape to the container
         * 
         * @param shape: Shape to add
         * 
         * @retval NONE
         */
		void add(Shape *shape); 

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
        std::vector<Shape *> get_shapes();
};

#endif
