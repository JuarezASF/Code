cmake_minimum_required(VERSION 2.8)
project( ScanImage )
find_package( OpenCV REQUIRED )
add_executable( ScanImage main.cpp )
target_link_libraries( ScanImage ${OpenCV_LIBS} )
