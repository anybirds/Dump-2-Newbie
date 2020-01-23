#include <custom_global.hpp>

/*
Scene

Describes resources and objects comprising the scene.
Reads a scene file that has resources and objects that are needed for creating the scene.
*/
class CUSTOM_EXPORT Scene final {
public:
	Scene();
	Scene(const char *name); // remove default constructor, implement this after serialization
	~Scene();
};
