#include "../../Header/FileSystem/FileManager.hpp"

FileManager::FileManager(const std::string& filename, FILE_FLAG flag): _flag(flag)
{
    if(_flag == FILE_FLAG::WRITE)
    {
        _ofstream.open(filename);
        _ofstream.exceptions(std::ofstream::failbit | std::ofstream::badbit);
        return;
    }

    _ifstream.open(filename);
    _ofstream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    if(!_ofstream && !_ifstream)
    {
        throw std::runtime_error("Couldn't open file");
    }
}

FileManager::~FileManager()
{
    // not closing the files as ofstream and ifstream already closes at its destructor
}

bool FileManager::isOpen() const
{
    if(_flag == FILE_FLAG::WRITE)
    {
        return _ofstream.is_open();
    }
    return _ifstream.is_open();
}

void FileManager::write(const char* data, size_t size)
{
    try
    {
        if (isOpen()) {
            _ofstream.write(data, size);

            _ofstream.close();
        }
    }
    catch(std::exception& ex)
    {
        throw std::runtime_error("Couldn't read file");
    }
}

void FileManager::read(char* data, size_t size)
{
    try
    {
        if (isOpen()) {
            _ifstream.read(data, size);

            _ifstream.close();
        }
    }
    catch(std::exception& ex)
    {
        throw std::runtime_error("Couldn't read file");
    }

}

size_t FileManager::getFileRawDataSize()
{
    _ifstream.seekg(0, std::ios::end);
    checkOperationFailed("Couldn't seekg.");

    std::streampos file_size = _ifstream.tellg();
    checkOperationFailed("Couldn't tellg.");

    _ifstream.seekg(0, std::ios::beg);
    checkOperationFailed("Couldn't seekg.");

    return file_size;
}

void FileManager::checkOperationFailed(char* message)
{
    if (_ifstream.fail())
    {
        throw std::runtime_error(message);
    }
}