#include "../../Header/Core/Registry.hpp"


Registry::Registry() {}

Registry &Registry::getInstance()
{
    static Registry instance;
    return instance;
}

void Registry::registerType(std::string type_info, std::shared_ptr<Base> base_ptr)
{
    _registered_types.try_emplace(type_info, base_ptr);
}

std::shared_ptr<Base> Registry::getObjectByTypeId(std::string type_info) const
{
    auto iterator = _registered_types.find(type_info);

    if(iterator != _registered_types.end())
    {
        return iterator->second;
    }

    return nullptr;
}
