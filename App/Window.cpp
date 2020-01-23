#include <iostream>

#include <Window.hpp>

using namespace std;

void Window::glfwInit() {
	::glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::glfwTerminate() {
	::glfwTerminate();
}

Window::Window(const char *name, int width, int height) 
	: name(name), width(width), height(height) {
	Window::glfwInit();

	if (!width && !height) {
		// full-screen window
		GLFWmonitor *monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode *mode = glfwGetVideoMode(monitor);
		width = mode->width;
		height = mode->height;
	}

	this->window = glfwCreateWindow(width, height, name, NULL, NULL);
	glfwMakeContextCurrent(this->window);
}

Window::~Window() {
	glfwDestroyWindow(window);
}

bool Window::ShouldClose() {
	return static_cast<bool>(glfwWindowShouldClose(window));
}

void Window::SwapBuffers() {
    glfwSwapBuffers(window);
}
