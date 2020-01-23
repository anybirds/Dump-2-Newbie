#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {
	
	/*
	Window

	Abstraction of a cross-platform window that appears in the monitor. 
	 */
	class Window final {
	private:
		static void glfwInit();
		static void glfwTerminate();
		static void glewInit();

	public:
		GLFWwindow *window;
		std::string name;
		int width;
		int height;
		
		int viewport_x;
		int viewport_y;
		int viewport_width;
		int viewport_height;

	public:
		Window(const char *name, int width, int height);
		~Window();

		int GetWidth() const { return width; };
		Window& SetWidth(int width) { this->width = width; return *this; };
		int GetHeight() const { return height; };
		Window& SetHeight(int height) { this->height = height; return *this; };
		const std::string& GetName() const { return name; };
		Window& SetName(const std::string &name) { this->name = name; return *this; };

		void SetActive();
		void Viewport(int viewport_x, int viewport_y, int viewport_width, int viewport_height);
		bool Closed();
		void SwapBuffers();
	};
}
