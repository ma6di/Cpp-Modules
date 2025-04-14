
#include "Serializer.hpp"
#include <iostream>

int main() {
    Data original;
    original.id = 42;
    original.name = "Hello";

    uintptr_t raw = Serializer::serialize(&original);
    Data* result = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &original << std::endl;
    std::cout << "Deserialized pointer: " << result << std::endl;

    std::cout << "Data.id: " << result->id << std::endl;
    std::cout << "Data.name: " << result->name << std::endl;

    if (&original == result)
        std::cout << "✅ Pointers match!" << std::endl;
    else
        std::cout << "❌ Pointers do NOT match!" << std::endl;
    return 0;
}

