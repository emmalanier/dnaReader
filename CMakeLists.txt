cmake_minimum_required(VERSION 3.10)

project(dnaReader VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Packages, including the window toolkit used for rendering with OpenGL
find_package(SQLite3 REQUIRED)
find_package(OpenGL REQUIRED)

# If not on Linux, uncomment the next line, comment lines 16 and 17
#find_package(GLFW REQUIRED)

#If on Linux, leave these as they are, and make sure to comment line 13
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

# Directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/maths.cpp
    src/molecules.cpp
    src/reader.cpp
    src/sqlMethods.cpp
    src/stringMethods.cpp
)

# Executable creation
add_executable(${PROJECT_NAME} ${SOURCES})

#Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${SQLite3_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

target_include_directories(${PROJECT_NAME} PRIVATE ${SQLite3_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIRS})

# SQL databases handling 

find_program(SQLITE3_EXECUTABLE NAMES sqlite3 REQUIRED)

set (DATABASES
    "elements"
    "molecules"
    "aminoAcids"
)

set(BINARY_DB_PATHS "")

foreach(DB ${DATABASES})
    set(SQL_SCRIPT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/data/${DB}.sql")
    set(BINARY_DB_PATH "${CMAKE_CURRENT_BINARY_DIR}/databases/${DB}.db")
    list(APPEND BINARY_DB_PATHS ${BINARY_DB_PATH})

    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/databases")

    add_custom_command(
        OUTPUT ${BINARY_DB_PATH}
        COMMAND ${SQLITE3_EXECUTABLE} ${BINARY_DB_PATH} < ${SQL_SCRIPT_PATH}
        DEPENDS ${SQL_SCRIPT_PATH}
        COMMENT "Compiling ${SQL_SCRIPT_PATH} into SQLite binary DB..."
    )
endforeach()

add_custom_target(CompileDatabases ALL DEPENDS ${BINARY_DB_PATH})

add_dependencies(${PROJECT_NAME} CompileDatabases)

########
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/samples 
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)