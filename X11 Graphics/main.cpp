#include "x11context.h"
#include <unistd.h>
#include <iostream>
 
int main(void){
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);
 
	/** Commands
	 * gc->setColor(GraphicsContext::GREEN); Set color
	 * gc->setPixel(10,10); Draw pixel(x,y)
	 * gc->drawLine(100,100,100,200); Draw line (x1, y1, x2, y2)
	 * gc->drawCircle(300,300,200); Draw circle (x, y, radius);
	 */

	// draw some lines
	gc->setColor(GraphicsContext::GREEN);
	gc->drawLine(0,250,800,250); //Horizon
	gc->drawCircle(325,125,25); //Outer moon
	gc->drawCircle(320,120,18); //Inner moon

	//Crosshair
	gc->drawLine(360,320,440,320); //bottom
	gc->drawLine(360,320,400,260);
	gc->drawLine(400,260,440,320);

	//=======Mountian Range========
	//MTN 1
	gc->drawLine(0,220,55,190);
	gc->drawLine(55,190,100,220);
	gc->drawLine(55,190,72,189);
	gc->drawLine(72,189,100,220);
	//MTN 2
	gc->drawLine(55,250,150,187);
	gc->drawLine(150,187,210,250);
	gc->drawLine(182,220,245,250);
	gc->drawLine(150,187,210,220);
	gc->drawLine(210,220,340,250);

	//MTN 3
	gc->drawLine(445,250,500,194);
	gc->drawLine(500,194,525,250);
	gc->drawLine(503,200,610,250);
	gc->drawLine(535,215,600,183);
	gc->drawLine(604,187,730,250);
	gc->drawLine(600,183,628,215);
	gc->drawLine(628,215,730,250);

	//MTN 4
	gc->drawLine(730,250,800,230);
	
	sleep(30);
 
	delete gc;
 
	return 0;
}