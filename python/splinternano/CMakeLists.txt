if (CMAKE_VERSION VERSION_LESS 3.18)
  set(DEV_MODULE Development)
else()
  set(DEV_MODULE Development.Module)
endif()

find_package(Python 3.10 COMPONENTS Interpreter ${DEV_MODULE} REQUIRED)

nanobind_add_module(splinternano splinternano.cpp)

# pybind11_add_module(splinterpy11 MODULE splinterpy11.cpp)
target_include_directories(splinternano PRIVATE
        ${EIGEN3_INCLUDE_DIRS}
        )
target_link_libraries(splinternano PRIVATE splinter-4-0)

set_target_properties(splinternano
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../splinterpy"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../splinterpy"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../splinterpy"
        )
