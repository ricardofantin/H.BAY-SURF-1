cmake_minimum_required(VERSION 2.8)

project(SURF)
set(CMAKE_BUILD_TYPE debug)
add_definitions(-DGRAPHICS)


set(surfLIB main.cpp imload.cpp os_mapping.cpp image.cpp surf.cpp fasthessian.cpp image.h fasthessian.h ipoint.h surf.h imload.h ipoint.h)
add_library(libSurf.so STATIC ${surfLIB})


set(surfEXE match.cpp ${surfLIB})
add_executable(match.ln ${surfEXE})
target_link_libraries(match.ln ${libSurf.so})
