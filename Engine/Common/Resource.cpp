#include <Common/Resource.hpp>
#include <Common/Storage.hpp>

using namespace std;
using namespace Engine;

Resource::Resource(const char *name) : name(name) {
	Storage::AddResource(*this); 
}

Resource::~Resource() {
	Storage::RemoveResource(*this);
}

