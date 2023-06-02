#ifndef POLYMORPHICSERIALIZER_FILEMANAGER_HPP
#define POLYMORPHICSERIALIZER_FILEMANAGER_HPP

#include <fstream>
#include <ostream>
#include <string>

enum class FILE_FLAG
{
    READ,
    WRITE
};

class FileManager
{

private:
    std::ifstream _ifstream;
    std::ofstream _ofstream;
    FILE_FLAG _flag;

public:
    FileManager(const std::string& filename, FILE_FLAG flag);

    ~FileManager();

    bool isOpen() const;
    void write(const char* data, size_t size);
    void read(char* data, size_t size);
    size_t getFileRawDataSize();
    void checkOperationFailed(char* message);
};

#endif //POLYMORPHICSERIALIZER_FILEMANAGER_HPP
