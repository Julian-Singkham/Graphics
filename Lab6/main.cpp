/**
  ***********************************************************************************
  * @file   : main.cpp
  * @brief  : Main program
  *         : Lab 6: Event Driven Drawing
  *         : CS-3210/021 
  * @date   : May 11 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  * This lab is an extension of the previous lab where the user can now interact with
  * the graphics window. 
  * 
  * Features:
  *   User can draw points, lines, and triangles with 9 different colors.
  *   All draw methods rubberband.
  *   User can undo the last drawn shape.
  *   User can save the image to output.txt.
  *   User can load image data from file using the console.
  *   Window can be resized without affecting the image.
  ***********************************************************************************
**/

#include "shape.h"
#include "image.h"
#include "x11context.h"
#include "mydrawing.h"

using namespace std;
//======================================Methods=======================================
/**
  * @brief The program entry point. Assume tests are successful unles otherwise stated
  * 
  * @param: NOT USED
  * 
  * @retval NOT USED
  */
int main(){
	GraphicsContext *gc = new X11Context(800, 600, GraphicsContext::BLACK);

 	cout << "This program creates an interactive graphics window using the mouse "
      	 << "to set the location of a point and keyboard to specify commands\n\n"
		 << "Pen Color Settings\n"
		 << "Key 1: Black\n"
		 << "Key 2: Gray\n"
		 << "Key 3: White\n"
		 << "Key 4: Red\n"
		 << "Key 5: Green\n"
		 << "Key 6: Blue\n"
		 << "Key 7: Cyan\n"
		 << "Key 8: Magenta\n"
		 << "Key 9: Yellow\n\n"
		 << "Graphics Commands\n"
		 << "Key P: Draw Point\n"
		 << "Key L: Draw Line\n"
		 << "Key T: Draw Triangle\n"
		 << "Key S: Save image to output.txt\n"
		 << "Key O: Load image from file using console\n"
		 << "Key Z: Undo last drawn shape" << endl;
	
	MyDrawing md;//Make a drawing
	gc->runLoop(&md); //Event loop that returns when window is closed
	delete gc;
	return 0;
}