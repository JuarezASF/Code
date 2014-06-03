#! /bin/bash

cd ..

 javac -d bin/ -cp include/sintese.jar:include/jmathplot.jar:src/ src/*.java src/*/*.java src/*/*/*.java


cd sh/
