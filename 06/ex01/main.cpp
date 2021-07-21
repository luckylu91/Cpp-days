#include <cstdint>
#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	Data d = {.n = 10, .comment = "les struct c'est la class"};
	uintptr_t dSerialized = serialize(&d);
	Data *dBis = deserialize(dSerialized);
	std::cout << "d and dBis are " << (d == *dBis ? "equals" : "not equals") << std::endl;
}
