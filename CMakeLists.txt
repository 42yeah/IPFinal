project("HDR")
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB sources "IPFinal/*.cpp" "IPFinal/*.c")

find_package(OpenCV REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

add_executable(HDR ${sources})
target_link_libraries(HDR ${OpenCV_LIBS} glfw ${GLFW_LIBRARIES} ${GLM_LIBS})
include_directories(${GLM_INCLUDE_DIRS} ${GLFW_INCLUDE_DIR})

file(COPY ${CMAKE_SOURCE_DIR}/Assets DESTINATION ${CMAKE_BINARY_DIR})
