#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string s;
	int n;
};

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const &rhs);
	~Serializer();
	Serializer &operator=(Serializer const &rhs);

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif