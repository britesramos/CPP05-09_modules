#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr); //Used to convert a pointer to any other type of pointer.
}

Data* Serializer::deserializer(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw); //Used to convert a pointer to any other type of pointer.
}