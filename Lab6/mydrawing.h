/**
  ***********************************************************************************
  * @file   : mydrawing.h
  * @brief  : Outline for user input drawing class, derived from drawBase
  *         : Lab 6: Event Driven Drawing
  *         : CS-3210/021 
  * @date   : MAY 11 2021
  * @author : Julian Singkham
  ***********************************************************************************
**/
#ifndef MYDRAWING_H
#define MYDRAWING_H
#include "drawbase.h"
#include "image.h"

// forward reference
class GraphicsContext;

//XK key values
enum drawing_state{
	//Logic
	point    = 112, //P
	line     = 108, //L
	triangle = 116, //T
	save     = 115, //S
	load     = 111, //O
	undo     = 122, //Z

	//Pen Colors
	black    = 49, //1
	gray     = 50, //2
	white    = 51, //3
	red      = 52, //4
	green    = 53, //5
	blue     = 54, //6
	cyan     = 55, //7
	magenta  = 56, //8
	yellow   = 57, //9
};

//========================================Class======================================
class MyDrawing : public DrawingBase{
    private: 
		//Shape properties
      	int x0; 
        int y0;
        int x1; 
        int y1;
        int x2; 
        int y2;
        int color;

		//mydrawing properties
        bool dragging; //Flag to know if mouse is moving
		bool can_undo; //Flag to know if undo can be used
		Image image;   //Shapes container
		int points_count; 		 //Keeps track of what point is being drawn
		drawing_state state; 	 //Keeps track of what command is being run
		drawing_state old_shape; //Keeps track of last drawn shape

		/**
		 * @brief Saves image information to output.txt
		 * 
		 * @param image: Image to save
		 * 
		 * @retval NONE
		 */
		void save_to_file(const Image image) const;

		/**
		 * @brief Loads image information from file specified in console
		 * 
		 * @param gc: Where to draw image
		 * 
		 * @retval NONE
		 */
		void load_file(GraphicsContext* gc);

		/**
		 * @brief Undos the last drawn shape. Only works if the user isn't in
		 * the process of drawing a shape. Shapes aren't saved to image until
		 * another shape is drawn or when saving.
		 * 
		 * @param gc: Where to draw image
		 * 
		 * @retval NONE
		 */
		void undo_shape(GraphicsContext* gc);

		/**
		 * @brief Saves the last drawn shape to image
		 * 
		 * @param: NONE
		 * 
		 * @retval NONE
		 */
		void update_image();
	
	public:
		/**
		 * @brief Constructor for a drawing (window). MyDrawing contains an image 
		 * that contains all shapes to draw and uses a graphic context to display.
		 * 
		 * @param: None
		 * 
		 * @retval NONE
		 */
    	MyDrawing();

		/**
		 * @brief Handles redrawing when window is resized
		 * 
		 * @param gc: Where to draw image
		 * 
		 * @retval NONE
		 */
        void paint(GraphicsContext* gc); 

		/**
		 * @brief Handles key presses from keyboard. Not currently used.
		 * 
		 * @param gc: Where to draw image
		 * @param keycode: XK value of pressed key
		 * 
		 * @retval NONE
		 */
		void keyDown(GraphicsContext *gc, unsigned int keycode);

		/**
		 * @brief Handles key releases from keyboard
		 * 
		 * @param gc: Where to draw image
		 * @param keycode: XK value of released key
		 * 
		 * @retval NONE
		 */
		void keyUp(GraphicsContext *gc, unsigned int keycode);

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
        void mouseButtonDown(GraphicsContext* gc, unsigned int button, int x, 
                                    int y);

		/**
		 * @brief Handles mouse releases
		 * 
		 * @param gc: Where to draw image
		 * @param button: What mouse button was released
		 * @param x: x-coordinate of mouse cursor
		 * @param y: y-coordinate of mouse cursor
		 * 
		 * @retval NONE
		 */
        void mouseButtonUp(GraphicsContext* gc, unsigned int button, int x, 
                                    int y); 
        
		/**
		 * @brief Handles mouse movement
		 * 
		 * @param gc: Where to draw image
		 * @param x: x-coordinate of mouse cursor
		 * @param y: y-coordinate of mouse cursor
		 * 
		 * @retval NONE
		 */
		void mouseMove(GraphicsContext* gc, int x, int y); 		
};
#endif