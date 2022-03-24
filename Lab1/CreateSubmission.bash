#Script to create pdf and zip submission from source files in
#src/ and inc/ directories
#Takes one parameter, the name (without extension) of both output files

outFilename="Lab1"

#add main.cpp first (it'd better exist)
submitFiles="./main.cpp"
submitFiles="$submitFiles ./StlFileReader.cpp"
submitFiles="$submitFiles ./StlFileReader.h"
submitFiles="$submitFiles ./Makefile"

echo -e "Creating $outFilename.pdf..."

a2ps --pro=color --toc -E -1 --header="$outFilename" --line-numbers=1 \
  -l 90 -T 4 -o - $submitFiles | ps2pdfwr - "$outFilename".pdf