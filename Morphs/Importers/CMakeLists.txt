set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Load SketchUP (if available)
if(WIN32)
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Dependencies/SketchUpAPI-Windows")
	find_package(SKPSDK.Windows)
	
	if(SKPSDK_FOUND)
		add_definitions(-DHAS_SKP_LIB)
	endif()
endif()

find_package(RapidJSON CONFIG REQUIRED)
find_package(directxtex CONFIG REQUIRED)
find_package(TBB CONFIG REQUIRED)
find_package(pxr CONFIG REQUIRED)
find_package(GLTFSDK CONFIG REQUIRED)

add_subdirectory(Utils)
add_subdirectory(Transcoders)
add_subdirectory(Apps)
