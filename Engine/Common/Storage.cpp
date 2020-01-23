#include <Common/Resource.hpp>
#include <Common/Storage.hpp>

using namespace std;
using namespace Engine;

Storage Storage::storage;

Storage::Storage() {

}

Storage::~Storage() {
	for (auto item : resource) {
		delete item.second; 
	}
}

