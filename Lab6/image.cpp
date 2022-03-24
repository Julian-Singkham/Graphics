/**
  ***********************************************************************************
  * @file   : Image.cpp
  * @brief  : Image container class
  *         : Lab 6: Event Driven Drawing
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
Image::Image(){}
        
/**
 * @brief Copy constructor that copies the contents from the given image
 * 
 * @param from: Image to copy into the current image.
 * 
 * @retval NONE
 */
Image::Image(const Image &from){
    for (Shape *i : from.shapes)
        add((i)->clone());
}

/**
 * @brief Image destructor, frees memory allocated to image
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
Image::~Image(){
    erase();
}
		
/**
 * @brief Delete all shapes within the image
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
void Image::erase(){
    for (Shape *i : shapes)
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
Image &Image::operator=(const Image &rhs){
    //check if image is being assigned it itself
    if(this != &rhs){
        shapes.clear();
        for (Shape *i : rhs.shapes)
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
void Image::add(Shape *shape){
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
void Image::draw(GraphicsContext *gc) const{
    for (Shape *i : shapes)
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
std::ostream &Image::out(std::ostream &os) const{
    for (Shape *i : shapes)
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
std::istream &Image::in(std::istream &is){
    std::string str_line;
    while(std::getline(is, str_line)){
        if (str_line.rfind("Line", 0) == 0)
            add(new Line(is));
        else if (str_line.rfind("Triangle", 0) == 0)
            add(new Triangle(is));
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
std::vector<Shape *> Image::get_shapes(){
    return shapes;
}