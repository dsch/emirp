CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(emirp)

ADD_EXECUTABLE(emirp_runner emirp.c emirp_runner.c)

ADD_EXECUTABLE(emirp_test emirp_test.c)
TARGET_LINK_LIBRARIES(emirp_test cunit)

ENABLE_TESTING()
ADD_TEST(emirp emirp_test)
