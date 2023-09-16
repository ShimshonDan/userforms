#pragma once
#include <string>

class Person{
	public:
		Person(const std::string& n_name,
			   const std::string& n_secondname,
			   const std::string& n_surname,
			   const std::string& n_numberphone,
			   short int n_age);

		std::string getSurname() const { return this->surname; }
		std::string getName() const { return this->name; }
		std::string getSecondname() const { return this->secondname; }
		std::string getNumberphone() const { return this->numberphone; }
		std::string getAge() const { return std::to_string(this->age); }

		void setSurname(const std::string& n_surname);
		void setName(const std::string& n_name);
		void setSecondName(const std::string& n_secondname);
		void setNumberphone(const std::string& n_numberpnoe);
		void setAge(short int n_age);

		std::string allData() const;
	
	private:
		std::string surname = "Ivanov";
		std::string name = "Ivan";
		std::string secondname;
		std::string numberphone = "+799999999999";
		short int age = 99;

		bool checkNumberphone(const std::string& numberphone);
		bool checkAge(short int age);
};

