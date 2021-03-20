# Makefile for plotting trafficSim data

## plot: have plotTraffic.py create a visualization of traffic from trafficData.txt to a .png image
plot: plotTraffic.py trafficData.txt
	python plotTraffic.py

.PHONY: plot
