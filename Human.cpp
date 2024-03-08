#include "Human.h"
#pragma warning (disable:4996)

Human::Human()
{
	firstName = new (std::nothrow) char[strlen("Name") + 1];
	lastName = new (std::nothrow) char[strlen("Family") + 1];

	if (!firstName || !lastName)
	{
		if (firstName)
			delete[] firstName;
		if (lastName)
			delete[] lastName;
		throw std::bad_alloc();
	}

	strcpy(firstName, "Name");
	strcpy(lastName, "Family");

	age = 0;
	gender = Gender::Other;
}

Human::Human(const char* name, const char* family, const unsigned age, const char* sex)
{
	firstName = new (std::nothrow) char[strlen(name) + 1];
	lastName = new (std::nothrow) char[strlen(family) + 1];

	if (!firstName || !lastName)
	{
		if (firstName)
			delete[] firstName;
		if (lastName)
			delete[] lastName;
		throw std::bad_alloc();
	}

	strcpy(firstName, name);
	strcpy(lastName, family);

	this->age = age;

	if (strcmp(sex, "Male") == 0)
		this->gender = Gender::Male;
	else if (strcmp(sex, "Male") == 0)
		this->gender = Gender::Female;
	else
	{
		this->gender = Gender::Other;
	}
}

Human::Human(const Human& other)
{
	this->firstName = new (std::nothrow) char[strlen(other.firstName) + 1];
	this->lastName = new (std::nothrow) char[strlen(other.lastName) + 1];

	if (!firstName || !lastName)
	{
		if (firstName)
			delete[] firstName;
		if (lastName)
			delete[] lastName;
	}

	strcpy(firstName, other.firstName);
	strcpy(lastName, other.lastName);

	this->age = other.age;
	this->gender = other.gender;
}

Human& Human::operator=(const Human& other)
{
	if (this == &other)
		return *this;

	char* tempFirstName = new (std::nothrow) char[strlen(other.firstName) + 1];
	char* tempLastName = new (std::nothrow) char[strlen(other.lastName) + 1];

	if (!tempFirstName || !tempLastName)
	{
		if (tempFirstName)
			delete[] tempFirstName;
		if (tempLastName)
			delete[] tempLastName;
		throw std::bad_alloc();
	}

	strcpy(tempFirstName, other.firstName);
	strcpy(tempLastName, other.lastName);

	delete[] this->firstName;
	firstName = tempFirstName;
	delete[] this->lastName;
	lastName = tempLastName;

	this->age = other.age;
	this->gender = other.gender;

	return *this;
}

Human::~Human()
{
	delete[] firstName;
	firstName = nullptr;
	delete[] lastName;
	lastName = nullptr;
}

const char* Human::getName() const
{
	return firstName;
}

const char* Human::getFamily() const
{
	return lastName;
}

const char* Human::getGender() const
{
	switch (gender)
	{
	case Human::Gender::Male: return "Male";
		break;
	case Human::Gender::Female: return "Female";
		break;
	case Human::Gender::Other: return "Other";
		break;
	}

	return "Other";
}

unsigned Human::getAge() const
{
	return age;
}

std::istream& operator>>(std::istream& input, Human& human)
{
	char tempFirstName[32];
	char tempLastName[32];

	input.getline(tempFirstName, 32, ',');
	if (!input)
		throw "Problem reading first name!";

	input.getline(tempLastName, 32, ',');
	if (!input)
		throw "Problem reading last name!";

	char gender[7];
	input.getline(gender, 7, ',');
	if (!input)
		throw "Problem reading gender!";

	unsigned age;
	input >> age;
	if (!input)
		throw "Problem reading age!";

	input.ignore();

	char* newFirstName = new (std::nothrow) char[strlen(tempFirstName) + 1];
	char* newLastName = new (std::nothrow) char[strlen(tempLastName) + 1];

	if (!newFirstName || !newLastName)
	{
		if (newFirstName)
			delete[] newFirstName;
		if (newLastName)
			delete[] newLastName;
		throw std::bad_alloc();
	}

	strcpy(newFirstName, tempFirstName);
	strcpy(newLastName, tempLastName);

	delete[] human.firstName;
	delete[] human.lastName;

	human.firstName = newFirstName;
	human.lastName = newLastName;

	if (strcmp(gender, "Male") == 0)
		human.gender = Human::Gender::Male;
	else if (strcmp(gender, "Female") == 0)
		human.gender = Human::Gender::Female;
	else
		human.gender = Human::Gender::Other;

	human.age = age;

	return input;
}

std::ostream& operator<<(std::ostream& output, const Human& human)
{
	output << human.firstName << "," << human.lastName << "," << human.getGender() << "," << human.age << "\n";
	return output;
}
