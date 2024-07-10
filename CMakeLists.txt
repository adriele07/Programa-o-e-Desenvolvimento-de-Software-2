cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Adicione vcpkg ao seu projeto
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Encontre e ligue com o Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(MyTest my_test.cpp)
target_link_libraries(MyTest ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES}) 