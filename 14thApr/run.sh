prog=$1

rm -f *.exe
clear

g++ -o $prog $prog.cpp
./$prog