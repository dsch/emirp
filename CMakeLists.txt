CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_BUILD_TYPE "DEBUG" CACHE STRING "Build type")
SET(CMAKE_C_FLAGS_DEBUG "-g -Wall -Werror -Wextra -ansi" CACHE STRING "C flags")

PROJECT(emirp)

ADD_EXECUTABLE(emirp_runner emirp.c emirp_runner.c)

ADD_EXECUTABLE(emirp_test emirp.c emirp_test.c)
TARGET_LINK_LIBRARIES(emirp_test cunit)

ENABLE_TESTING()
ADD_TEST(emirp emirp_test)
