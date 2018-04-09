cmake_minimum_required( VERSION 3.5.1 )

SET( CMAKE_CXX_STANDARD 11 )
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -funroll-loops -flto -D _DEFAULT_SOURCE -Wall -Wextra -Wpedantic -g")

FIND_PACKAGE( Boost COMPONENTS program_options REQUIRED )
FIND_PACKAGE( OpenCV REQUIRED )

ADD_EXECUTABLE( image_viewer
src/tarea04.cpp
src/space_convolution.cpp
src/frequency_convolution.cpp
src/time_measure.cpp
src/runs_per_case.cpp
)

TARGET_LINK_LIBRARIES( image_viewer ${OpenCV_LIBS} )
