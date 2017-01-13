# latex-graphics
Grapics tooling for LaTeX to integrate diagrams from ROOT, Gnuplot, Inkscape SVG and potentially more

This set of files allows to easily integrate plots and graphics from various tools into LaTeX making use of `-shell-escape` 
to recreate the dependencies as-needed. 
No additional tools like `make` are needed, and parameters such as the size / geometry of the graphics can be passed through from within LaTeX. 

A POSIX compatible system is required. 
