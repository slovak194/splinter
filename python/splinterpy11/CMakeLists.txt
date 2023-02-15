find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(splinterpy11 MODULE splinterpy11.cpp)
target_include_directories(splinterpy11 PRIVATE
        ${EIGEN3_INCLUDE_DIRS}
        )
target_link_libraries(splinterpy11 PRIVATE splinter-4-0)

set_target_properties(splinterpy11
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../splinterpy"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../splinterpy"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../splinterpy"
        )
