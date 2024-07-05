cmake_minimum_required(VERSION 3.27.8)
project(graphAssignment VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCE_FILES
    app.cpp
    src/graph.cpp
    src/service.cpp
    src/ui.cpp
        src/test.cpp
        src/test.cpp
        includes/test.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
