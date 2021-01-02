cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# ---- Project ----

project(benchmark_example LANGUAGES CXX)

# ---- Fetch CPM ----

set(CPM_DOWNLOAD_VERSION 0.27.2)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake v${CPM_DOWNLOAD_VERSION}")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for details and examples

# for now play with the fibonacci stuff from Lars
CPMAddPackage(
  NAME fibonacci
  GITLAB_REPOSITORY TheLartians/Fibonacci
  VERSION 2.0
)

CPMAddPackage(
  NAME benchmark
  GITHUB_REPOSITORY sthagen/cpp-benchmark
  GIT_TAG 2020.12
  # Below version not yet released - take above approved commit from proxy
  VERSION 1.5.2
  OPTIONS
    "BENCHMARK_ENABLE_TESTING Off"
)

if (benchmark_ADDED)
  # patch google benchmark target
  set_target_properties(benchmark PROPERTIES CXX_STANDARD 17)
endif()

# ---- Create binary ----

add_executable(benchmark_example main.cpp)
set_target_properties(benchmark_example PROPERTIES CXX_STANDARD 17)        
target_link_libraries(benchmark_example fibonacci benchmark)

# ---- Enable testing ----

enable_testing() 
add_test(benchmark_example benchmark_example)
