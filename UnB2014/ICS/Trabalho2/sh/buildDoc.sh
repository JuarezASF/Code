#! /bin/bash

cd ..

javadoc -d doc/ -sourcepath src/: -subpackages SomJASF:GUI -charset "UTF-8"  src/*.java

cd sh/
