#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
    public:
        //the shader program ID
        unsigned int ID;

        //constructor reads and builds shader
        Shader(const char* vertexPath, const char* fragmentPath)
        {
            //retrieve shader source code from the path
            std::string vertexCode;
            std::string fragmentCode;
            std::ifstream vShaderFile;
            std::ifstream fShaderFile;

            //ensure ifstream objects can throw exceptions:
            vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
            fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
            try
            {
                //open files
                std::cout << "before open" << std::endl;
                vShaderFile.open(vertexPath);
                fShaderFile.open(fragmentPath);
                std::cout << "opened" << std::endl;
                std::stringstream vShaderStream, fShaderStream;
                //read file's buffer contents into streams
                vShaderStream << vShaderFile.rdbuf();
                fShaderStream << fShaderFile.rdbuf();
                std::cout << "rdbuf()" << std::endl;
                //close file handlers
                vShaderFile.close();
                fShaderFile.close();
                std::cout << "closed" << std::endl;
                //convert stream into string
                vertexCode = vShaderStream.str();
                fragmentCode = fShaderStream.str();
            }
            catch(std::ifstream::failure e)
            {
                std::cout << "ERROR SHADER FILE NOT READ " << e.what() << std::endl;
            }
            const char* vShaderCode = vertexCode.c_str(); 
            const char* fShaderCode = fragmentCode.c_str(); 

            //compile shaders
            unsigned int vertex, fragment;
            int success;
            char infoLog[512];
            //vertex shader
            
            vertex = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex, 1, &vShaderCode, NULL);
            glCompileShader(vertex);
            //print compile errors 
            glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(vertex, 512, NULL, infoLog);
                std::cout << "ERROR VERTEX SHADER COMPILATION FAILED\n" << infoLog << std::endl;
            }

            //fragment shader
            fragment = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment, 1, &fShaderCode, NULL);
            glCompileShader(fragment);
            //print compile errors
            glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
            if (!success) 
            {
                    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
                    std::cout << "ERROR FRAGMENT SHADER COMPILATION FAILED\n" << infoLog << std::endl;
            }

            //shader program 
            ID = glCreateProgram(); 
            glAttachShader(ID, vertex);
            glAttachShader(ID, fragment);
            glLinkProgram(ID);
            //print linking errors
            glGetProgramiv(ID, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(ID, 512, NULL, infoLog);
                std::cout << "ERROR SHADER PROGRAM LINKING FAILED\n" << infoLog << std::endl;
            }

            //delete the shaders after linking, they aren't needed anymore
            glDeleteShader(vertex);
            glDeleteShader(fragment);
        }

        //use shader
        void use()
        {
            glUseProgram(ID);
        }

        void setBool(const std::string &name, bool value) const
        {
            glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
        }
        void setInt(const std::string &name, int value) const
        {
            glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
        }
        void setFloat(const std::string &name, float value) const
        {
            glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
        }
};

#endif