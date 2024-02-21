#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	data->s = "Hello";
	data->n = 42;

	uintptr_t raw = Serializer::serialize(data);
	Data *data2 = Serializer::deserialize(raw);

	std::cout << "data and data2 before change " << std::endl;
	std::cout << "data: " << data << ", &data: " << &data << std::endl;
	std::cout << "data->s: " << data->s << std::endl;
	std::cout << "data->n: " << data->n << std::endl;
	std::cout << "data2: " << data2 << ", &data2: " << &data2 << std::endl;
	std::cout << "data2->s: " << data2->s << std::endl;
	std::cout << "data2->n: " << data2->n << std::endl;

	std::cout << "------------------------" << std::endl;

	std::cout << "change data" << std::endl;
	data->s = "World";
	data->n = 21;
	std::cout << "data: " << data << ", &data: " << &data << std::endl;
	std::cout << "data->s: " << data->s << std::endl;
	std::cout << "data->n: " << data->n << std::endl;
	std::cout << "data2: " << data2 << ", &data2: " << &data2 << std::endl;
	std::cout << "data2->s: " << data2->s << std::endl;
	std::cout << "data2->n: " << data2->n << std::endl;

	std::cout << "------------------------" << std::endl;

	std::cout << "change data2" << std::endl;
	data2->s = "Hello World";
	data2->n = 63;
	std::cout << "data: " << data << ", &data: " << &data << std::endl;
	std::cout << "data->s: " << data->s << std::endl;
	std::cout << "data->n: " << data->n << std::endl;
	std::cout << "data2: " << data2 << ", &data2: " << &data2 << std::endl;
	std::cout << "data2->s: " << data2->s << std::endl;
	std::cout << "data2->n: " << data2->n << std::endl;

	delete data;

	return (0);
}