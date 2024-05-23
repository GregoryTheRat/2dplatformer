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
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 800;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

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
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    //rectangle made of two triangles (4 vertices)
    float rectangle_vertices[] = {
        //pos                //normal vector 
        0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  
        0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
       -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
       -0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f 
    };
    //indices for the rectangle (which vertices to use in what order)
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    float background_rect_vertices[] = {
        //pos               //tex coord
         1.0f,  0.5f, 0.0f,   1.5f, 1.0f, //top-right
         1.0f, -0.5f, 0.0f,   1.5f, 0.0f, //bottom-right
        -1.0f, -0.5f, 0.0f,   -0.5f, 0.0f, //bottom-left
        -1.0f,  0.5f, 0.0f,   -0.5f, 1.0f  //top-left
    };

    //VBO, EBO, VAO for character
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
    //normal vectors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //light VAO
    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //background VAO
    unsigned int bgVAO, bgVBO;
    glGenVertexArrays(1, &bgVAO);
    glGenBuffers(1, &bgVBO);
    glBindVertexArray(bgVAO);
    glBindBuffer(GL_ARRAY_BUFFER, bgVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(background_rect_vertices), background_rect_vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //build and compile shader programs
    Shader lightCubeShader("../../src/shaders/space_matrix.vs", "../../src/shaders/light_cube.fs");
    Shader lightingShader("../../src/shaders/space_matrix.vs", "../../src/shaders/ocolor_lcolor.fs");
    Shader bgShader("../../src/shaders/space_matrix_tex.vs", "../../src/shaders/tex.fs");


    //TODO: create class that loads textures
    //TEXTURE SETUP
    //------------------
    //background texture sky
    unsigned int bgSkyTexture;
    glGenTextures(1, &bgSkyTexture);
    glBindTexture(GL_TEXTURE_2D, bgSkyTexture);
    //set texutre wrapping/filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   
    //img loading
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);  
    unsigned char *data = stbi_load("../../assets/img/backgrounds/clouds/1.png", &width, &height, &nrChannels, 3);
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

    //background texture clouds
    unsigned int bgCloudsTexture;
    glGenTextures(1, &bgCloudsTexture);
    glBindTexture(GL_TEXTURE_2D, bgCloudsTexture);
    //set texutre wrapping/filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   
    //img loading
    stbi_set_flip_vertically_on_load(true);  
    data = stbi_load("../../assets/img/backgrounds/clouds/3.png", &width, &height, &nrChannels, 4);
    if (data)
    {
        //generating texture
        std::cout << nrChannels << std::endl;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
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

    //light and color
    //----------------------
    glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
    glm::vec3 toyColor(1.0f, 0.5f, 0.31f);

    glm::vec3 lightPos(1.0f, 1.0f, 0.5f);

    glm::mat4 lightCubeModel = glm::mat4(1.0f);
    //----------------------

    //setting projection matrix
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

    //only drawing lines, so triangles can be differentiated.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //render loop
    while (!glfwWindowShouldClose(window))
    {
        //calc delta time
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        //clear 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        //PLAYER
        //----------------
        glBindVertexArray(VAO);

        lightingShader.use();
        lightingShader.setVec3("objectColor", toyColor);
        lightingShader.setVec3("lightColor", lightColor);
        lightingShader.setVec3("lightPos", lightPos);

        //space matrices
        glm::mat4 playerModel = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        playerModel = glm::translate(playerModel, glm::vec3(xOffset, yOffset, 0.0f));
        playerModel = glm::rotate(playerModel, glm::radians(zRotation), glm::vec3(0.0f, 0.0f, 1.0f));
        playerModel = glm::scale(playerModel, glm::vec3(0.2f, 0.2f, 0.0f));
        view = glm::translate(view, glm::vec3(-xOffset, 0.0f, -5.0f));
        //passing matrices to shader
        lightingShader.setMat4("model", playerModel);
        lightingShader.setMat4("view", view);
        lightingShader.setMat4("projection", projection);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //----------------

        //lightCube
        //--------------
        glBindVertexArray(lightCubeVAO);
        lightCubeShader.use();
        lightCubeModel = glm::mat4(1.0f);
        lightCubeModel = glm::translate(lightCubeModel, lightPos);
        lightCubeModel = glm::scale(lightCubeModel, glm::vec3(0.1f));

        lightCubeShader.setMat4("model", lightCubeModel);
        lightCubeShader.setMat4("view", view);
        lightCubeShader.setMat4("projection", projection);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //BACKGROUND
        //----------------

        //background setup
        bgShader.use();
        glBindTexture(GL_TEXTURE_2D, bgSkyTexture);
        glBindVertexArray(bgVAO);

        glm::mat4 bgModel = glm::mat4(1.0f);
        bgModel = glm::translate(bgModel, glm::vec3(xOffset * 0.9f, 0.0f, -1.0f));
        bgModel = glm::scale(bgModel, glm::vec3(12.0f, 6.0f, 0.0f));


        bgShader.setMat4("model", bgModel);
        bgShader.setMat4("view", view);
        bgShader.setMat4("projection", projection);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //clouds
        glBindTexture(GL_TEXTURE_2D, bgCloudsTexture);
        bgModel = glm::mat4(1.0f);
        bgModel = glm::translate(bgModel, glm::vec3(xOffset * 0.5f, 0.0f, -0.9f));
        bgModel = glm::scale(bgModel, glm::vec3(22.0f, 6.0f, 0.0f));

        bgShader.setMat4("model", bgModel);
        bgShader.setMat4("view", view);
        bgShader.setMat4("projection", projection);
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

    //de-allocate resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glfwTerminate();
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
    float characterSpeed = 2.5 * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        xOffset -= 0.80f * characterSpeed;  

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        xOffset += 0.80f * characterSpeed;  

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        yOffset += 0.80f * characterSpeed;  

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        yOffset -= 0.80f * characterSpeed;  

    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        if (zRotation == 360.0f)
            zRotation = 0.0f;
        zRotation -= 75.0f * characterSpeed;
    }

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        if (zRotation == 0.0f)
            zRotation = 360.0f;
        zRotation += 75.0f * characterSpeed;
    }
}
