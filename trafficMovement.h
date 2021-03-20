/**
 * @file trafficMovement.h
 * @brief Function that evolves traffic at a specific timestep according to the Nager-Schreckenberg Model:
 * v = min(v + 1, vmax) - If the velocity is below maximum velocity, then increase v by 1 (try to speed up).
 * v = min(v, d - 1) - If the car in front of the given car is a distance d away, and v is greater than or equal to d, then reduce v to d - 1.
 * v = v - 1 if v is greater than 0, with probability p - If v is greater than 0 then with probability p the car reduces its speed by 1.
 * x = x + v - The car moves ahead by v steps (on a circular track).
 * @author Emaad Paracha
 */

#ifndef TRAFFICMOVEMENT_H
#define TRAFFICMOVEMENT_H

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
 * @param trafficMatrix Matrix that holds positions of cars for each timestep
 * @param velocityMatrix Matrix that holds the velocity of cars for each timestep
 * @param positions Number of positions on our 1-D grid
 * @param timestep Specific timestep to evolve traffic at
 * @param probability Probability variable as set in the params.ini file
 * @param maxvelocity Maximum velocity variable as set in the params.ini file
 * @param engine Random number generator engine
 */
void evolutionTraffic(rmatrix<int> trafficMatrix, rmatrix<int> velocityMatrix, int positions, int timestep, double probability, int maxvelocity, mt19937 &engine);

#endif