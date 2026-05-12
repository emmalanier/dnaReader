cmake_minimum_required(VERSION 3.10)

# 1. Project Name
project(dnaReader VERSION 1.0 LANGUAGES CXX)

# 2. Set C++ Standard (C++17 is great for filesystem and math)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Find Packages (SQLite and OpenGL)
find_package(SQLite3 REQUIRED)
find_package(OpenGL REQUIRED)

# 4. Include Directories
include_directories(include)

# 5. Collect Source Files
set(SOURCES
    src/main.cpp
    src/maths.cpp
    src/molecules.cpp
    src/reader.cpp
    src/sqlMethods.cpp
    src/stringMethods.cpp
)

# 6. Create the Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# 7. Link Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${SQLite3_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})

target_include_directories(${PROJECT_NAME} PRIVATE ${SQLite3_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIRS})

# 8. Copy Assets to Build folder (Optional but helpful)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/samples 
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)