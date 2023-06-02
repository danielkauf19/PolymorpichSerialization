#ifndef POLYMORPHICSERIALIZER_SERIALIZABLEPOD_HPP
#define POLYMORPHICSERIALIZER_SERIALIZABLEPOD_HPP

#include <iostream>
#include <cstring>


template <typename POD>
class SerializablePOD
{
public:
    static size_t serializeSize(POD data)
    {
        return sizeof(POD);
    }

    static void serialize(const POD& data, std::vector<char>& buffer, size_t offset = 0)
    {
        const char* dataPtr = reinterpret_cast<const char*>(&data);
        std::memcpy(buffer.data() + offset, dataPtr, serializeSize(data));
    }

    static void deserialize(std::vector<char> buffer, POD& data, size_t offset = 0)
    {
        const char* bufferPtr = buffer.data();
        std::memcpy(&data, bufferPtr + offset, serializeSize(data));
    }
};

#endif //POLYMORPHICSERIALIZER_SERIALIZABLEPOD_HPP
