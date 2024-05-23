#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

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
                vShaderFile.open(vertexPath);
                fShaderFile.open(fragmentPath);
                std::stringstream vShaderStream, fShaderStream;
                //read file's buffer contents into streams
                vShaderStream << vShaderFile.rdbuf();
                fShaderStream << fShaderFile.rdbuf();
                //close file handlers
                vShaderFile.close();
                fShaderFile.close();
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

        void setMat4(const std::string &name, const glm::mat4 &mat) const
        {
            glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        }

        void setVec3(const std::string &name, const glm::vec3 &vec) const
        {
            glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &vec[0]);
        }
};

#endif