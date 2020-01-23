#include <Core/Debug.hpp>
#include <Core/Window.hpp>

#ifdef DEBUG_INTERACTION
#define DEBUG
#endif

using namespace std;
using namespace Engine;

void Window::glfwInit() {
	::glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
#ifdef DEBUG_GRAPHICS
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	GLint flags;
	glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
	if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(Debug::GraphicsErrorLog, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
	}
#endif
}

void Window::glfwTerminate() {
	::glfwTerminate();
}

void Window::glewInit() {
	GLenum glew_error = ::glewInit();
	if (glew_error != GLEW_OK) {
		// Initializing GLEW failed
		cout << '[' << __FUNCTION__ << ']' << " message: " << glewGetErrorString(glew_error) << '\n';
		exit(1);
	}
	glEnable(GL_DEPTH_TEST); // move this to framebuffer specification
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

	Window::glewInit();
	Viewport(0, 0, width, height);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " Window created." << endl;
#endif	

}

Window::~Window() {
	glfwDestroyWindow(window);
}

void Window::SetActive() {
	glfwMakeContextCurrent(window);
}

void Window::Viewport(int viewport_x, int viewport_y, int viewport_width, int viewport_height) {
	this->viewport_x = viewport_x;
	this->viewport_y = viewport_y;
	this->viewport_width = viewport_width;
	this->viewport_height = viewport_height;

	glViewport(viewport_x, viewport_y, viewport_width, viewport_height);
}

bool Window::Closed() {
	return static_cast<bool>(glfwWindowShouldClose(window));
}

void Window::SwapBuffers() {
	glfwSwapBuffers(window);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // move this to framebuffer specification
}