# Python file to create a visualization of traffic from the trafficData.txt data file

# Dependencies
import matplotlib.pyplot as plt
import numpy as np

traffic = np.loadtxt("trafficData.txt", dtype=int) # Load data

totalTimesteps = traffic.shape[0]  # Get number of rows (timesteps)
totalPositions = traffic.shape[1]  # Get number of columns (positions)

timesteps = np.arange(0, totalTimesteps, 1)  # Create array of timesteps
positionsteps = np.arange(0, totalPositions, 1) # Create array of all the positions

# Plot dimension scale factors
poscaleFactor = totalPositions/(totalPositions+totalTimesteps)
timescaleFactor = totalTimesteps/(totalPositions+totalTimesteps)

# Set plot size
plt.figure(figsize=(15.0*poscaleFactor, 15.0*timescaleFactor))

# Set marker size
s = np.empty(totalPositions)
s.fill(0.2)

# Iterate over each time row and plot the scatter plot
for t in timesteps:
    # Create array with the current time filled in (as many times as there are positions)
    timeArray = np.empty(totalPositions)
    timeArray.fill(t)

    # Multiply the car positions with the array of all positions so we get the position ID for a car and if there is no car we get 0
    newArray = positionsteps * traffic[t]

    # Plot on the scatter plot
    plt.scatter(newArray, timeArray, s=s, c="black")

plt.savefig("trafficSnapshot.png")  # Save the figure
