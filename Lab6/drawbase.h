/**
  ***********************************************************************************
  * @file   : DrawBase.h
  * @brief  : Outline for Drawing base class
  *         : Lab 6: Event Driven Drawing
  *         : CS-3210/021 
  * @date   : APR 27 2021
  * @author : Unknown (provided)
  ***********************************************************************************
**/
#ifndef DRAWBASE_H
#define DRAWBASE_H

// forward reference
class GraphicsContext;
//========================================Class======================================
//Refer to mydrawing.h for documentation
class DrawingBase{
	public:
		// prevent warnings
		virtual ~DrawingBase(){}
		virtual void paint(GraphicsContext* gc){}
		virtual void keyDown(GraphicsContext* gc, unsigned int keycode){}
		virtual void keyUp(GraphicsContext* gc, unsigned int keycode){}
		virtual void mouseButtonDown(GraphicsContext* gc, 
								unsigned int button, int x, int y){}
		virtual void mouseButtonUp(GraphicsContext* gc,
								unsigned int button, int x, int y){}
		virtual void mouseMove(GraphicsContext* gc, int x, int y){}
};
#endif