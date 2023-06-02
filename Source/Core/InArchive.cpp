#include "../../Header/Core/InArchive.hpp"


InArchive::InArchive(const std::string& file_name): _file_name(file_name)
{
}

void InArchive::read(std::vector<std::shared_ptr<Base>> &objects)
{
    try
    {
        std::vector<SerializedObject> serialized_objs = InArchive::deserializeVectorOfSerialized();
        auto& registry_instance = Registry::getInstance();

        for(const auto& [type_info, raw_data] : serialized_objs)
        {
            try
            {
                auto typeinfo = StringManipulations::clearNullTerminators(type_info);
                auto restored_obj = getBaseSmartPtrByType(typeinfo, registry_instance);

                std::vector<char> data(restored_obj->serializeSize());

                restored_obj->deserialize(raw_data);
                objects.push_back(restored_obj);
            }
            catch(std::exception& ex)
            {
                std::cerr << "Error occurred in archive read of object: " << ex.what() << std::endl;
            }
        }
    }
    catch(std::exception& ex)
    {
        std::cerr << "Error occurred while initializing Archive reader: " << ex.what() << std::endl;
    }
}

std::vector<SerializedObject> InArchive::deserializeVectorOfSerialized()
{
    FileManager reader(_file_name, FILE_FLAG::READ);

    auto file_data_size = reader.getFileRawDataSize();
    std::vector<char> buffer(file_data_size);

    reader.read(buffer.data(), file_data_size);
    std::vector<SerializedObject> objects;
    iterateBufferToSerializedObjs(objects, buffer);

    return objects;
}

std::shared_ptr<Base> InArchive::getBaseSmartPtrByType(const std::string& typeInfo, const Registry& registry)
{
    auto obj = registry.getObjectByTypeId(typeInfo.c_str());
    if(obj == nullptr)
    {
        throw std::runtime_error("Couldn't find object type in registry");
    }

    auto derived_obj = obj->clone();
    std::shared_ptr<Base> smart_ptr(derived_obj);

    return smart_ptr;
}

void InArchive::iterateBufferToSerializedObjs(std::vector<SerializedObject>& objects, std::vector<char>& buffer)
{
    size_t offset = 0;
    size_t iterator = 0;

    while (offset < buffer.size() - iterator) {
        iterator++;
        SerializedObject obj;
        obj.deserialize(buffer, offset);
        objects.push_back(obj);
    }
}