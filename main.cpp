#include "Header/Core/InArchive.hpp"
#include "Header/Core/OutArchive.hpp"

#include "Header/SecondDerived.hpp"


int main() {
    std::vector<std::shared_ptr<Base>> objects;
    objects.push_back(std::make_shared<Point>(1,2));
    objects.push_back(std::make_shared<Point>(3,4));
    objects.push_back(std::make_shared<Circle>(0,0,10));

    OutArchive write_archive("out.dat");
    write_archive.write(objects);

    std::vector<std::shared_ptr<Base>> loaded_objects;

    InArchive read_archive("out.dat");
    read_archive.read(loaded_objects);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
