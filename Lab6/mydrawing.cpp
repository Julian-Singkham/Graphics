/**
  ***********************************************************************************
  * @file   : mydrawing.cpp
  * @brief  : User driven drawing class, derived from drawbase
  *         : Lab 6: Event Driven Drawing
  *         : CS-3210/021 
  * @date   : MAY 11 2021
  * @author : Unknown (provided)
  ***********************************************************************************
  * @attention
  * The mydrawing handles user interaction with the graphics context window.
  * A shape is saved to mydrawing, which is then added to image once another shape
  * is drawn or saving to file. This was done to support an undo last shape feature.
  ***********************************************************************************
**/
#include "mydrawing.h"
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;
//======================================Private======================================
/**
 * @brief Saves image information to output.txt
 * 
 * @param image: Image to save
 * 
 * @retval NONE
 */
void MyDrawing::save_to_file(const Image image)const{
	ofstream file;
	file.open("output.txt", ofstream::trunc);
	image.out(file);
	file.close();
    cout << "Saving to output.txt" << endl;
}
/**
 * @brief Loads image information from file specified in console
 * 
 * @param gc: Where to draw image
 * 
 * @retval NONE
 */
void MyDrawing::load_file(GraphicsContext* gc){
    cout << "Enter name of .txt file containing image information" << endl;
    string file_name;
    cin >> file_name;
    ifstream file(file_name);
    if (!file.is_open())
        cout << "Error: unable to open " << file_name << endl;
    else{
        image.in(file);
        cout << "Loaded " << file_name << endl;
        gc -> clear();
        image.draw(gc);
        file.close();
    }
}

/**
 * @brief Undos the last drawn shape. Only works if the user isn't in
 * the process of drawing a shape. Shapes aren't saved to image until
 * another shape is drawn or when saving.
 * 
 * @param gc: Where to draw image
 * 
 * @retval NONE
 */
void MyDrawing::undo_shape(GraphicsContext* gc){
    switch (old_shape){
        case point:
            gc->setMode(GraphicsContext::MODE_XOR);
            gc->drawLine(x0, y0, x0, y0);
            gc->setMode(GraphicsContext::MODE_NORMAL);
            break;
        case line:
            gc->setMode(GraphicsContext::MODE_XOR);
            gc->drawLine(x0, y0, x1, y1);
            gc->setMode(GraphicsContext::MODE_NORMAL);
            break;
        case triangle:
            gc->setMode(GraphicsContext::MODE_XOR);
            gc->drawLine(x0, y0, x1, y1);
            gc->drawLine(x1, y1, x2, y2);
            gc->drawLine(x2, y2, x0, y0);
            //Triangles create points on vertices on window
            //This only exists in the window, image is not affected
            gc->drawLine(x0, y0, x0, y0);
            gc->drawLine(x1, y1, x1, y1);
            gc->drawLine(x2, y2, x2, y2);
            gc->setMode(GraphicsContext::MODE_NORMAL);
            break;
        default:
            break;
    }
    can_undo = false;
    gc->clear();
    image.draw(gc);
    cout << "Undo" << endl;
}
/**
 * @brief Saves the last drawn shape to image
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
void MyDrawing::update_image(){
    switch (old_shape){
        case point:
            image.add(new Line(x0, y0, x0, y0, color));
            break;
        case line:
            image.add(new Line(x0, y0, x1, y1, color));
            break;
        case triangle:
            image.add(new Triangle(x0, y0, x1, y1, x2, y2, color));
            break;
        default:
            break;
    }
    can_undo = false;
}
//=======================================Public======================================      
/**
 * @brief Constructor for a drawing (window). MyDrawing contains an image 
 * that contains all shapes to draw and uses a graphic context to display.
 * 
 * @param: None
 * 
 * @retval NONE
 */
MyDrawing::MyDrawing(){
	dragging = false;
    can_undo = false;
	x0 = x1 = x2 = y0 = y1 = y2 = 0;
    points_count = 0;
    color = GraphicsContext::WHITE; //Default pen color
    image = Image();
	return;
}

