#ifndef POLYMORPHICSERIALIZER_POLYMORPHICSERIALIZABLE_HPP
#define POLYMORPHICSERIALIZER_POLYMORPHICSERIALIZABLE_HPP

template<typename Base>
class PolymorphicSerializable
{
public:
    virtual Base* clone() const = 0;
};

#endif //POLYMORPHICSERIALIZER_POLYMORPHICSERIALIZABLE_HPP
