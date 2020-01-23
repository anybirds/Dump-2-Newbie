#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Common/Component.hpp>
#include <Common/Debug.hpp>
#include <Common/Object.hpp>
#include <Common/Resource.hpp>
#include <Common/Script.hpp>
#include <Common/Storage.hpp>
#include <Common/Transform.hpp>
#include <Common/World.hpp>

#include <Graphics/Camera.hpp>
#include <Graphics/Material.hpp>
#include <Graphics/Mesh.hpp>
#include <Graphics/Model.hpp>
#include <Graphics/Renderer.hpp>
#include <Graphics/Texture.hpp>

#include <Scene.hpp>

#include <Material/DefaultMaterial.hpp>
#include <Scripts/RotateScript.hpp>

using namespace std;
using namespace glm;
using namespace Engine;

#define DEBUG

Scene::Scene() {
    // glew init
    GLenum glew_error = ::glewInit();
    if (glew_error != GLEW_OK) {
        // Initializing GLEW failed
        cout << '[' << __FUNCTION__ << ']' << " message: " << glewGetErrorString(glew_error) << '\n';
        exit(1);
    }
    glEnable(GL_DEPTH_TEST); // move this to framebuffer specification

    Model::Import("C:\\Users\\river\\Documents\\Newbie\\Custom\\Models\\square_model.obj");
    Model::Import("C:\\Users\\river\\Documents\\Newbie\\Custom\\Models\\bunny_model.obj");
	
    Texture *bunny_texture = new Texture("bunny_texture", "C:\\Users\\river\\Documents\\Newbie\\Custom\\Textures\\bunny_texture.png");
    DefaultMaterial *bunny_material = new DefaultMaterial("bunny_material", "C:\\Users\\river\\Documents\\Newbie\\Custom\\Shaders\\unlit_vert.glsl", "C:\\Users\\river\\Documents\\Newbie\\Custom\\Shaders\\unlit_frag.glsl", bunny_texture);
	
	Object *camera = new Object("camera", { vec3(0.0f, 0.0f, 5.0f), mat4(1.0f), vec3(1.0f) });
	Camera *camera_camera = camera->AddComponent<Camera>();
	camera_camera->SetNormalization(perspective(radians(60.0f), 800.0f / 600.0f, 0.1f, 1000.0f));
	
	Object *square = new Object("square", { vec3(-2.0f, 0.0f, 0.0f), mat4(1.0f), vec3(1.0f) });
	Renderer *square_renderer = square->AddComponent<Renderer>();
	square_renderer->SetMesh(*Storage::FindResource<Mesh>("square_mesh"));
	square_renderer->SetMaterial(*Storage::FindResource<Material>("bunny_material"));
	
	Object *bunny = new Object("bunny", { vec3(2.0f, 0.0f, 0.0f), rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 1.0f, 0.0f)), vec3(2.0f) });
	Renderer *bunny_renderer = bunny->AddComponent<Renderer>();
	bunny_renderer->SetMesh(*Storage::FindResource<Mesh>("bunny_mesh"));
	bunny_renderer->SetMaterial(*Storage::FindResource<Material>("bunny_material"));
	RotateScript *bunny_rotatescript = bunny->AddComponent<RotateScript>();
	bunny_rotatescript->SetRate(90.0f);
	
	Camera::SetCurrentCamera(*World::FindObject("camera")->GetComponent<Camera>()); // scene should have current camera settings

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " Scene loaded successfully." << endl;
#endif
}

Scene::Scene(const char *name) {

}

Scene::~Scene() {
	// track objects and resources by adding scene name to each 
}

