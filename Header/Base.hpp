#ifndef POLYMORPHICSERIALIZER_BASE_HPP
#define POLYMORPHICSERIALIZER_BASE_HPP

#include <iostream>

#include "./Serializable/Serializable.hpp"
#include "./Serializable/PolymorphicSerializable.hpp"
#include "./Serializable/SerializablePOD.hpp"
#include "./Utils/StringManipulations.hpp"


class Base : public Serializable, public PolymorphicSerializable<Base>
{
protected:
    std::string name;

public:
    virtual ~Base()
    {}

};

#endif //POLYMORPHICSERIALIZER_BASE_HPP
