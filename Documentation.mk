## doc: build documentation
doc: trafficSim.pdf html/index.html

# Documentation by 'doxygen'
# The sed command displays inserts a project name in the otherwise
# generic configuration file Doxyfile.
Doxyfile:
	doxygen -g $@ 
	sed -i 's/PROJECT_NAME[ ]*=.*/PROJECT_NAME=TrafficSim/' $@


trafficSim.pdf: Doxyfile trafficSim.cpp README.md
	doxygen
	cd latex && pdflatex refman.tex && pdflatex refman.tex
	mv latex/refman.pdf trafficSim.pdf

html/index.html: Doxyfile trafficSim.cpp README.md
	doxygen

.PHONY: doc