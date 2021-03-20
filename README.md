[//]: # \mainpage

Program that evolves and plots a 1-D traffic model at a specific timestep according to the Nager-Schreckenberg Model:

v = min(v + 1, vmax) - If the velocity is below maximum velocity, then increase v by 1 (try to speed up).
v = min(v, d - 1) - If the car in front of the given car is a distance d away, and v is greater than or equal to d, then reduce v to d - 1.
v = v - 1 if v is greater than 0, with probability p - If v is greater than 0 then with probability p the car reduces its speed by 1.
x = x + v - The car moves ahead by v steps (on a circular track).

This code includes the following modules along with their respective headers:

readINIFile.cpp and readINIFile.h -> Functions that read a given .ini file. "readINIints" reads the .ini file at the specific path and returns integers given a string that defines the section and variable name as in the .ini file. 

trafficMaker.cpp and trafficMaker.h -> Function that creates an initial matrix with row corresponding to the first timestep filled with randomly spaced 1s and 0s, 1 depicting if a car is at that spot, 0 if that spot is empty.

trafficMovement.cpp and trafficMovement.h -> Function that evolves traffic at a specific timestep according to the Nager-Schreckenberg Model.

outFile.cpp and outFile.h -> Function that outputs the traffic matrix to a .txt file.

trafficSim.cpp -> Main driver file that runs everything together

This code comes with a Makefiles to help compile, generate
documentation, run and plot results.

To play around with different values of positions, timesteps, number of cars, probability, max velocity, and seed, please edit the values in the params.ini file.

On the Teach cluster, run the app and get the trafficData.txt file with:

```sh
   source modSetup
   make run
```

Following which, you can get the plot of traffic data using

```make plot
```

And to build the program and get the documentation, use:

```make all
```

To also denerate html and pdf versions of the code documentation using Doxygen, use

```sh
   make doc
```

Type 'make help' to see other usages of the Makefiles.