#include <iostream>
#include <filesystem>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <shader.h>

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

//settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float xOffset;
float yOffset;

int main()
{
    std::cout << "helobelo world" << std::endl;

    //glfw initialization
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "failed to create glfw window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    //loading opengl funciton pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "failed to init glad" << std::endl;
        return -1;
    }
    
    //set viewport
    glViewport(0, 0, 800, 600);


    //set up vertex data, buffers, and config vertex attr.
    //single triangle
    float triagnle_vertices[] = {
        -0.5f, -0.5f, 0.0f, //left
        0.5f, -0.5f, 0.0f,  //right
        0.0f, 0.5f, 0.0f    //top
    };

    //rectangle made of two triangles (4 vertices)
    float rectangle_vertices[] = {
        0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  //top right
        0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  //bottom right
       -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  //bottom left
       -0.5f,  0.5f, 0.0f,  0.5f, 0.5f, 0.0f   //top left 
    };
    //indices for the rectangle (which vertices to use in what order)
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    //VBO, VAO
    unsigned int VBO, EBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    //binding VAO first so VBO & EBO configs are saved to VAO
    glBindVertexArray(VAO);
    //VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle_vertices), rectangle_vertices, GL_STATIC_DRAW);
    //EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //setting vertex attr pointer for coords
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //setting vertex attr pointer for colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //unbinding VBO, EBO and VAO.  not always necessary
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //only drawing lines, so triangles can be differentiated.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //build and compile shader program
    Shader ourShader("../../src/shaders/pos_color_sh.vs", "../../src/shaders/sh.fs");

    xOffset = 0.0f;

    //render loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.use();
        ourShader.setFloat("xOffset", xOffset);
        ourShader.setFloat("yOffset", yOffset);
        //render rectangle
        glBindVertexArray(VAO);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //get and cout errors from glfw
    const char* description;
    int code = glfwGetError(&description);
 
    if (description)
    {
        std::cout << description << std::endl;
    }
    return 0;
}

//resize callback function, executes everytime window resizes
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

//process input, called each frame 
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        xOffset -= 0.01f;  

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        xOffset += 0.01f;  

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        yOffset += 0.01f;  

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        yOffset -= 0.01f;  
}
