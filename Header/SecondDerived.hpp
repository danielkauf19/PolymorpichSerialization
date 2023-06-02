#ifndef POLYMORPHICSERIALIZER_SECONDDERIVED_HPP
#define POLYMORPHICSERIALIZER_SECONDDERIVED_HPP

#include "FirstDerived.hpp"

class Circle : public Point
{
private:
    int _r;

public:
    Circle();
    Circle(float, float, int);
    virtual Circle* clone() const;
    virtual size_t serializeSize() const;
    virtual void serialize(std::vector<char>& data_out) const;
    virtual void deserialize(const std::vector<char>& data_in);
};

#endif //POLYMORPHICSERIALIZER_SECONDDERIVED_HPP
