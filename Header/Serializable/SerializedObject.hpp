#ifndef POLYMORPHICSERIALIZER_SERIALIZEDOBJECT_HPP
#define POLYMORPHICSERIALIZER_SERIALIZEDOBJECT_HPP

#include "Serializable.hpp"

// the struct created to manage serializing the
// original object using metadata as their type_info
// struct also managing size of each field
struct SerializedObject
{
    std::vector<char> _type_info;
    std::vector<char> _raw_data;

    void serialize(std::vector<char>& buffer) const
    {
        size_t type_info_size = _type_info.size();
        buffer.insert(buffer.end(), reinterpret_cast<const char*>(&type_info_size), reinterpret_cast<const char*>(&type_info_size) + sizeof(size_t));
        buffer.insert(buffer.end(), _type_info.begin(), _type_info.end());

        size_t data_size = _raw_data.size();
        buffer.insert(buffer.end(), reinterpret_cast<const char*>(&data_size), reinterpret_cast<const char*>(&data_size) + sizeof(size_t));
        buffer.insert(buffer.end(), _raw_data.begin(), _raw_data.end());
    }

    void deserialize(const std::vector<char>& buffer, size_t& offset)
    {
        size_t type_info_size;
        std::memcpy(&type_info_size, &buffer[offset], sizeof(size_t));
        offset += sizeof(size_t);

        _type_info.resize(type_info_size);
        std::memcpy(_type_info.data(), &buffer[offset], type_info_size);
        offset += type_info_size;

        size_t data_size;
        std::memcpy(&data_size, &buffer[offset], sizeof(size_t));
        offset += sizeof(size_t);

        _raw_data.resize(data_size);
        std::memcpy(_raw_data.data(), &buffer[offset], data_size);
        offset += data_size;
    }
};

#endif //POLYMORPHICSERIALIZER_SERIALIZEDOBJECT_HPP
