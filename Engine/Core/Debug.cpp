#include <string>

#include <Core/Debug.hpp>

using namespace Engine;

void APIENTRY Debug::GraphicsErrorLog(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam) {
	// ignore insignificant error/warning codes
	if (id == 131169 || id == 131185 || id == 131218 || id == 131204) {
		return;
	}
	
	string source_str, type_str, severity_str;
	
	switch (source) {
	case GL_DEBUG_SOURCE_API:
		source_str = "API";
		break;
	case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
		source_str = "Window System";
		break;
	case GL_DEBUG_SOURCE_SHADER_COMPILER:
		source_str = "Shader Compiler";
		break;
	case GL_DEBUG_SOURCE_THIRD_PARTY:
		source_str = "Third Party";
		break;
	case GL_DEBUG_SOURCE_APPLICATION:
		source_str = "Application";
		break;
	case GL_DEBUG_SOURCE_OTHER:
		source_str = "Other";
		break;
	}

	switch (type) {
	case GL_DEBUG_TYPE_ERROR:
		type_str = "Error";
		break;
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
		type_str = "Deprecated Behavior";
		break;
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
		type_str = "Undefined Behavior";
		break;
	case GL_DEBUG_TYPE_PORTABILITY:
		type_str = "Portability";
		break;
	case GL_DEBUG_TYPE_PERFORMANCE:
		type_str = "Performance";
		break;
	case GL_DEBUG_TYPE_PUSH_GROUP:
		type_str = "Push Group";
		break;
	case GL_DEBUG_TYPE_POP_GROUP:
		type_str = "Pop Group";
		break;
	case GL_DEBUG_TYPE_OTHER:
		type_str = "Other";
		break;
	}

	switch (severity) {
	case GL_DEBUG_SEVERITY_HIGH:
		severity_str = "High";
		break;
	case GL_DEBUG_SEVERITY_MEDIUM:
		severity_str = "Medium";
		break;
	case GL_DEBUG_SEVERITY_LOW:
		severity_str = "Low";
		break;
	case GL_DEBUG_SEVERITY_NOTIFICATION:
		severity_str = "Notification";
		break;
	}

	cout << '[' << __FUNCTION__ << "] ";
	cout << severity_str << " severity level " << type_str << " (Error) occured by " << source_str << '.' << endl;
	
	return;
}