cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(mesonProduction)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

file(GLOB MACRO_FILES ${PROJECT_SOURCE_DIR}/macros/*.mac)
file(COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR})

add_executable(meson mesonProduction.cc ${sources} ${headers})
target_link_libraries(meson ${Geant4_LIBRARIES})

add_custom_target(mesonProduction DEPENDS meson)
