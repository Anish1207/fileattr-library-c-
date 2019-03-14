# fileattr-library-c-
a c++ library to extract file attributes,MIME type and sort stored files based on various attributes

sudo apt install libmagic-dev

 g++ -c check_file.cpp
 
 ar cr libfileattr.a check_file.o
 
 g++ -o demo demo.cpp -L. -lfileattr -lmagic

 
