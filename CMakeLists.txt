cmake_minimum_required (VERSION 2.8.11)

project(snake)

# SET the directory where you have saved SDL2 lib
set(SDL2_DIR "C:/SDL2")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src" "${SDL2_DIR}/include/")
link_directories("${SDL2_DIR}/lib/x86/")

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

add_executable(snake WIN32  ${SOURCES} ${HEADERS})

target_link_libraries(snake SDL2 SDL2main)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_custom_command(TARGET snake POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2_DIR}/lib/x86/SDL2.dll"  $<TARGET_FILE_DIR:snake>)
