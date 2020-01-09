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

# Copy files from source directory to destination directory, substituting any
# variables.  Create destination directory if it does not exist.

macro(configure_files srcDir destDir)
    message(STATUS "Configuring directory ${destDir}")
    make_directory(${destDir})

    file(GLOB templateFiles RELATIVE ${srcDir} ${srcDir}/*)
    foreach(templateFile ${templateFiles})
        set(srcTemplatePath ${srcDir}/${templateFile})
        if(NOT IS_DIRECTORY ${srcTemplatePath})
            message(STATUS "Configuring file ${templateFile}")
            configure_file(
                    ${srcTemplatePath}
                    ${destDir}/${templateFile}
                    @ONLY)
        endif(NOT IS_DIRECTORY ${srcTemplatePath})
    endforeach(templateFile)
endmacro(configure_files)

# configure_files(${CMAKE_SOURCE_DIR}/Assets ${CMAKE_BINARY_DIR}/Assets)
file(COPY ${CMAKE_SOURCE_DIR}/Assets DESTINATION ${CMAKE_BINARY_DIR})
