cmake_minimum_required(VERSION 3.29.0)
project(graphAssignemnt VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCE_FILES
    app.cpp
    src/graph.cpp
    src/service.cpp
    src/ui.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
