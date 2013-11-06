#--------------------------------------------
# C++ language project template
#
# default folder structure as follows
# <project root folder>
#      cmake/   <- here the additional modules with handy macro and finders
#      include/
#      src/
#      test/
#
#--------------------------------------------
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# use standard file endings - rename to cxx if needed
set(SRC_EXT_PATTERN ".cpp")

# rename to your name here
set(PROJECT_NAME vcffmpeg)

# define project for C++ language
project(${PROJECT_NAME} CXX)

# set where to find additional cmake modules if any
# comment it out if not required
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# set compiler support for C++11 standard
option(USE_CXX11_STD "Product should be build with C++11 compiler option enabled" ON)

if(USE_CXX11_STD)
	if(CMAKE_COMPILER_IS_GNUCXX)
		set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
	else()
		# don't know so far how to enable it for clang/icc/msvc
#		message(FATAL_ERROR "USE_CXX11_STD: only GCC is supported")
	endif()
endif()

# add include path for project
# add additional path if required
include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(FFMPEG)

if(FFMPEG_FOUND)
#  FFMPEG_INCLUDE_DIRS  - Include directory necessary for using the required components headers.
#  FFMPEG_LIBRARIES     - Link these to use the required ffmpeg components.
#  FFMPEG_DEFINITIONS   - Compiler switches required for using the required ffmpeg components.
    message("FFMPEG_INCLUDE_DIRS = ${FFMPEG_INCLUDE_DIRS} ")
    message("FFMPEG_LIBRARIES = ${FFMPEG_LIBRARIES} ")
    message("FFMPEG_DEFINITIONS = ${FFMPEG_DEFINITIONS} ")

    include_directories(${FFMPEG_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "FFMPEG not found")
endif()

# get all *.cpp files from src to build target
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*${SRC_EXT_PATTERN})
source_group("Source Files" FILES ${SRC_FILES})


# build target
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${FFMPEG_LIBRARIES})

