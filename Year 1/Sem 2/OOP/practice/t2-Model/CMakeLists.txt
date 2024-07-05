cmake_minimum_required(VERSION 3.29.0)
project(protein VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCE_FILES
    main.cpp
    BMI.cpp
    BP.cpp
    MedicalAnalysis.cpp
    Person.cpp
    Ui.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
