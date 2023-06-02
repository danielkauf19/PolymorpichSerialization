#ifndef POLYMORPHICSERIALIZER_REGISTRY_HPP
#define POLYMORPHICSERIALIZER_REGISTRY_HPP

#include <iostream>
#include <typeinfo>
#include <unordered_map>

#include "../Base.hpp"

class Registry
{
    Registry();
    std::unordered_map<std::string, std::shared_ptr<Base>> _registered_types;

public:
    static Registry& getInstance();

    void registerType(std::string type, std::shared_ptr<Base> base_ptr);
    std::shared_ptr<Base> getObjectByTypeId(std::string type) const;
};

#endif //POLYMORPHICSERIALIZER_REGISTRY_HPP
