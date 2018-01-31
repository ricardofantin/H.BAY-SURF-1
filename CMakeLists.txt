cmake_minimum_required(VERSION 2.8)

project(SURF)
set(CMAKE_BUILD_TYPE debug)
add_definitions(-DGRAPHICS)

set(surfLIB imload.cpp os_mapping.cpp image.cpp surf.cpp fasthessian.cpp image.h fasthessian.h ipoint.h surf.h imload.h ipoint.h)
add_library(Surf.so STATIC ${surfLIB})

#main generates the interest points description vector
add_executable(main.ln main.cpp ${surfLIB})
target_link_libraries(main.ln ${libSurf.so})

#match draws two images and their corresponding interest points
add_executable(match.ln match.cpp ${surfLIB})
target_link_libraries(match.ln ${libSurf.so})
