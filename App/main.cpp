#include <Scene/Scene.hpp>
#include <Engine.hpp>

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

int main(int argc, char **argv) {
	Window window({ __FUNCTION__, 800, 600 }); // replace this code to Window::Init({});

	Scene scene; // replace this to Scene scene({""});

	World::Start();

	while (!window.Closed()) {
		Time::Tick();

		World::Update();
		World::Render();
		window.SwapBuffers();
		glfwPollEvents(); // replace this to Input static function
	}
}