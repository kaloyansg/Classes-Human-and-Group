#pragma once
#include <istream>

class Human
{
	enum class Gender
	{
		Male,
		Female,
		Other
	};

	char* firstName;
	char* lastName;
	unsigned age;
	Gender gender;

public:
	Human();
	Human(const char*, const char*, const unsigned, const char*);
	Human(const Human&);
	Human& operator=(const Human&);
	~Human();

	const char* getName() const;
	const char* getFamily() const;
	const char* getGender() const;
	unsigned getAge()const;

	friend std::istream& operator>>(std::istream&, Human&);
	friend std::ostream& operator<<(std::ostream&, const Human&);
};
