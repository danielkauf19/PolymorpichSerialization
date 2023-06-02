#include <vector>
#include "../../Header/Core/OutArchive.hpp"

OutArchive::OutArchive(const std::string& file_name): _file_name(file_name)
{
}

void OutArchive::write(std::vector<std::shared_ptr<Base>>& objects)
{
    try
    {
        FileManager writer(_file_name, FILE_FLAG::WRITE);

        OutArchive::SerializedVector serialized_objs;
        auto buffer = OutArchive::serializeVectorOfBase(objects);

        writer.write(buffer.data(), buffer.size());
    }
    catch(std::exception& ex)
    {
        std::cerr << "Error occurred in Archive write: " << ex.what() << std::endl;
    }
}

std::vector<char> OutArchive::serializeVectorOfBase(std::vector<std::shared_ptr<Base>>& objects)
{
    auto& registry_instance = Registry::getInstance();
    OutArchive::SerializedVector serialized_objs;
    std::vector<char> buffer;

    for(const auto obj : objects)
    {
        std::vector<char> data(obj->serializeSize());
        obj->serialize(data);

        auto type_id_char = typeid(*obj).name();
        size_t size = atoi(type_id_char);
        std::vector<char> type_id_vec(size);

        type_id_vec.insert(type_id_vec.begin(), type_id_char, type_id_char + size);
        registry_instance.registerType(type_id_vec.data(), obj);

        SerializedObject({type_id_vec, data}).serialize(buffer);
    }

    return buffer;
}
