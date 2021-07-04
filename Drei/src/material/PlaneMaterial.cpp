#include "PlaneMaterial.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>



PlaneMaterial::PlaneMaterial() {
    std::string vertex = 
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    std::string fragment = 
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";

    shader = createShader(vertex, fragment);
}

void PlaneMaterial::draw(Camera* camera, Object3D* object) {
    glUseProgram(shader);
}



