#!/bin/bash

mkdir -p geometry
cd geometry

for INDEX in 0{1..9} {10..80}
do
    FILE=u${INDEX}.wrl
    wget --no-clobber http://bulatov.org/polyhedra/uniform/$FILE

    whitedune -x3d $FILE | xml2 | grep IndexedFaceSet/@coordIndex | grep -o "=.*" | tail -c +2 | head -c -1 > u${INDEX}.indices
    whitedune -x3d $FILE | xml2 | grep IndexedFaceSet/Coordinate/@point | grep -o "=.*" | tail -c +2 | head -c -1 > u${INDEX}.vertices
done
