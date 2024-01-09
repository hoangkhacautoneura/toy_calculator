cmake_minimum_required(VERSION 3.0)

project(CalculatorAPI)

set(RESTBED_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/../restbed/source)
# set(RESTBED_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/../restbed/build/Release)

include_directories(${RESTBED_INCLUDE_DIR})
add_subdirectory(restbed)
# find_library(RESTBED_LIBRARY NAMES restbed HINTS ${RESTBED_LIB_DIR})

# if(RESTBED_LIBRARY)
#     message(STATUS "Restbed library found: ${RESTBED_LIBRARY}")
# else()
#     message(FATAL_ERROR "Restbed library not found")
# endif()

# Add the target
add_executable(CalculatorAPI
    main.cpp
    CalcResourceFactory.cpp
    CalcService.cpp
    CalcServiceSettingsFactory.cpp)

# Link against Restbed library
# target_link_directories(CalculatorAPI PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/../../../restbed/build/Release")
target_link_libraries(CalculatorAPI restbed-shared)
target_include_directories(CalculatorAPI PUBLIC include ${RESTBED_INCLUDE_DIR})
set_property(TARGET CalculatorAPI PROPERTY CXX_STANDARD 17)

# add_executable(restbed_example restbed_example.cpp) 
# # target_link_directories(restbed_example PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/../../../restbed/build/Release")
# target_link_libraries(restbed_example restbed-shared)
# target_include_directories(restbed_example PUBLIC include ${RESTBED_INCLUDE_DIR})
# set_property(TARGET restbed_example PROPERTY CXX_STANDARD 17)

add_custom_command(
    TARGET CalculatorAPI POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_BINARY_DIR}/restbed/Release/restbed-shared.dll
            $<TARGET_FILE_DIR:CalculatorAPI>
)