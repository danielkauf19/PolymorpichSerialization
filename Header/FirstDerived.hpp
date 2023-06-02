#ifndef POLYMORPHICSERIALIZER_FIRSTDERIVED_HPP
#define POLYMORPHICSERIALIZER_FIRSTDERIVED_HPP

#include "Base.hpp"

class Point : public Base
{
private:
    float _x;
    float _y;

public:
    Point();
    Point(float, float);
    virtual Point* clone() const;
    virtual size_t serializeSize() const;
    virtual void serialize(std::vector<char>& data_out) const;
    virtual void deserialize(const std::vector<char>& data_in);

    void print();
};

#endif //POLYMORPHICSERIALIZER_FIRSTDERIVED_HPP
