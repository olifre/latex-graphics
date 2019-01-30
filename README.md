# latex-graphics
Grapics tooling for LaTeX to integrate diagrams from ROOT, Gnuplot, Inkscape SVG and potentially more

This set of files allows to easily integrate plots and graphics from various tools into LaTeX making use of `-shell-escape` 
to recreate the dependencies as-needed. 
No additional tools like `make` are needed, and parameters such as the size / geometry of the graphics can be passed through from within LaTeX. 

A POSIX compatible system is required. 

### Note
There are problems on MacOS X when MacTeX and the tools (such as Inkscape) are installed separately. Notably:

- Inkscape can not be called from commandline.
- No external tools find LaTeX's fonts.

These can be worked around with symbolic links to system directories for the Inkscape binary and all the fonts you need, but it's probably by far easier to just use MacPorts for both LaTeX and all the tools you need since this avoids any such issues.
