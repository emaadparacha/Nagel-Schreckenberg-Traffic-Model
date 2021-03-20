/**
 * @file trafficSim.cpp
 * @brief Program that evolves traffic at a specific timestep according to the Nager-Schreckenberg Model:
 * 
 * v = min(v + 1, vmax) - If the velocity is below maximum velocity, then increase v by 1 (try to speed up).
 * v = min(v, d - 1) - If the car in front of the given car is a distance d away, and v is greater than or equal to d, then reduce v to d - 1.
 * v = v - 1 if v is greater than 0, with probability p - If v is greater than 0 then with probability p the car reduces its speed by 1.
 * x = x + v - The car moves ahead by v steps (on a circular track).
 * 
 * @author Emaad Paracha
 */

//Dependencies
#include "readINIFile.h"
#include "trafficMaker.h"
#include "trafficMovement.h"
#include "outFile.h"

//Namespace
using namespace std;

//Main driver
int main()
{
    string path = "params.ini"; //Location of params.ini file

    int L, T, N, vmax, seed; //Initialize variables for the simulation

    //Set strings for the variable names in the ini file
    string Lstring = "Parameters.L";
    string Tstring = "Parameters.T";
    string Nstring = "Parameters.N";
    string vmaxstring = "Parameters.vmax";
    string seedstring = "Parameters.seed";

    //Get variables from ini file
    L = readINIints(path, Lstring);              //Number of positions on the road
    T = readINIints(path, Tstring);              //Total number of time steps
    N = readINIints(path, Nstring);              //Number of cars on the road
    vmax = readINIints(path, vmaxstring);        //Maximum Velocity
    seed = readINIints(path, seedstring);        //Random number seed
    double p = readINIdouble(path);              //Probability of slowing down
    string outputfilename = readINIstring(path); //Name of the file to save the data
    ofstream trafficfile(outputfilename);        //File variable with the outputfilename

    rmatrix<int> trafficMatrix(T, L);  //Create traffic data matrix to hold data of position of cars at each timestep
    trafficMatrix.fill(0);             //Fill in with 0s
    rmatrix<int> velocityMatrix(T, L); //Create velocity data matrix to hold data of velocity of cars at each timestep
    velocityMatrix.fill(0);            //Fill in with 0s

    mt19937 engine(seed); //Random number engine

    trafficMatrix = createTraffic(L, T, N, seed, engine); //Initialize the first timestep row with randomly placed cars (designated as 1)

    //Iterate over all the timesteps
    for (int t = 0; t < T - 1; t++)
    {
        evolutionTraffic(trafficMatrix, velocityMatrix, L, t, p, vmax, engine); //Evolve traffic according to our rules
    }

    createFile(trafficfile, trafficMatrix, T, L); //Output traffic data to a .txt file
}
