#!/bin/bash

# generate .png from all .tex in current directory

for filename_with_extension in *.tex
do
    echo "processing $filename_with_extension..."

    # remove file exctension to made file handling easier

    filename=${filename_with_extension%.*}

    # convert .tex to .png 

    pdflatex $filename.tex
    touch $filename-tmp.pdf
    pdfcrop $filename.pdf $filename-tmp.pdf
    pdftoppm -png -r 800 $filename-tmp.pdf $filename

done

rm *.aux *.log *.pdf
