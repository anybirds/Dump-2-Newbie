#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <engine.hpp>

using namespace std;

int main()
{
    // glfw current context set
    if (!glfwInit())
    {
        exit(1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow *window = glfwCreateWindow(1024, 768, "App", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // glew triangle set
    Engine::prepareTriangle();

    // draw triangle
    while (!glfwWindowShouldClose(window)) {
        Engine::drawTriangle();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
