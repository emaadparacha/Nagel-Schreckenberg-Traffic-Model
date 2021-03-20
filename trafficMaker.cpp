/**
 * @file trafficMaker.cpp
 * @brief Function that creates an initial matrix with row corresponding to the first timestep filled with
 * randomly spaced 1s and 0s, 1 depicting if a car is at that spot, 0 if that spot is empty.
 * @author Emaad Paracha
 */

//Dependencies
#include "trafficMaker.h"

//Namespaces
using namespace std;

/**
 * Creates an initial matrix with row corresponding to the first timestep filled with randomly spaced 1s and 0s, 1 depicting if a car is at that spot, 0 if that spot is empty.
 *
 * @param positions Number of positions on our 1-D grid
 * @param timesteps Number of timesteps for our simulation
 * @param cars Number of cars in the simulation
 * @param seed Random number seed
 * @param engine Random number generator engine
 */
rmatrix<int> createTraffic(int positions, int timesteps, int cars, int seed, mt19937 &engine)
{
    rmatrix<int> trafficMatrix(timesteps, positions); //Initialize timesteps x positions matrix to hold information about the cars
    trafficMatrix.fill(0);                            //Fill with 0s

    //Fill up the matrix with as many 1s as the number of cars and 0s otherwise
    for (int i = 0; i < positions; i++)
    {
        if (i < cars)
        {
            trafficMatrix[0][i] = 1;
        }
        else
        {
            trafficMatrix[0][i] = 0;
        }
    }

    //For loop based on std::shuffle to loop over the timestep = 0 row and randomly shuffle the 1s and 0s to create random traffic
    for (int n = positions; n > 0; n--)
    {
        uniform_int_distribution<int> distribution(0, n - 1); //Create a uniform distribution from 0 to n-1
        int ran = distribution(engine);                       //Random number between 0 and n-1
        int valn = trafficMatrix[0][n];                       //Get the value of the nth index
        trafficMatrix[0][n] = trafficMatrix[0][ran];          //Set value of nth index as the value of the random index
        trafficMatrix[0][ran] = valn;                         //Set value of the random index as the previous nth index value
    }

    //Return the initial matrix with the first timestep filled with shuffled up values of 1s and 0s (1 where there is a car, 0 for empty space)
    return trafficMatrix;
}