cmake_minimum_required(VERSION 3.27.8)
project(a4-oop VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Our project
set(SOURCE_FILES
    main.cpp
    src/domain/domain.cpp
    src/repository/repository.cpp
    src/service/service.cpp
    src/ui/ui.cpp
    tests/test.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
