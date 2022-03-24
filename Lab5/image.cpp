/**
  ***********************************************************************************
  * @file   : image.cpp
  * @brief  : Image container class
  *         : Lab 5: Shapes Classes and Shapes Container
  *         : CS-3210/021 
  * @date   : APR 27 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  * The image class is a container for shapes. Think of image as a frame and shapes
  * are added to the frame to be displayed on the monitor.
  * When creating shapes with a stream, image must be called so that it can determine
  * what shapes the parameters belong to.
  ***********************************************************************************
**/
#include <sstream> //For String Stream

#include <string>

#include "image.h"
//=======================================Public======================================
/**
 * @brief Constructor
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
image::image(){}
        
/**
 * @brief Copy constructor that copies the contents from the given image
 * 
 * @param from: Image to copy into the current image.
 * 
 * @retval NONE
 */
image::image(const image &from){
    for (shape *i : from.shapes)
        add((i)->clone());
}

/**
 * @brief Image destructor, frees memory allocated to image
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
image::~image(){
    erase();
}
		
/**
 * @brief Delete all shapes within the image
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
void image::erase(){
    for (shape *i : shapes)
        delete i;
    shapes.clear();
}

/**
 * @brief Assigns the image to another image
 * 
 * @param rhs: The given image to copy from
 * 
 * @retval A copy of the given image
 */
image &image::operator=(const image &rhs){
    //check if image is being assigned it itself
    if(this != &rhs){
        shapes.clear();
        for (shape *i : rhs.shapes)
            add((i)->clone());
    }
    return *this;
}

/**
 * @brief Adds a shape to the container
 * 
 * @param shape: Shape to add
 * 
 * @retval NONE
 */
void image::add(shape *shape){
    shapes.push_back(shape);
}

/**
 * @brief Draws tall shapes in the image
 *        Method made const to prevent modifying when outputting
 * 
 * @param gc: GraphicsContext object that tells the shape where to draw
 * 
 * @retval NONE
 */
void image::draw(GraphicsContext *gc) const{
    for (shape *i : shapes)
        (i)->draw(gc);
}

/**
 * @brief Print contents of image into std.
 *        Method made const to prevent modifying when outputting
 * 
 * @param os: Stream to write to
 * 
 * @retval NONE
 */
std::ostream &image::out(std::ostream &os) const{
    for (shape *i : shapes)
        i->out(os);
    return os;
}

/**
 * @brief Read shape properties from a text file (stream)
 * 
 * @param is: Stream to read from
 * 
 * @retval NONE
 */
std::istream &image::in(std::istream &is){
    std::string str_line;
    while(std::getline(is, str_line)){
        if (str_line.rfind("Line", 0) == 0)
            add(new line(is));
        else if (str_line.rfind("Triangle", 0) == 0)
            add(new triangle(is));
        else
            std::cout << "Unable to read line, Skipping" << std::endl;
    }
    
    return is;
}

/**
 * @brief Shapes vector getter
 * 
 * @param: NONE
 * 
 * @retval Shapes vector
 */
std::vector<shape *> image::get_shapes(){
    return shapes;
}