## esta es la version minima del cmake
cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

## nombre del proyecto Dose
project(G4Dose)

## paquetes requeridos para el cmake ui:user interface vis:visualization
find_package(Geant4 REQUIRED ui_all vis_all)

## incluyendo las librerias de Geant4, ${string} son variables del G4
include(${Geant4_USE_FILE})

## direccion de los codigos fuente y headers
include_directories($(PROJECT_SOURCE_DIR)/inc ${Geant4_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.hh)

## el nombre del ejecutable y los archivos ligados a este
## dose es el ejecutable para dose.cc
add_executable(dose dose.cc ${sources} ${headers})

## librerias ligadas al ejecutable
target_link_libraries(dose ${Geant4_LIBRARIES})

## ligando el ejecutable a nuestro proyecto
add_custom_target(G4Dose DEPENDS dose)
