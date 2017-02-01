include_directories(include)
file(GLOB LIB_SOURCE "${CMAKE_SOURCE_DIR}/src/lib/*.cc")

add_library(interest_calc_lib ${LIB_HEADERS} ${LIB_SOURCE})