/**
 * @brief Handles redrawing when window is resized
 * 
 * @param gc: Where to draw image
 * 
 * @retval NONE
 */
void MyDrawing::paint(GraphicsContext* gc){
    // it will only show up after an exposure
    image.draw(gc);
    //Since the last drawn isn't saved to image, we have to redraw it to
    //preserve the undo functionality
    if(can_undo){
        switch (old_shape){
            case point:
                gc->setMode(GraphicsContext::MODE_NORMAL);
                gc->drawLine(x0, y0, x0, y0); //draw line in copy mode
                break;
            case line:
                gc->setMode(GraphicsContext::MODE_NORMAL);
                gc->drawLine(x0, y0, x1, y1); //draw line in copy mode
                break;
            case triangle:
                gc->setMode(GraphicsContext::MODE_NORMAL);
                gc->drawLine(x0, y0, x1, y1); //draw line in copy mode
                gc->drawLine(x1, y1, x2, y2);
                gc->drawLine(x2, y2, x0, y0);
                break;
            default:
                break;
            }
    }
    return;
}

/**
 * @brief Handles key presses from keyboard. Not currently used.
 * 
 * @param gc: Where to draw image
 * @param keycode: XK value of pressed key
 * 
 * @retval NONE
 */
void MyDrawing::keyDown(GraphicsContext *gc, unsigned int keycode){
    return;
}

/**
 * @brief Handles key releases from keyboard
 * 
 * @param gc: Where to draw image
 * @param keycode: XK value of released key
 * 
 * @retval NONE
 */
void MyDrawing::keyUp(GraphicsContext *gc, unsigned int keycode){
	switch (keycode){
        case point:
            state = point;
            cout << "POINT" << endl;
            break;
        case line:
            state = line;
            cout << "LINE" << endl;
            break;
        case triangle:
            state = triangle;
            points_count = 0;
            cout << "TRIANGLE" << endl;
            break;
        case save:
            if(can_undo)
                update_image();
            save_to_file(image);
            break;
        case load:
            load_file(gc);
            break;
        case undo:
            if(can_undo)
                undo_shape(gc);
            else
                cout << "Unable to undo: Either the last shape was already "
                     << "removed or no images have been added" << endl;
            break;
        case black:
            color = GraphicsContext::BLACK;
            cout << "BLACK" << endl;
            break;
        case gray:
            color = GraphicsContext::GRAY;
            cout << "GRAY" << endl;
            break;
        case white:
            color = GraphicsContext::WHITE;
            cout << "WHITE" << endl;
            break;
        case red:
            color = GraphicsContext::RED;
            cout << "RED" << endl;
            break;
        case green:
            color = GraphicsContext::GREEN;
            cout << "GREEN" << endl;
            break;
        case blue:
            color = GraphicsContext::BLUE;
            cout << "BLUE" << endl;
            break;
        case cyan:
            color = GraphicsContext::CYAN;
            cout << "CYAN" << endl;
            break;
        case magenta:
            color = GraphicsContext::MAGENTA;
            cout << "MAGENTA" << endl;
            break;
        case yellow:
            color = GraphicsContext::YELLOW;
            cout << "YELLOW" << endl;
            break;
        default:
            cout << "Key down: " << keycode << endl;
            break;
    }
    gc->setColor(color);
}

/**
 * @brief Handles mouse presses
 * 
 * @param gc: Where to draw image
 * @param button: What mouse button was pressed
 * @param x: x-coordinate of mouse cursor
 * @param y: y-coordinate of mouse cursor
 * 
 * @retval NONE
 */
