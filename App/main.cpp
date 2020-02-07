#include <Windows.h>

#include <Engine.hpp>
#include <Window.hpp>

using namespace std;
using namespace glm;
using namespace Engine;

int main(int argc, char **argv) {
    HINSTANCE hCustom = LoadLibrary(".\\Custom.dll");
    if (!hCustom) {
#ifdef DEBUG
        cout << '[' << __FUNCTION__ << ']' << " failed to load the custom library." << endl;
#endif
        return EXIT_FAILURE;
    }

    typedef void (*Func)();
    Func TypeInit = reinterpret_cast<Func>(GetProcAddress(hCustom, "TypeInit"));
    if (!TypeInit) {
#ifdef DEBUG
        cout << '[' << __FUNCTION__ << ']' << " failed to locate TypeInit function in the custom library." << endl;
#endif
        return EXIT_FAILURE;
    }
    TypeInit();

    Window window("App");
    Project::Load("C:\\Users\\river\\Documents\\Newbie\\Custom\\custom_project.json");
    Scene::Load("bunny_scene");

    Script::Start();

    while (!window.ShouldClose()) {
        Time::Tick();

        Script::Update();

        Camera::GetMainCamera()->Render();

		window.SwapBuffers();
        window.PollEvents();
    }
}
