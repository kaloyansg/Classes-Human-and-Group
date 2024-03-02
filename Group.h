#pragma once
#include "Human.h"
#include "fstream"

class Group
{
	Human* people;
	unsigned number;

	void addPerson(const Human&);

public:
	Group();
	Group(Human*, unsigned);
	Group(const char*);
	Group(const Group&);
	Group& operator=(const Group&);
	~Group();

	void save(const char*) const;
	unsigned getNumber() const;
	const Human& operator[](unsigned index) const;
	Human& operator[](unsigned index);
};

