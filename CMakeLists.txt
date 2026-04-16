## esta es la version minima del cmake
cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

## nombre del proyecto Dose
project(G4Dose)

# ------ Boost - - - - - -#
# Find Boost package
find_package ( Boost REQUIRED regex )
# Add include directories to the list of directories searched by the
#compiler for include files :
include_directories(${Boost_INCLUDE_DIRS})
# Set Boost library list
set(LIBS_BOOST boost_regex)


# ------ zlib - - - - - -#
# Find zlib package
find_package ( ZLIB REQUIRED )
# Add include directories to the list of directories searched by the
#compiler for include files :
include_directories(${ZLIB_INCLUDE_DIRS})
# Set zlib library list
set(LIBS_ZLIB ${ZLIB_LIBRARIES})

# ------ GODDeSS - - - - - -#
# Locate GODDeSS
set(GODDESS_LIB_DIR $ENV{GODDESS}/build/G4BasicObjects/*/)
find_library(G4PropertyFileReadInTools NAMES G4PropertyFileReadInTools HINTS "${GODDESS_LIB_DIR}")
find_library(G4Scintillator NAMES G4Scintillator HINTS "${GODDESS_LIB_DIR}")
find_library(G4Fibre NAMES G4Fibre HINTS "${GODDESS_LIB_DIR}")
find_library(G4GeneralParticleSource NAMES G4GeneralParticleSource HINTS "${GODDESS_LIB_DIR}")
find_library(G4PhotonDetector NAMES G4PhotonDetector HINTS "${GODDESS_LIB_DIR}")
find_library(DataProcessing NAMES DataProcessing HINTS "${GODDESS_LIB_DIR}")
set(LIBS ${G4PropertyFileReadInTools} ${G4Scintillator} ${G4Fibre} ${G4GeneralParticleSource} ${G4PhotonDetector} ${DataProcessing})

# adding directories to the list
set(GODDESS_INCLUDE_DIR $ENV{GODDESS}/source/G4BasicObjects/)
include_directories(${GODDESS_INCLUDE_DIR}/G4PropertyFileReadInTools/include)
include_directories(${GODDESS_INCLUDE_DIR}/G4Scintillator/include)
include_directories(${GODDESS_INCLUDE_DIR}/G4Fibre/include)
include_directories(${GODDESS_INCLUDE_DIR}/G4GeneralParticleSource/include)
include_directories(${GODDESS_INCLUDE_DIR}/G4PhotonDetector/include)
include_directories(${GODDESS_INCLUDE_DIR}/DataProcessing/include)




## paquetes requeridos para el cmake ui:user interface vis:visualization
find_package(Geant4 REQUIRED ui_all vis_all)

## incluyendo las librerias de Geant4, ${string} son variables del G4
include(${Geant4_USE_FILE})

## direccion de los codigos fuente y headers
include_directories(${PROJECT_SOURCE_DIR}/inc ${Geant4_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.hh)

## el nombre del ejecutable y los archivos ligados a este
## dose es el ejecutable para dose.cc
add_executable(dose dose.cc ${sources} ${headers})

## librerias ligadas al ejecutable
target_link_libraries(dose ${Geant4_LIBRARIES} ${LIBS_BOOST} ${LIBS_ZLIB} ${LIBS_GODDESS})
#add_dependencies(${PROJECT_NAME} ${LIBS_GODDESS})


## ligando el ejecutable a nuestro proyecto
add_custom_target(G4Dose DEPENDS dose)
