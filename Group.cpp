#include "Group.h"

void Group::addPerson(const Human& human)
{
	Human* tempPeople = new Human[number + 1];
	for (size_t i = 0; i < number; i++)
	{
		tempPeople[i] = people[i];
	}
	tempPeople[number] = human;
	delete[] people;
	people = tempPeople;
	++number;
}

Group::Group()
{
	people = nullptr;
	number = 0;
}

Group::Group(Human* arr, unsigned n)
{
	people = new Human[n];
	number = n;
	for (size_t i = 0; i < n; ++i)
	{
		people[i] = arr[i];
	}
}

Group::Group(const char* fileName)
{
	std::ifstream file(fileName);
	char a;

	number = 0;
	people = nullptr;
	
	file >> a;
	while (!file.eof())
	{
		file.seekg(-1, std::ios::cur);
		Human tempHuman;
		file >> tempHuman;
		this->addPerson(tempHuman);
		file >> a;
	}

	file.close();
}

Group::Group(const Group& other)
{
	people = new Human[other.number];
	number = other.number;
	for (size_t i = 0; i < number; ++i)
	{
		people[i] = other.people[i];
	}
}

Group& Group::operator=(const Group& other)
{
	if (this == &other)
		return *this;

	Human* tempPeople = new Human[other.number];
	unsigned n = other.number;
	for (size_t i = 0; i < n; ++i)
	{
		tempPeople[i] = other.people[i];
	}

	delete[] people;
	people = tempPeople;
	number = n;

	return *this;
}

Group::~Group()
{
	delete[] people;
	people = nullptr;
}

void Group::save(const char* fileName) const
{
	std::ofstream file(fileName);
	for (size_t i = 0; i < number; ++i)
	{
		file << people[i];
	}
	file.close();
}

unsigned Group::getNumber() const
{
	return number;
}

const Human& Group::operator[](unsigned index) const
{
	if (index >= number)
		throw "Invalid index";

	return people[index];
}

Human& Group::operator[](unsigned index)
{
	if (index >= number)
		throw "Invalid index";

	return people[index];
}
