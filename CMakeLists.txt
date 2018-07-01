cmake_minimum_required(VERSION 2.6)
project(GLIP)

find_package(GLUT)
find_package(OpenGL)
find_package(OpenCV)

include_directories(${GLIP_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "-g -Wall")

IF (NOT DESTDIR)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/uv_libs)
ELSE (NOT DESTDIR)
  set(CMAKE_INSTALL_PREFIX ${DESTDIR})
ENDIF (NOT DESTDIR)


set (GLIP_SOURCE_FILES src/glipColors.c src/glipImages.c src/glipDisplayImage.c)

#IF (OpenCV_FOUND)
#  set (GLIP_SOURCE_FILES glipOpenCV.c ${GLIP_SOURCE_FILES})
#ENDIF (OpenCV_FOUND)


add_library(glip ${GLIP_SOURCE_FILES})


INSTALL(TARGETS glip
        DESTINATION "lib"
        PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

INSTALL(FILES src/glip.h src/glipImageSt.h
        DESTINATION "include"
        PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
