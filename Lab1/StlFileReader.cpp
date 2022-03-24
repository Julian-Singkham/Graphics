/**
  ***********************************************************************************
  * @file   : stlFileReader.cpp
  * @brief  : STL File Reader
  *         : Lab 1: C++ Console Program
  *         : CS-3210/021 
  * @date   : MAR 16 2021
  * @author : Julian Singkham
  ***********************************************************************************
  * @attention
  *
  * This handles reading a STL file and prints out each facet's vertex coordinates to
  * stdout. Additionally the minimum and maximum x,y,z values and the facet count are
  * also recorded.
  * 
  ***********************************************************************************
**/

#include "StlFileReader.h"
#include <cfloat>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//=======================================Methods=====================================


/**
 * @brief Creates STL File Reader object. Additionally, this also uses a member
 *        initializer list to set the values of the stlFileReader variables as seen
 *        in the header file.
 *        DBL_MAX is the maximum value for a float.
 * 
 * @param filename: Name of the STL file
 * 
 * @retval NONE
 */
stlFileReader::stlFileReader(string filename)
    : max_x(-DBL_MAX), min_x(DBL_MAX), max_y(-DBL_MAX), min_y(DBL_MAX), 
      max_z(-DBL_MAX), min_z(DBL_MAX), facets_count(0), filename(filename),
      line_buffer(""), filein(filename.c_str()){
          process_Stl();
      }

/**
 * @brief Reads STIL file and keeps track of how many facets there are, the
 *        max&min vertex values, and prints the vertex values for each facet
 *        to stdout.
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
void stlFileReader::process_Stl(){
    cout << "Processing " << filename << endl;
    while(filein){
        process_Facet();
    }
    print_Summary();
}

/**
 * @brief Prints the max&min vertex values and facets count.
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
void stlFileReader::print_Summary(){
    cout << "==================================================" << endl 
         << "Summary" << endl;

    cout << "Total number of facets: " << facets_count << endl;
    cout << "X Range: " << min_x << " - " << max_x <<endl;
    cout << "Y Range: " << min_y << " - " << max_y <<endl;
    cout << "Z Range: " << min_z << " - " << max_z <<endl;
}

/**
 * @brief Helper function used to parse a facet and prints the information.
 * 
 * @param: NONE
 * 
 * @retval NONE
 */
void stlFileReader::process_Facet(){
    getline(filein, line_buffer);

    //The first check is to see if the end of the STL file has been reached.
    //The second check is to see if the line contains a character.
    //The third check is to see if we reached the end of the file
    if (line_buffer.find("endsolid") == string::npos &&
        line_buffer.find_first_not_of(" \t\n\v\f\r") != string::npos && !filein.eof()){
        
        string first_word;
        stringstream(line_buffer) >> first_word;

        //Skip until facet is found
        while(first_word != "facet" && !filein.eof()){
            getline(filein, line_buffer);
            stringstream(line_buffer) >> first_word;
        }
        
        //Code can be added here to deal with facet shading.
        //Code can be added here to deal with special shapes (like shape in shape)

        //Skip until vertex is found. Stop working if end of file.
        while(first_word != "vertex" && !filein.eof()){
            getline(filein, line_buffer);
            stringstream(line_buffer) >> first_word;
        }
        
        //Stop working if end of file.
        if (!filein.eof()){
            facets_count++;
            cout << "Facet #" << facets_count << endl;
            //Iterate through each axis.
            for (int i = 0; i < 3; i++){
                string vertex;
                double x, y, z;
                stringstream(line_buffer) >> vertex >> x >> y >> z;

                cout << "   Vertex " << i+1 << ": (" << x << ", " << y << ", " << z << ")" << endl;

                max_x = max(x, max_x);
                min_x = min(x, min_x);

                max_y = max(y, max_y);
                min_y = min(y, min_y);

                max_z = max(z, max_z);
                min_z = min(z, min_z);
                getline(filein, line_buffer);
            }
        }
        cout << endl;
    }
}

stlFileReader::~stlFileReader() { 
    filein.close(); 
}