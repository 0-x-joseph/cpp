#include "Data.hpp"
#include "Serializer.hpp"
#include <cstdint>
#include <iostream>

int main() {
  Data my_data;

  my_data.id = 42;
  my_data.name = "Joseph";
  my_data.content = "Hello Bitches";

  std::cout << "Original Pointer" << &my_data << std::endl;

  uintptr_t raw = Serializer::serialize(&my_data);
  std::cout << "Serialized value: " << raw << std::endl;

  Data *ptr = Serializer::deserialize(raw);
  std::cout << "Deserialized value: " << ptr << std::endl;

  if (ptr == &my_data) {
    std::cout << "Success: Pointers match" << std::endl;
    std::cout << "id: " << ptr->id << ", name: " << ptr->name << std::endl;
  } else {
    std::cout << "Failure: pointers do not match" << std::endl;
  }

  return (0);
}
