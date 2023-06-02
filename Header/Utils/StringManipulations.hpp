#ifndef POLYMORPHICSERIALIZER_STRINGMANIPULATIONS_HPP
#define POLYMORPHICSERIALIZER_STRINGMANIPULATIONS_HPP

#include <memory>
#include <algorithm>
#include <cstring>

class StringManipulations
{
public:
    template<typename T>
    static std::string clearNullTerminators(T buffer)
    {
        std::string result(buffer.begin(), buffer.end());
        result.erase(std::remove(result.begin(), result.end(), '\0'), result.end());

        return result;
    }

};

#endif //POLYMORPHICSERIALIZER_STRINGMANIPULATIONS_HPP
