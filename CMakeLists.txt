# We set up both `CMakeLists.txt` and `setup.py` so that C++ IDE's can understand the C++ project,
# and Python IDE's can understand the Python.
cmake_minimum_required(VERSION 3.15)
project(speiceio_pybind11)


# Use `FetchContent` to install pybind11
include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11
    GIT_TAG v2.5.0
)
FetchContent_MakeAvailable(pybind11)

# Set up our code
add_library(speiceio_pybind11 SHARED src/main.cpp)
target_compile_features(speiceio_pybind11 PUBLIC cxx_std_11)
target_link_libraries(speiceio_pybind11 pybind11)