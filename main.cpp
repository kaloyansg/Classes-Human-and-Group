#include <iostream>
#include <fstream>
#include "Human.h"
#include "Group.h"

#pragma warning (disable:4996)

/*enum class Gender
{
    Male,
    Female,
    Other
};

std::ostream& operator<<(std::ostream& os, const Gender sex)
{
    switch (sex)
    {
    case Gender::Male: os << "Male";
        break;
    case Gender::Female: os << "Female";
        break;
    case Gender::Other: os << "Other";
        break;
    }

    return os;
}

std::istream& operator>>(std::istream& is, Gender& sex)
{
    char gender[7];
    is >> gender;
    if (strcmp(gender, "Male") == 0)
        sex = Gender::Male;
    else if (strcmp(gender, "Female") == 0)
        sex = Gender::Female;
    else
    {
        sex = Gender::Other;
    }


    return is;
}

struct Human
{
    char firstName[24];
    char lastName[24];
    unsigned age;
    Gender sex;
};

Human* getPeople(std::ostream& output, std::istream& input, const unsigned n)
{
    Human* result = new Human[n];

    for (size_t i = 0; i < n; ++i)
    {
        output << "Enter two names:";
        input >> result[i].firstName;
        input >> result[i].lastName;
        output << "Enter sex /Male,Female,Other/: ";
        input >> result[i].sex;
        output << "Enter age:";
        input >> result[i].age;
    }

    return result;
}

void printHumans(std::ostream& output, const Human* const people, const unsigned n)
{
    for (size_t i = 0; i < n; ++i)
    {
        output << people[i].firstName << " " << people[i].lastName << " " << people[i].sex << " " << people[i].age << "\n";
    }
}*/


int main()
{

    /*Human kalata("Kaloyan", "Georgiev", 20, "Male");
    Human pesho("Pesho", "Armqnov", 45, "Male");

    Human* arr = new Human[3];
    arr[0] = kalata;
    arr[1] = pesho;

    Group gang(arr, 3);

    gang.save("group.txt");

    delete[] arr;*/

    Group gang("group.txt");
    unsigned n = gang.getNumber();
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << gang[i];
    }
}