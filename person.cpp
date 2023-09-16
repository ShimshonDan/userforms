#include "person.h"
#include "Error.h"
#include <cstring>
#include <string>
#include <iostream>

bool Person::checkNumberphone(const std::string& numberphone){
	if (numberphone.size() < 9 || numberphone.size() > 13)
		throw ErrorNumber("Unccorct numer size");

	if (numberphone[0] != '+')
		if (numberphone[0] != '8')
			if (numberphone[0] != '7')
				if (numberphone[0] != '9')
					throw ErrorNumber("Unccorct number phone!");

	for (int i = 1; i < numberphone.size(); ++i)
		if (!(std::isdigit(numberphone[i]))) {
			std::cout << numberphone[i] << "\n";
			throw ErrorNumber("The number phone must not nothing all but digit!");
		}
	return true;
}

bool Person::checkAge(short int age) {
	if (11 >= age && age <= 99)
		throw ErrorAge("Unccort age!");
	return true;
}

Person::Person(const std::string& n_name,
			   const std::string& n_secondname,
			   const std::string& n_surname,
			   const std::string& n_numberphone,
			   short int n_age) :
			   name{ n_name }, secondname{ n_secondname }, surname{ n_surname },
	           numberphone{ n_numberphone }, age{ n_age }
{	
	this->name = n_name;
	this->surname = n_surname;
	this->secondname = n_secondname;
	if(checkNumberphone(n_numberphone))
		this->numberphone = n_numberphone;
	if (checkAge(n_age))
		this->age = n_age;
}

void Person::setSurname(const std::string& n_surname) {
	this->surname = n_surname;
}
void Person::setName(const std::string& n_name){
	this->name = n_name;
}
void Person::setSecondName(const std::string& n_secondname) {
	this->secondname = n_secondname;
}
void Person::setNumberphone(const std::string& n_numberpnoe) {
	if (checkNumberphone(n_numberpnoe))
		this->numberphone = n_numberpnoe;
}
void Person::setAge(short int n_age) {
	if (checkAge(n_age))
		this->age = n_age;
}

std::string Person::allData() const {
	return "Secondname:" + this->secondname + "\n" +
		   "Name: " + this->name + "\n" +
	 	   "Surname: " + this->surname + "\n" +
		   "Number phone: " + this->numberphone + "\n" +
    	   "age: " + std::to_string(this->age) + "\n";
}