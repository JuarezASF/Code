#! /bin/bash

cd ..

javadoc -d doc/ -sourcepath src/: -charset "UTF-8"  src/*.java

cd sh/
