//
//  StandardProgram.hpp
//  Snooker3D
//
//  Created by apple on 2019/11/23.
//  Copyright © 2019 aiofwa. All rights reserved.
//

#ifndef StandardProgram_hpp
#define StandardProgram_hpp

#include "glad/glad/glad.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


/**
 Explanation about why it being "standard":
 Standard only applies to all Snooker3D shaders, which means it has all uniforms we need,
 And the data are at the right place.
 */
class StandardProgram {
public:
    StandardProgram();

    void link(std::string vertexShaderPath, std::string fragmentShaderPath);
    GLuint compile(GLuint shaderType, std::string shaderPath);
    void use();
    void configVertexPointers();
    void setCameraTexture(GLuint texture, GLuint TBO);
    void setHDRTexture(GLuint texture);
    void setResolution(glm::vec2 r);

private:
    GLuint program;
    
    // === LOCATIONS === //
    GLuint cameraTexturePos;
    GLuint hdrTexturePos;
    GLuint resolutionPos;
};

#endif /* StandardProgram_hpp */
