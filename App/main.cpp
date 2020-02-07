#include <Engine.hpp>
#include <Window.hpp>

using namespace std;
using namespace glm;
using namespace Engine;

template <template <typename ...> class List, typename T, typename ...Types>
void TypeInit();

template <typename T, typename ...Types>
inline void TypeInit(TypeList<T, Types...>) {
    T::type = new Type(T::typeName, T::Instantiate, T::Serialize, T::Deserialize);
    TypeInit(TypeList<Types...>());
}

template <typename T>
inline void TypeInit(TypeList<T>) {
    T::type = new Type(T::typeName, T::Instantiate, T::Serialize, T::Deserialize);
}

int main(int argc, char **argv) {
    TypeInit(TYPE_LIST());

    Window window("App");
    Project::Load("C:\\Users\\river\\Documents\\Newbie\\Custom\\custom_project.json");
    Scene::Load("bunny_scene");

    while (!window.ShouldClose()) {
        Time::Tick();

        Camera::GetMainCamera()->Render();

		window.SwapBuffers();
        window.PollEvents();
    }
}
