cmake_minimum_required(VERSION 3.10)

project(FactoryMethod)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)


set(SOURCES
src/view_factory.c
src/main.c
src/callbacks.c
)


add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${GTK_INCLUDE_DIRS})


# Include your project's header files
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/inc")

# Source files

# Link GTK libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTK_LIBRARIES})