cmake_minimum_required (VERSION 3.8)

project ("secret game")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/extern/)

IF(WIN32)
    find_package(SDL2_image REQUIRED CONFIG REQUIRED COMPONENTS SDL2_image)
ELSEIF(LINUX)
    set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
    find_package(SDL2_image REQUIRED)
ELSEIF(APPLE)

ENDIF(WIN32)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

# Add source to this project's executable.
add_executable (secret_game "main.c")
target_include_directories(secret_game PUBLIC include ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS}) 
IF(WIN32)
    target_link_libraries(secret_game PUBLIC PRIVATE SDL2_image::SDL2_image ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
ELSEIF(LINUX)
    target_link_libraries(secret_game PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
ELSEIF(APPLE)

ENDIF(WIN32)