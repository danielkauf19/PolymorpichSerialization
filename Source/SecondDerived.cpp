#include "../Header/SecondDerived.hpp"


Circle::Circle(): Point()
{

}

Circle::Circle(float x, float y, int r): _r(r), Point(x, y)
{
}

Circle* Circle::clone() const
{
    return new Circle();
}

size_t Circle::serializeSize() const
{
    return Point::serializeSize() + sizeof (_r);
}

void Circle::serialize(std::vector<char>& dataOut) const
{
    Point::serialize(dataOut);
    SerializablePOD<int>::serialize(_r, dataOut, Point::serializeSize());
}

void Circle::deserialize(const std::vector<char>& dataIn)
{
    Point::deserialize(dataIn);
    SerializablePOD<int>::deserialize(dataIn, _r, Point::serializeSize());
}