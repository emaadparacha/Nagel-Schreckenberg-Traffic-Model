/**
 * @file trafficMaker.h
 * @brief Function that creates an initial matrix with row corresponding to the first timestep filled with
 * randomly spaced 1s and 0s, 1 depicting if a car is at that spot, 0 if that spot is empty.
 * @author Emaad Paracha
 */


#ifndef TRAFFICMAKER_H
#define TRAFFICMAKER_H

//Dependencies
#include <random>
#include <algorithm>
#include <rarray>
#include <rarrayio>

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
rmatrix<int> createTraffic(int positions, int timesteps, int cars, int seed, mt19937 &engine);

#endif