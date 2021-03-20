/**
 * @file trafficMovement.cpp
 * @brief Function that evolves traffic at a specific timestep according to the Nager-Schreckenberg Model:
 * v = min(v + 1, vmax) - If the velocity is below maximum velocity, then increase v by 1 (try to speed up).
 * v = min(v, d - 1) - If the car in front of the given car is a distance d away, and v is greater than or equal to d, then reduce v to d - 1.
 * v = v - 1 if v is greater than 0, with probability p - If v is greater than 0 then with probability p the car reduces its speed by 1.
 * x = x + v - The car moves ahead by v steps (on a circular track).
 * @author Emaad Paracha
 */

//Dependencies
#include "trafficMovement.h"

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
void evolutionTraffic(rmatrix<int> trafficMatrix, rmatrix<int> velocityMatrix, int positions, int timestep, double probability, int maxvelocity, mt19937 &engine)
{
    //Iterate over the positions one by one
    for (int pos = 0; pos < positions; pos++)
    {
        //Check if there is a car at that specific position
        if (trafficMatrix[timestep][pos] == 1)
        {
            //Condition 1 - v = min(v + 1, vmax)
            velocityMatrix[timestep][pos] = min(velocityMatrix[timestep][pos] + 1, maxvelocity);

            //Condition 2 - v = min(v, d - 1)
            int distance = 1;                         //Set default distance to next car
            int nextPosition = (pos + 1) % positions; //Position of next car (mod total number of positions to not go \\overboard\\ (pun intended))

            //If and while loop to check distance to next car
            if (trafficMatrix[timestep][nextPosition] == 0) //If the next position is empty
            {
                while (trafficMatrix[timestep][nextPosition] == 0) //While the next positions are empty
                {
                    distance += 1;                                 //Increment distance
                    nextPosition = (nextPosition + 1) % positions; //Change next position
                }
            }

            //Apply Condition 2 (v = min(v, d - 1))
            velocityMatrix[timestep][pos] = min(velocityMatrix[timestep][pos], distance - 1);

            //Condition 3 - v = v - 1 if v is greater than 0, with probability p
            uniform_real_distribution<double> distribution(0, 1.0); //Uniform distribution of real numbers between 0 and 1
            double r = distribution(engine);                        //Get a random number between 0 and 1

            if (velocityMatrix[timestep][pos] > 0 && r < probability) //Check if the random number is less than p
            {
                velocityMatrix[timestep][pos] -= 1; //If less than p, decrease the velocity by 1
            }

            //Move The Car - x = x + v
            int newpos = (pos + velocityMatrix[timestep][pos]) % positions;       //New position variable, adding the velocity and mod total positions
            trafficMatrix[timestep + 1][newpos] = 1;                              //Move this car into the new position in the next timestep
            velocityMatrix[timestep + 1][newpos] = velocityMatrix[timestep][pos]; //Add current velocity to new position in the next timestep
        }
    }
}