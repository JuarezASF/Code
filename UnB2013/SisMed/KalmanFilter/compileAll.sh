#! /bin/bash

cd src 

gcc -Wall *.c -o KalmanFilter -lm

mv KalmanFilter ../bin/
