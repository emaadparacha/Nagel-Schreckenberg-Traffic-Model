/**
 * @file outFile.h
 * @brief Function that outputs the traffic matrix to a .txt file
 * @author Emaad Paracha
 */

#ifndef OUTFILE_H
#define OUTFILE_H

//Dependencies
#include <iostream>
#include <fstream>
#include <rarray>
#include <rarrayio>

//Namespaces
using namespace std;

/**
 * Outputs the traffic matrix to a .txt file
 *
 * @param file File variable to output data onto
 * @param traffic Matrix that holds the position data of cars for each timestep
 * @param rows Number of rows in the matrix
 * @param columns Number of columns in the matrix
 */
void createFile(ofstream &file, rmatrix<int> traffic, int rows, int columns);

#endif