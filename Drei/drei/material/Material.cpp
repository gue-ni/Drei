#include "Material.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>
#include <fstream>


namespace DREI {

    int Material::createShader(std::string& vertexShaderCode, std::string& fragmentShaderCode)
    {
        const char* vShaderSource = vertexShaderCode.c_str();
        const char* fShaderSource = fragmentShaderCode.c_str();

        int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vShaderSource, NULL);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "vertex shader did not compile\n" << infoLog << std::endl;
        }

        int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fShaderSource, NULL);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "fragment shader did not compile\n" << infoLog << std::endl;
        }

        int s = glCreateProgram();
        glAttachShader(s, vertexShader);
        glAttachShader(s, fragmentShader);
        glLinkProgram(s);

        glGetProgramiv(s, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(s, 512, NULL, infoLog);
            std::cout << "shader linking failed\n" << infoLog << std::endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        // std::cout << "shader=" << s << std::endl;
        return s;

    }


    int Material::loadShader(std::string vertexShaderPath, std::string fragementShaderPath)
    {
        std::string vShaderSourceCode;
        loadFile(vertexShaderPath, vShaderSourceCode);

        const char* vShaderSource = vShaderSourceCode.c_str();

        std::string fShaderSourceCode;
        loadFile(fragementShaderPath, fShaderSourceCode);

        std::cout << fShaderSourceCode << std::endl;
        std::cout << vShaderSourceCode << std::endl;

        const char* fShaderSource = fShaderSourceCode.c_str();

        int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vShaderSource, NULL);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "vertex shader did not compile\n" << infoLog << std::endl;
        }

        int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fShaderSource, NULL);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "fragment shader did not compile\n" << infoLog << std::endl;
        }

        int s = glCreateProgram();
        glAttachShader(s, vertexShader);
        glAttachShader(s, fragmentShader);
        glLinkProgram(s);

        glGetProgramiv(s, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(s, 512, NULL, infoLog);
            std::cout << "shader linking failed\n" << infoLog << std::endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        std::cout << "shader=" << s << std::endl;
        return s;
    }

    void Material::loadFile(std::string filename, std::string& code)
    {
        std::ifstream file;
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            file.open(filename);
            std::stringstream fileStream;
            fileStream << file.rdbuf();
            file.close();
            code = fileStream.str();
        }
        catch (std::ifstream::failure& e) {
            std::cout << "could not read file " << filename << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}
