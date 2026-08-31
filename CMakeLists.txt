cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR) #version minima del CMake
project(G4Dose) # nombre del proyecto

find_package(Geant4 REQUIRED ui_all vis_all) # Busca la ubicacion de Geant4 y pide interfaz usuario y visual
include(${Geant4_USE_FILE}) # Incluye configuraciones de Geant4

include_directories(${PROJECT_SOURCE_DIR}/inc) # Busca donde estan los archivos de cabecera .hh
file(GLOB sources src/*.cc) # agrupa los archivos .cc para el momento de compilacion

add_executable(dose dose.cc ${sources}) # aprepara el comando de compilacion
target_link_libraries(dose ${Geant4_LIBRARIES}) # enlaza el ejecutable a las librerias de Geant4