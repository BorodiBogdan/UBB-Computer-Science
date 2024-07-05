cmake_minimum_required(VERSION 3.27)
project(practical-exam VERSION 1.0.0)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Enable automatic MOC, UIC, and RCC processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the required Qt packages
find_package(Qt6 COMPONENTS Widgets Charts REQUIRED)

# Specify the path to the SQLite amalgamation

# Add UI file processing
# Source files and headers
set(PROJECT_SOURCES
        main.cpp
        utils.cpp
        Repository.cpp
        Service.cpp
        Courier.cpp
        Package.cpp
        gui.cpp
        companyui.cpp
        Observer.cpp
        Observer.h
        plotorderswidget.cpp
        plotorderswidget.h
        plotorderswidget.ui
)

# Define the executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Link the executable with the necessary Qt libraries
target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::Charts)

# Define compile definitions for the project
target_compile_definitions(${PROJECT_NAME} PRIVATE SQLITE_THREADSAFE=1)

# Find and link threads
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

# Additional linking for non-Windows platforms
if(NOT WIN32)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} dl)
endif()

# Set up CPack for easy packaging
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)