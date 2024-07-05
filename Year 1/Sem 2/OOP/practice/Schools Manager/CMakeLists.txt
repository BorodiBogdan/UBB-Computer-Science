cmake_minimum_required(VERSION 3.29.0)
project(projectmy VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCE_FILES
    main.cpp
    repository.cpp
    service.cpp
    ui.cpp
    domain.cpp
    test.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
