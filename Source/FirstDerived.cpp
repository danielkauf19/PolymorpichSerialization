#include "../Header/FirstDerived.hpp"


Point::Point()
{
}

Point::Point(float x, float y): _x(x), _y(y)
{
}

Point* Point::clone() const
{
    return new Point();
}

size_t Point::serializeSize() const
{
    return sizeof(_x) + sizeof (_y);
}

void Point::serialize(std::vector<char>& dataOut) const
{
    SerializablePOD<float>::serialize(_x, dataOut);
    SerializablePOD<float>::serialize(_y, dataOut, sizeof(_x));

}

void Point::deserialize(const std::vector<char>& dataIn)
{
    SerializablePOD<float>::deserialize(dataIn, _x);
    SerializablePOD<float>::deserialize(dataIn, _y, sizeof(_x));
}