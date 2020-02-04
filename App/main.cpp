#include <Common/Time.hpp>

#include <Window.hpp>
#include <Scene.hpp>

using namespace std;
using namespace glm;
using namespace Engine;

int main(int argc, char **argv) {
    Window window("App"); // replace this code to Window::Init({});

    Scene scene; // replace this to Scene scene({""});

    World::Start();

    while (!window.ShouldClose()) {
        Time::Tick();

        World::Update();
        World::Render();
		window.SwapBuffers();
        window.PollEvents();
	}
}
