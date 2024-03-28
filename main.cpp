#include <iostream>
#include <filesystem>
#include <math.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <shader.h>

#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

//settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float xOffset;
float yOffset;
float zRotation;

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
        //pos               //colors            //texture coords
        0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,  //top right
        0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 0.0f,  //bottom right
       -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,  //bottom left
       -0.5f,  0.5f, 0.0f,  0.5f, 0.5f, 0.0f,    0.0f, 1.0f  //top left 
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //setting vertex attr pointer for colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    //setting vertex attr pointer for texture coords
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    //unbinding VBO, EBO and VAO.  not always necessary
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //only drawing lines, so triangles can be differentiated.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //build and compile shader program
    Shader ourShader("../../src/shaders/trans_color_tex_sh.vs", "../../src/shaders/tex_sh.fs");

    //TODO: create class that loads textures
    //TEXTURE SETUP
    //------------------
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    //boder color
    float borderColor[] = {1.0f, 1.0f, 0.0f, 1.0f};
    //set texutre wrapping/filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   
    //img loading
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);  
    unsigned char *data = stbi_load("../../assets/img/pepe.png", &width, &height, &nrChannels, 3);
    if (data)
    {
        //generating texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "failed to load texture" << std::endl;
    }
    //freeing image memory
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
    //TEXTURE SETUP DONE
    //----------------------

    ourShader.use();
    unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");

    //render loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(xOffset, yOffset, 0.0f));
        trans = glm::rotate(trans, glm::radians(zRotation), glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans)); 

        //bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);
        //bind VAO
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
        xOffset -= 0.02f;  

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        xOffset += 0.02f;  

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        yOffset += 0.02f;  

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        yOffset -= 0.02f;  

    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        if (zRotation == 360.0f)
            zRotation = 0.0f;
        zRotation += 3.0f;
    }

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        if (zRotation == 0.0f)
            zRotation = 360.0f;
        zRotation -= 3.0f;
    }
}
