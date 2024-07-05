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
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes/gui)

# Find the required Qt packages
find_package(Qt6 COMPONENTS Widgets Charts REQUIRED)

# Specify the path to the SQLite amalgamation

# Add UI file processing
qt6_wrap_ui(UI_HEADERS src/gui/mainwindow.ui)

# Source files and headers
set(PROJECT_SOURCES
        main.cpp
        src/gui/mainwindow.cpp
        src/gui/databasewidget.cpp
        src/gui/Connecter.cpp
        src/gui/choosemodewidget.cpp
        src/gui/chooseconnectionmodewidget.cpp
        src/gui/adminwidget.cpp
        src/gui/userwidget.cpp
        src/gui/mainwindow.h
        src/gui/databasewidget.h
        src/gui/Connecter.h
        src/gui/choosemodewidget.h
        src/gui/chooseconnectionmodewidget.h
        src/gui/adminwidget.h
        src/gui/userwidget.h
        src/domain/domain.cpp
        src/repository/repository.cpp
        src/repository/CSVRepository.cpp
        src/repository/HTMLRepository.cpp
        src/repository/FileRepository.cpp
        src/service/service.cpp
        src/ui/ui.cpp
        src/Exceptions/Exceptions.cpp
        src/validators/MovieValidator.cpp
        src/utils/Utils.cpp
        src/gui/watchlistwidget.cpp
        src/gui/barchartwidget.cpp

        ${UI_HEADERS}
        src/UndoRedoService/UndoRedoService.cpp
        src/gui/tableView.cpp
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