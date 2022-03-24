/**
  ***********************************************************************************
  * @file   : line.cpp
  * @brief  : line shape class
  *         : Lab 5: Shapes Classes and Shapes Container
  *         : CS-3210/021 
  * @date   : APR 27 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  * Handles the creation of a line in 3-D space using x11 graphics.
  ***********************************************************************************
**/
#include <sstream> //For String Stream

#include "line.h"
//======================================Private======================================
/**
 * @brief Constructor that makes a new line from a stream
 *        Made private so that only image can create triangles with a stream.
 *        Image will handle parsing through the file and determining what
 *        shape gets created.
 * @param is: Input stream that contains Line parameters
 * 
 * @retval NONE
 */
line::line(std::istream &is)
    : shape(color), point2(5,5){

    in(is);
}

/**
 * @brief Read line properties from a text file (stream)
 * 
 * @param is: Stream to read from
 * 
 * @retval NONE
 */
std::istream &line::in(std::istream &is){
    std::string str_line;
    std::stringstream str_stream;
    
    shape::in(is); //Call parent first

    //Copy second point
    std::getline(is, str_line); //Read line
    str_stream = std::stringstream(str_line);
    str_stream.ignore(32, ':');
    str_stream >> point2[0][0];
    str_stream >> point2[1][0];
    str_stream >> point2[2][0];

    return is;
}
//=======================================Public======================================      
/**
 * @brief Parameterized constructor, it creates a Line with a color.
 * 
 * @param color: 3x8-bit value for red, green, blue
 * 
 * @retval NONE
 */
line::line(double x0, double y0, double x1, double y1, int color) 
    : shape(color), point2(5,5){

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
}

/**
 * @brief Copy constructor that copies the paramters from the given line
 * 
 * @param from: Line to copy into the current line.
 * 
 * @retval None
 */
line::line(const line &from) 
    : shape(from.color), point2(from.point2){

    point1 = matrix(from.point1);
}

/**
 * @brief Virtual constructor thats used to copy a shape 
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
line *line::clone(){
    return new line(*this);
}

/**
 * @brief Line destructor, frees memory allocated to line
 *        Not currently used due to image handling deletion
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
line::~line(){
}

/**
 * @brief Assigns properties from the given line to this line
 * 
 * @param rhs: The given line to copy from
 * 
 * @retval A copy of the given line
 */
line &line::operator=(const line &rhs){
    //check if shape is being assigned it itself
    if(this != &rhs){
        color = rhs.color;
        point1 = matrix(rhs.point1);
        point2 = matrix(rhs.point2);
    }
    return *this;
}

/**
 * @brief Draws the given line
 * 
 * @param gc: GraphicsContext object that tells the shape where to draw
 * 
 * @retval NONE
 */
void line::draw(GraphicsContext *gc){
    gc->setColor(color);
    gc->drawLine(point1[0][0], point1[1][0], point2[0][0], point2[1][0]);
}

/**
 * @brief Print contents of line into std.
 *        Method made const to prevent modifying when outputting
 *        
 *        Shape type
 *          Color: 0x......
 *          Point?: x y z
 * 
 * @param os: Stream to write to
 * 
 * @retval NONE
 */
std::ostream &line::out(std::ostream &os) const{
    os << "Line" << std::endl;
    shape::out(os); //Call shape's printout first

    os << "\tPoint 2: " 
       << point2[0][0] << " "
       << point2[1][0] << " " 
       << point2[2][0] 
       << std::endl;
    
    return os;
}