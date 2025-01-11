//
// Created by Benjamin Melville on 1/11/25.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    if(!glfwInit())
    {
        return -1;
    }

    // Configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a window object to hold windowing data and other GLFW functions
    GLFWwindow* window = glfwCreateWindow(800, 600, "Ben's Physics Sim", nullptr, nullptr);

    if(!window)
    {
        std::cerr << "FAILED TO CREATE GLFW WINDOW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // GLEW manages the function pointers for OpenGL, so we want to initialize GLEW before we call any OpenGL function
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "FAILED TO INITIALIZE GLEW!" << std::endl;
    }

    // set the size of the rendering window
    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Create a render loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // rendering ....
        glClearColor(0.3f, 0.2f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // check and call events and swap the buffers
        glfwSwapBuffers(window); // swap the color buffer to prevent flickering
        glfwPollEvents(); // check for any triggered events
    }

    // Clean delete all GLFW resources
    glfwTerminate();
    return 0;
}
