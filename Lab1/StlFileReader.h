/**
  ***********************************************************************************
  * @file   : stlFileReader.h
  * @brief  : Outline for STL file reader
  *         : Lab 1: C++ Console Program
  *         : CS-3210/021 
  * @date   : MAR 16 2021
  * @author : Julian Singkham
  ***********************************************************************************
**/

#ifndef STLFILEREADER
#define STLFILEREADER

#include <fstream>
#include <string>
#include <cfloat>

using namespace std;

class stlFileReader{
    public:
        //===================================Methods=================================
        /**
         * @brief Creates STL File Reader object
         * 
         * @param filename: Name of the STL file
         * 
         * @retval NONE
         */
        stlFileReader(string filename);

        ~stlFileReader();

    private:
        //==================================Variables================================
        double max_x, min_x, max_y, min_y, max_z, min_z;
        int facets_count;
        string filename, line_buffer;
        ifstream filein; //Input only file stream

        //===================================Methods=================================

        /**
         * @brief Reads STL file and keeps track of how many facets there are, the
         *        max&min vertex values, and prints the vertex values for each facet
         *        to stdout.
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
        void process_Stl();

        /**
         * @brief Helper function used to parse a facet and prints the information.
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
        void process_Facet();

        /**
         * @brief Prints the max&min vertex values and facets count.
         * 
         * @param: NONE
         * 
         * @retval NONE
         */
        void print_Summary();
};
#endif