void MyDrawing::mouseButtonDown(GraphicsContext* gc, unsigned int button, int x, 
                                int y) {
    //Undow will only be available if the user isn't drawing a shape
    if(can_undo)
        update_image();
    
    //gc MODE_NORMAL means that shapes will be drawn ontop of the frame
    //gc MODE_XOR means that shape collision will negate eachother
    switch (state){
        case point:
            x0 = x;
            y0 = y;
            gc->setMode(GraphicsContext::MODE_NORMAL);
            gc->drawLine(x, y, x, y);
            old_shape = point;
            can_undo = true;
            break;
        case line:
            if (points_count == 0){
                points_count = 1;
                x0 = x1 = x;
                y0 = y1 = y;
                gc->setMode(GraphicsContext::MODE_XOR);
                dragging = true;
            }
            else{
                dragging = false;
                gc->drawLine(x0, y0, x1, y1); //Delete old line
                x1 = x;
                y1 = y;
                gc->setMode(GraphicsContext::MODE_NORMAL);
                gc->drawLine(x0, y0, x1, y1);
                
                //Set Flags
                points_count = 0;
                old_shape = line;
                can_undo = true;
            }
            break;
        case triangle:
            if (points_count == 0){
                points_count = 1;
                x0 = x1 = x2 = x;
                y0 = y1 = y2 = y;
                gc->setMode(GraphicsContext::MODE_XOR);
                dragging = true;
            }
            else if (points_count == 1){
                dragging = false;
                points_count = 2;
                gc->drawLine(x0, y0, x1, y1); //Delete old line
                x1 = x;
                y1 = y;
                gc->setMode(GraphicsContext::MODE_NORMAL);
                gc->drawLine(x0, y0, x1, y1);
                gc->setMode(GraphicsContext::MODE_XOR);

                //Set Flags
                dragging = true;
            }
            else{
                dragging = false;
                points_count = 0;
                gc->drawLine(x1, y1, x2, y2); //Delete old line
                gc->drawLine(x2, y2, x0, y0); //Delete old line
                x2 = x;
                y2 = y;
                gc->setMode(GraphicsContext::MODE_NORMAL);
                gc->drawLine(x1, y1, x2, y2);
                gc->drawLine(x2, y2, x0, y0);

                //Set Flags
                old_shape = triangle;
                can_undo = true;
            }
            break;
        default:
            break;
	}
    return;
}

/**
 * @brief Handles mouse releases. Not currently used.
 * 
 * @param gc: Where to draw image
 * @param button: What mouse button was released
 * @param x: x-coordinate of mouse cursor
 * @param y: y-coordinate of mouse cursor
 * 
 * @retval NONE
 */
void MyDrawing::mouseButtonUp(GraphicsContext* gc, unsigned int button, int x, 
                                int y){
	return;
}

/**
 * @brief Handles mouse movement
 * Assume GC in MODE_XOR prior to function call
 * 
 * @param gc: Where to draw image
 * @param x: x-coordinate of mouse cursor
 * @param y: y-coordinate of mouse cursor
 * 
 * @retval NONE
 */
void MyDrawing::mouseMove(GraphicsContext* gc, int x, int y){
	switch (state){
        case line:
            if (dragging){
                gc->drawLine(x0, y0, x1, y1); //Delete old line
                //Update
                x1 = x;
                y1 = y;
                gc->drawLine(x0, y0, x1, y1); //Draw new line
            }
            break;
        case triangle:
            if (dragging){
                if(points_count == 1){
                    gc->drawLine(x0, y0, x1, y1);
                    x1 = x;
                    y1 = y;
                    gc->drawLine(x0, y0, x1, y1);
                }
                else if(points_count == 2){
                    //Since all points are inialized to the origin, we have to 
                    //update the last vertex before drawing it or else the 
                    //first line will be missing in the window 
                    if((x2 != x0) || (y2 != y0)){
                        
                        gc->drawLine(x1, y1, x2, y2);
                        gc->drawLine(x2, y2, x0, y0);
                    }
                    x2 = x;
                    y2 = y;
                    gc->drawLine(x1, y1, x2, y2);
                    gc->drawLine(x2, y2, x0, y0);
                }
            }
            break;
        default:
            break;
	}
	return;
}