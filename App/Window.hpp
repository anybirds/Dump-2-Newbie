#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
Window

Abstraction of a cross-platform window that appears in the monitor.
 */
class Window final {
private:
    static void glfwInit();
    static void glfwTerminate();

public:
    GLFWwindow *window;
    std::string name;
    int width;
    int height;

public:
    Window(const char *name, int width, int height);
    ~Window();

    bool ShouldClose();
    void SwapBuffers();
    void PollEvents();
};
