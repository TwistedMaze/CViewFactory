cmake_minimum_required(VERSION 3.10)

project(FactoryMethod)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)


# Include directories
include_directories(${GTK_INCLUDE_DIRS})
include_directories("${CMAKE_SOURCE_DIR}/inc")

# Source files
set(LIB_SOURCES
    src/view_factory.c
    src/callbacks.c
)

set(DEMO_SOURCES
    src/main.c
)

# Create shared library
add_library(viewfactory SHARED ${LIB_SOURCES})
target_link_libraries(viewfactory ${GTK_LIBRARIES})
target_include_directories(viewfactory PRIVATE ${GTK_INCLUDE_DIRS})

# Set output directory for .so file
set_target_properties(viewfactory PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# Copy headers to lib/include after build
add_custom_command(TARGET viewfactory POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/lib/include"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/inc"
            "${CMAKE_BINARY_DIR}/lib/include"
)

# Create demo executable
add_executable(${PROJECT_NAME} ${DEMO_SOURCES})
target_link_libraries(${PROJECT_NAME} viewfactory ${GTK_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTK_INCLUDE_DIRS})
