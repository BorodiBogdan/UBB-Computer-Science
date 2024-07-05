cmake_minimum_required(VERSION 3.18)
project(a4-oop VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SQLITE_AMALGAMATION_PATH "${CMAKE_SOURCE_DIR}/sqlite-amalgamation-3450300")
include_directories(${SQLITE_AMALGAMATION_PATH})

set(SOURCE_FILES
    main.cpp
    src/domain/domain.cpp
    src/repository/repository.cpp
    src/repository/CSVRepository.cpp
    src/repository/HTMLRepository.cpp
    src/service/service.cpp
    src/ui/ui.cpp
    src/Exceptions/Exceptions.cpp
    src/validators/MovieValidator.cpp
    src/repository/DBRepository.cpp
    ${SQLITE_AMALGAMATION_PATH}/sqlite3.c
)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_definitions(${PROJECT_NAME} PRIVATE SQLITE_THREADSAFE=1)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

if(NOT WIN32)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} dl)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)