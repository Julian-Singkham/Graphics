/**
  ***********************************************************************************
  * @file   : line.h
  * @brief  : Outline for line shape class
  *         : Lab 6: Event Driven Drawing
  *         : CS-3210/021 
  * @date   : APR 27 2021
  * @author : Julian Singkham
  ***********************************************************************************
**/
#ifndef LINE_H
#define LINE_H

#include "shape.h"

//========================================Class======================================      
class Line : public Shape{
    private:
        //points to draw to
        matrix point2;

         /**
         * @brief Constructor that makes a new line from a stream
         *        Made private so that only image can create triangles with a stream.
         *        Image will handle parsing through the file and determining what
         *        shape gets created.
         * @param is: Input stream that contains Line parameters
         * 
         * @retval NONE
         */
		Line(std::istream &is);

        /**
         * @brief Read line properties from a text file (stream)
         * 
         * @param is: Stream to read from
         * 
         * @retval NONE
         */
		std::istream &in(std::istream &is);

	public:
        friend class Image; //Allows image access to the instream methods

        /**
         * @brief Parameterized constructor, it creates a Line with a color.
         * 
         * @param color: 3x8-bit value for red, green, blue
         * 
         * @retval NONE
         */
        Line(double x0, double y0, double x1, double y1, int color);

        /**
         * @brief Copy constructor that copies the paramters from the given line
         * 
         * @param from: Line to copy into the current line.
         * 
         * @retval None
         */
		Line(const Line &from);

        /**
         * @brief Virtual constructor thats used to copy a shape 
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
		Line *clone(); 

		/**
         * @brief Line destructor, frees memory allocated to line
         *        Not currently used due to image handling deletion
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
		~Line();

        /**
         * @brief Assigns properties from the given line to this line
         * 
         * @param rhs: The given line to copy from
         * 
         * @retval A copy of the given line
         */
        Line &operator=(const Line &rhs);

        /**
         * @brief Draws the given line
         * 
         * @param gc: GraphicsContext object that tells the shape where to draw
         * 
         * @retval NONE
         */
		void draw(GraphicsContext *gc); 

        /**
         * @brief Print contents of line into std.
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