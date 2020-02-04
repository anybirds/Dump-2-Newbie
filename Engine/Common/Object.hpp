#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <unordered_map>

#include <Common/Type.hpp>
#include <engine_global.hpp>

namespace Engine {

    class Project;

    SER_DECL(Object)

    /*
    Base class for all serializeable objects.
    */
    class ENGINE_EXPORT Object {
        TYPE_DECL(Object)

    private:
        static std::unordered_map<Object *, Type *> objs;
        static std::unordered_map<std::string, Object *> objmap;

    private:
        std::string name;

    public:
        Object(const std::string &name, Type *type = &Object::type);
        virtual ~Object();

        std::string const &GetName() const { return name; }
        bool SetName(std::string const &name) {
            auto it = objmap.find(name);
            if (it != objmap.end()) {
                return false;
            }
            objmap.erase(GetName());
            objmap.insert({name, this});
            this->name = name;
            return true;
        }

        // Load and Unload should be considered as pure virtual functions
        virtual void OnInit() { }
        virtual void OnDestroy() { }

        friend bool IsValid(Object *);
        friend Type *GetType(Object *);
        template <typename T> friend T *Find(const std::string &);
        friend class Project;
    };

    bool IsValid(Object *obj) {
        auto it = Object::objs.find(obj);
        if (it == Object::objs.end()) {
            return false;
        }
        return true;
    }

    Type *GetType(Object *obj) {
        auto it = Object::objs.find(obj);
        if (it == Object::objs.end()) {
            return nullptr;
        }
        return it->second;
    }

    template <typename T>
    T *Find(const std::string &name) {
        auto it = Object::objmap.find(name);
        if (it == Object::objmap.end()) {
            return nullptr;
        }
        return dynamic_cast<T *>(it->second);
    }
}

#endif
