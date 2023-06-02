#ifndef POLYMORPHICSERIALIZER_INARCHIVE_HPP
#define POLYMORPHICSERIALIZER_INARCHIVE_HPP

#include "../Base.hpp"
#include "../Core/Registry.hpp"
#include "../FileSystem/FileManager.hpp"
#include "../Serializable/SerializedObject.hpp"


class InArchive
{
    std::string _file_name;
public:
    InArchive(const std::string& file_name);

    void read(std::vector<std::shared_ptr<Base>>& objects);
    std::vector<SerializedObject> deserializeVectorOfSerialized();
    std::shared_ptr<Base> getBaseSmartPtrByType(const std::string& type_info, const Registry& registry);
    void iterateBufferToSerializedObjs(std::vector<SerializedObject>& objects, std::vector<char>& buffer);
};

#endif //POLYMORPHICSERIALIZER_INARCHIVE_HPP
