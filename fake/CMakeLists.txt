CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(FAKE)
AUX_SOURCE_DIRECTORY(./ FAKE_SRC_LIST)
INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(../include)
MESSAGE(STATUS "This is cmdcontroller BINARY dir " ${FAKE_BINARY_DIR})
MESSAGE(STATUS "This is cmdcontroller SOURCE dir " ${FAKE_SOURCE_DIR})
MESSAGE(STATUS "This is cmdcontroller SOURCE file " ${FAKE_SRC_LIST})
LINK_DIRECTORIES(${FAKE_SOURCE_DIR}/../bin/)
IF(REMOD)
SET(CMAKE_CXX_FLAGS "-O3 -Wall -Werror -gdwarf-2 -m64 -DNDEBUG")
MESSAGE("build release fake")
ELSE()
SET(CMAKE_CXX_FLAGS "-g3 -O0 -Wall -Werror -gdwarf-2 -m64 -D_DEBUG")
MESSAGE("build debug fake")
ENDIF()
SET(EXECUTABLE_OUTPUT_PATH ${FAKE_BINARY_DIR}/../bin)
ADD_EXECUTABLE(fake ${FAKE_SRC_LIST})
TARGET_LINK_LIBRARIES(fake fkscript profiler)
