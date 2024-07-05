cmake_minimum_required(VERSION 3.27)
project(1st_QT_Project VERSION 1.0.0)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Enable automatic MOC, UIC, and RCC processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Include directories for your own headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gui)

# Find the required Qt packages
find_package(Qt6 COMPONENTS Widgets Charts REQUIRED)

# Source files and headers
set(PROJECT_SOURCES
        main.cpp
        domain/domain.cpp
        service/Service.cpp
        repository/Repository.cpp
        gui/mainwindow.cpp
        gui/mainwindow.ui  # Include the UI file directly
)

# Define the executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Link the executable with the necessary Qt libraries
target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::Charts)

# Additional linking for non-Windows platforms
if(NOT WIN32)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} dl)
endif()

# Set up CPack for easy packaging
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)