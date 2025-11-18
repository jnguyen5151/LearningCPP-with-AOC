
cmake_minimum_required(VERSION 3.16)

project(LearnCPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# wxWidgets
set(wxWidgets_ROOT_DIR "$ENV{WXWIN}")
set(wxWidgets_LIB_DIR "$ENV{WXWIN}/lib/vc_x64_dll")
set(wxWidgets_CONFIGURATION mswud)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

set(SOURCES
    app/MainFrame.cpp
    app/app.cpp
    app/OperationFactory.cpp
    app/aocDay1.cpp
    app/aocDay2.cpp
    app/aocDay3.cpp
)

# Main Executable
add_executable(LearnCPP ${SOURCES})

target_include_directories(LearnCPP PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(LearnCPP PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(LearnCPP PRIVATE ${wxWidgets_LIBRARIES})

# No console
if (WIN32)
    set_target_properties(LearnCPP PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# Input Files
file(COPY ${CMAKE_SOURCE_DIR}/app/input.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/app/input2.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/app/input3.txt DESTINATION ${CMAKE_BINARY_DIR})

# Copy wxWidgets
add_custom_command(TARGET LearnCPP POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${wxWidgets_LIB_DIR}"
    "$<TARGET_FILE_DIR:LearnCPP>"
)