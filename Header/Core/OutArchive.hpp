#ifndef POLYMORPHICSERIALIZER_OUTARCHIVE_HPP
#define POLYMORPHICSERIALIZER_OUTARCHIVE_HPP

#include "../Base.hpp"
#include "../Core/Registry.hpp"
#include "../FileSystem/FileManager.hpp"
#include "../Serializable/SerializedObject.hpp"


class OutArchive
{
    using SerializedVector = std::vector<SerializedObject>;
    std::string _file_name;
public:
    OutArchive(const std::string& file_name);

    void write(std::vector<std::shared_ptr<Base>>& objects);
    std::vector<char> serializeVectorOfBase(std::vector<std::shared_ptr<Base>>& base_objs);
};

#endif //POLYMORPHICSERIALIZER_OUTARCHIVE_HPP
