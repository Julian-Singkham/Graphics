/**
  ***********************************************************************************
  * @file   : shape.cpp
  * @brief  : Shape base class
  *         : Lab 6: Event Driven Drawing
  *         : CS-3210/021 
  * @date   : APR 27 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  * Abstract base class for all types of shapes (currently line, triangle). 
  * Shape houses the color and origin point for all its children since all shapes.
  * Shape functions are only ever called on when a child needs to modify/get
  * color or point1.
  ***********************************************************************************
**/
#include <sstream> //For String Stream

#include "shape.h"

//=====================================Protected===================================== 
/**
 * @brief Assigns properties from the given shape to this shape
 * 		  Made protected so that the children of shape can't be set to
 *        eachother. A triangle should not converted into a line.
 * 
 * @param rhs: The given shape to copy from
 * 
 * @retval A copy of the given shape
 */
Shape &Shape::operator=(const Shape &rhs){
    //check if shape is being assigned it itself
    if(this != &rhs){
        color = rhs.color;
        point1 = matrix(rhs.point1);
    }
    return *this;
}
//=======================================Public======================================  
/**
 * @brief Read line properties from a text file (stream)
 * 
 * @param is: Stream to read from
 * 
 * @retval NONE
 */
std::istream &Shape::in(std::istream &is){
    std::string Line;
    std::stringstream str_stream;

    //Copy Color
    std::getline(is, Line); //Read line
    str_stream = std::stringstream(Line);
    str_stream.ignore(32, ':');
    str_stream >> std::hex >> color;
    
    //Copy first point
    std::getline(is, Line); //Read line
    str_stream = std::stringstream(Line);
    str_stream.ignore(32, ':');
    str_stream >> point1[0][0];
    str_stream >> point1[1][0];
    str_stream >> point1[2][0];

    return is;
}    
/**
 * @brief Parameterized constructor, it creates a shape with a color.
 * 
 * @param color_red: 3x8-bit value for red, green, blue
 * 
 * @retval NONE
 */
Shape::Shape(int color) 
    : color(color), point1(5,5){
}

/**
 * @brief Copy constructor that copies the paramters from the given shape
 * 
 * @param from: shape to copy into the current shape.
 * 
 * @retval NONE
 */
Shape::Shape(const Shape &from) 
    : color(from.color), point1(from.point1){
}

/**
 * @brief Line destructor, frees memory allocated to line
 *        Not currently used due to image handling deletion
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
Shape::~Shape(){
}

/**
 * @brief Print contents of line into std.
 *        Method made const to prevent modifying when outputting
 *        
 *        Shape_type
 *          Color: 0x......
 *          Point1: x y z
 * 
 * @param os: Stream to write to
 * 
 * @retval NONE
 */
std::ostream &Shape::out(std::ostream &os) const{
    os << "\tColor: 0x" << std::uppercase << std::hex << color << std::endl;

    os << "\tPoint 1: " 
       << point1[0][0] << " "
       << point1[1][0] << " " 
       << point1[2][0] 
       << std::endl;

    return os;
}