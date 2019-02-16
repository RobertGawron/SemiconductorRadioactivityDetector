pdflatex diagram.tex
pdfcrop diagram.pdf diagram-tmp.pdf
pdftoppm  -png -r 600 diagram-tmp.pdf diagram-output
