#include "Serializer.hpp"

int main()
{
	Data* ptr = new Data;
	ptr->name = "Testing Data struct";

	std::cout << PINK << "Original pointer: " << ptr << RESET << std::endl;
	std::cout << BLUE << "Original name: " << ptr->name << RESET << std::endl;

	uintptr_t address = Serializer::serialize(ptr);
	std::cout << "Serialized address: 0x" << std::hex << address << std::dec << std::endl;

	Data* newptr = Serializer::deserializer(address);
	std::cout << PINK << "Deserialized pointer: " << newptr << RESET << std::endl;
	std::cout << BLUE << "Deserialized name: " << newptr->name  << RESET << std::endl;
	
	if (newptr == ptr)
		std::cout << GREEN << "SUCCESS!" << RESET << std::endl;
	return (0);
}