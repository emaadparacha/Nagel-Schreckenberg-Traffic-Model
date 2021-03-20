/**
 * @file outFile.cpp
 * @brief Function that outputs the traffic matrix to a .txt file
 * @author Emaad Paracha
 */

//Dependencies
#include "outFile.h"

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
void createFile(ofstream &file, rmatrix<int> traffic, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            file << traffic[i][j] << ' '; //Print to the file
        }
        file << std::endl;
    }
    file << std::endl;
}
