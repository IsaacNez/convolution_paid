cmake_minimum_required( VERSION 3.5.1 )
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -funroll-loops" )
FIND_PACKAGE( Boost COMPONENTS program_options REQUIRED )
FIND_PACKAGE( OpenCV REQUIRED )
#find_package(PythonLibs 2.7.12 REQUIRED)

#ADD_EXECUTABLE( image_viewer src/main.cpp src/CampbellRobson.tpp src/param_parser.tpp )

#target_include_directories(image_viewer PRIVATE ${PYTHON_INCLUDE_DIRS})
#target_link_libraries(image_viewer ${PYTHON_LIBRARIES})
#TARGET_LINK_libraries( image_viewer ${OpenCV_LIBS} ${Boost_LIBRARIES} )


