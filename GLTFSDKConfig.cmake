################################################################################
# CMake minimum version required
cmake_minimum_required(VERSION 3.0)


################################################################################
# Compute paths
set(GLTFSDK_CMAKE_DIR "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/")

set( GLTFSDK_INCLUDE_DIR  "${GLTFSDK_CMAKE_DIR}/include" )
set( GLTFSDK_INCLUDE_DIRS  "${GLTFSDK_CMAKE_DIR}/include" )
message(STATUS "GLTF SDK found. Headers: ${GLTFSDK_INCLUDE_DIRS}")

if(NOT TARGET GLTFSDK)
  add_library(GLTFSDK STATIC IMPORTED)
  set_target_properties(GLTFSDK PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${GLTFSDK_INCLUDE_DIRS}
    IMPORTED_LOCATION_DEBUG "${GLTFSDK_CMAKE_DIR}/debug/lib/GLTFSDK.lib"
    IMPORTED_LOCATION_RELEASE "${GLTFSDK_CMAKE_DIR}/lib/GLTFSDK.lib")
endif()