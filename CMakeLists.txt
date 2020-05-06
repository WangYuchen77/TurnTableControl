project( TurnTableControl )
set(OpenCV_DIR "/usr/local/Cellar/opencv/4.0.1/lib/cmake/opencv4")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
find_package( OpenCV REQUIRED )
find_package( Boost REQUIRED)
include_directories(
    /usr/local/include
    )
link_directories(/usr/local/lib)
add_executable( turnTableControl main.cpp Communication.cpp TurnTableControl.cpp)
target_link_libraries( turnTableControl ${OpenCV_LIBS} )