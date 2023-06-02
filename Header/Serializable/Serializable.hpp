#ifndef POLYMORPHICSERIALIZER_SERIALIZABLE_HPP
#define POLYMORPHICSERIALIZER_SERIALIZABLE_HPP

#include <vector>
#include <cstddef>
#include <cstring>


class Serializable
{
public:
    virtual size_t serializeSize() const = 0;
    virtual void serialize(std::vector<char>&) const = 0;
    virtual void deserialize(const std::vector<char>&) = 0;
};

#endif //POLYMORPHICSERIALIZER_SERIALIZABLE_HPP
