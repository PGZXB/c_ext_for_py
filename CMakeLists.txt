cmake_minimum_required(VERSION 3.4...3.18)
project(sum)

# The following has been moved to setup.py
# To enable this you'll need a pybind11 submodule
#add_subdirectory(pybind11)
#pybind11_add_module(sum_from_pybind11 src/sum_pybind11.cpp)
#target_include_directories(sum_from_pybind11 PRIVATE src/)
#target_compile_definitions(sum_from_pybind11 PRIVATE VERSION_INFO=0.1)
add_library(sum_from_ctypes MODULE src/sum.c)

# See https://github.com/wjakob/nanobind_example/blob/master/CMakeLists.txt

find_package(Python COMPONENTS Interpreter Development.Module REQUIRED)

# Run `nanobind.cmake_dir()` from Python to detect install location
execute_process(
  COMMAND
  python3 -c "import nanobind; print(nanobind.cmake_dir())"
  OUTPUT_VARIABLE _tmp_dir
  OUTPUT_STRIP_TRAILING_WHITESPACE COMMAND_ECHO STDOUT)
list(APPEND CMAKE_PREFIX_PATH "${_tmp_dir}")

# Now import nanobind from CMake
find_package(nanobind CONFIG REQUIRED)

# Build the actual extension module
nanobind_add_module(
  sum_from_nanobind
  NB_STATIC # Build static libnanobind (the extension module itself remains a shared library)
  src/sum_nanobind.cpp
)
