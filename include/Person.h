#pragma once
#include <string>
using namespace std;

class Person
{
protected:
	//attributes:
	string name, password;
	int id;

public:
	//constructors:
	Person() {
		id = 0;
		id++;
	}
	Person(string name, string password, int id) {
		this->id = id;
		this->name = name;
		this->password = password;
	}

	virtual void display() = 0;
};
