
file(GLOB_RECURSE LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/**.cpp)

add_library(ipc_q ${LIB_SRC})

