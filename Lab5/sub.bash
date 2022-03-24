#Script to create pdf and zip submission from source files in
#src/ and inc/ directories
#Takes one parameter, the name (without extension) of both output files

outFilename="Lab5"

#add main.cpp first (it'd better exist)
submitFiles="./main.cpp"
submitFiles="$submitFiles ./shape.h"
submitFiles="$submitFiles ./shape.cpp"
submitFiles="$submitFiles ./line.h"
submitFiles="$submitFiles ./line.cpp"
submitFiles="$submitFiles ./triangle.h"
submitFiles="$submitFiles ./triangle.cpp"
submitFiles="$submitFiles ./image.h"
submitFiles="$submitFiles ./image.cpp"

echo -e "Creating $outFilename.pdf..."

a2ps --pro=color --toc -E -1 --header="$outFilename" --line-numbers=1 \
  -l 90 -T 4 -o - $submitFiles | ps2pdfwr - "$outFilename".pdf