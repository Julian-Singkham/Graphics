/**
  ***********************************************************************************
  * @file   : main.cpp
  * @brief  : Main program
  *         : Lab 5: Shapes Classes and Shapes Container
  *         : CS-3210/021 
  * @date   : APR 27 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  * The purpose of this lab is to demonstrate our knowledge of software architecuture
  * to create a 3D graphics program using x11 context. This program is designed to
  * create lines and triangles in 3D space using the image class as a container
  * for a image.
  ***********************************************************************************
**/
#include <fstream>	//File io
#include <unistd.h> //Sleep
#include <assert.h> //Testing

#include "shape.h"
#include "image.h"
#include "x11context.h"

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
	//-----------------Create 3 x11 windows---------------------------
	GraphicsContext *gc1 = new X11Context(500, 500, GraphicsContext::BLACK);
    GraphicsContext *gc2 = new X11Context(500, 500, GraphicsContext::BLACK);
    GraphicsContext *gc3 = new X11Context(500, 500, GraphicsContext::BLACK);

    image image1 = image();

    //Create image from file
    ifstream file;
    file.open("test.txt");
    image1.in(file);
    file.close();

    //Create a copy of the image using the copy constructor
    image image2 = image(image1);
    //Create a copy by assignment operator
    image image3 = image1;

	//Add aditional shapes to image2 and image3
	image2.add(new line(45, 70, 62, 20, gc2->CYAN));
	image3.add(new triangle(400, 100, 300, 200, 100, 150, gc2->CYAN));

    //Verify image creation through console
	image1.out(cout);
    cout << "-----------------------------" << endl;
    image2.out(cout);
    cout << "-----------------------------" << endl;
    image3.out(cout);

    //Verify that images are unique by checking addresses
    assert(&image1 != &image2);
    assert(&image1 != &image3);

	//Verify that the shapes within the images are unique by verifying shape addresses
    vector<shape *> shapes1 = image1.get_shapes();
    vector<shape *> shapes2 = image2.get_shapes();
    vector<shape *> shapes3 = image3.get_shapes();
    for (unsigned int i = 0; i < shapes1.size(); i++){
        assert(&shapes1[i] != &shapes2[i]);
        assert(&shapes1[i] != &shapes3[i]);
    }

    //Display all images
    image1.draw(gc1);
    image2.draw(gc2);
    image3.draw(gc3);

    //Wait a while
    sleep(15);

    //Free memory
    delete gc1;
    delete gc2;
    delete gc3;

    return 0;
}