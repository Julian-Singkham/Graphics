/**
  ***********************************************************************************
  * @file   : triangle.cpp
  * @brief  : Triangle shape class
  *         : Lab 5: Shapes Classes and Shapes Container
  *         : CS-3210/021 
  * @date   : APR 27 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  * Handles the creation of a triangle in 3-D space using x11 graphics.
  ***********************************************************************************
**/
#include <sstream> //For String Stream

#include "triangle.h"
//======================================Private======================================
/**
 * @brief Constructor that makes a new triangle from a stream
 *        Made private so that only image can create triangles with stream.
 *        Image will handle parsing through the file and determining what
 *        shape gets created.
 * 
 * @param is: Input stream that contains triangle parameters
 * 
 * @retval NONE
 */
triangle::triangle(std::istream &is)
    : shape(color), point2(5,5), point3(5,5){

    in(is);
}

/**
 * @brief Read triangle properties from a text file (stream)
 * 
 * @param is: Stream to read from
 * 
 * @retval NONE
 */
std::istream &triangle::in(std::istream &is){
    std::string line;
    std::stringstream str_stream;
    
    shape::in(is); //Call parent first

    //Copy second point
    std::getline(is, line); //Read line
    str_stream = std::stringstream(line);
    str_stream.ignore(32, ':');
    str_stream >> point2[0][0];
    str_stream >> point2[1][0];
    str_stream >> point2[2][0];

    //Copy third point
    std::getline(is, line); //Read line
    str_stream = std::stringstream(line);
    str_stream.ignore(32, ':');
    str_stream >> point3[0][0];
    str_stream >> point3[1][0];
    str_stream >> point3[2][0];

    return is;
}
//=======================================Public======================================      
/**
 * @brief Parameterized constructor, it creates a triangle with a color.
 * 
 * @param color: 3x8-bit value for red, green, blue
 * 
 * @retval NONE
 */
triangle::triangle(double x0, double y0, double x1, double y1, double x2, double y2, 
                    int color) : shape(color), point2(5,5), point3(5,5){
    
    //Copy origin point
    this->point1[0][0] = x0;
    this->point1[1][0] = y0;
    this->point1[2][0] = 0; //Default
    this->point1[3][0] = 1; //Default

    //Copy second point
    this->point2[0][0] = x1;
    this->point2[1][0] = y1;
    this->point2[2][0] = 0; //Default
    this->point2[3][0] = 1; //Default

    //Copy third point
    this->point3[0][0] = x2;
    this->point3[1][0] = y2;
    this->point3[2][0] = 0; //Default
    this->point3[3][0] = 1; //Default
}

/**
 * @brief Copy constructor that copies the paramters from the given triangle 
 * 
 * @param from: Triangle to copy into the current triangle.
 * 
 * @retval None
 */
triangle::triangle(const triangle &from) 
    : shape(from.color), point2(from.point2), point3(from.point3){

    point1 = matrix(from.point1);
}

/**
 * @brief Virtual constructor thats used to copy a shape 
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
triangle *triangle::clone(){
    return new triangle(*this);
}

/**
 * @brief Triangle destructor, frees memory allocated to triangle
 *        Not currently used due to image handling deletion
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
triangle::~triangle(){
}

/**
 * @brief Assigns properties from the given triangle to this triangle
 * 
 * @param rhs: The given triangle to copy from
 * 
 * @retval A copy of the given triangle
 */
triangle &triangle::operator=(const triangle &rhs){
    //check if shape is being assigned it itself
    if(this != &rhs){
        color = rhs.color;
        point1 = matrix(rhs.point1);
        point2 = matrix(rhs.point2);
        point3 = matrix(rhs.point3);
    }
    return *this;
}

/**
 * @brief Draws the given triangle
 * 
 * @param gc: GraphicsContext object that tells the shape where to draw
 * 
 * @retval NONE
 */
void triangle::draw(GraphicsContext *gc){
    gc->setColor(color);
    gc->drawLine(point1[0][0], point1[1][0], point2[0][0], point2[1][0]);
    gc->drawLine(point2[0][0], point2[1][0], point3[0][0], point3[1][0]);
    gc->drawLine(point3[0][0], point3[1][0], point1[0][0], point1[1][0]);
}

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
std::ostream &triangle::out(std::ostream &os) const{
    os << "Triangle" << std::endl;
    shape::out(os); //Call shape's printout first

    os << "\tPoint 2: " 
       << point2[0][0] << " "
       << point2[1][0] << " " 
       << point2[2][0] 
       << std::endl;
    
    os << "\tPoint 3: " 
       << point3[0][0] << " "
       << point3[1][0] << " " 
       << point3[2][0] 
       << std::endl;

    return os;
}