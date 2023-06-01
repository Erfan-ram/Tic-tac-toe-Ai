cmake_minimum_required(VERSION 3.20.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project (main-tic)

set( NAME_SRC
    src/Main.cpp  
    src/start.cpp  
)

set( NAME_HEADERS        
    include/Ai_module.h  
    include/Main.h  
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)


add_executable(main-tic ${NAME_SRC} ${NAME_HEADERS})
