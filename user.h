#include <iostream>
#include <string>
#include "person.h"
class User : public Person{
	public:
		User(const std::string& nUsername,
			 const std::string& nPassword,
			 const std::string& n_name, const std::string& n_secondname,
			 const std::string& n_surname, const std::string& n_numberphone,
			 short int age);

		void setUsername(const std::string& nUsername);
		void setPassword(const std::string& nPassword);
		void setDataPerson(const std::string& n_name,
						   const std::string& n_secondname,
						   const std::string&  n_surname,
						   const std::string& n_numberphone,
						   short int n_age);

		std::string getUsername() const { return username; }
		std::string getPassword() const { return password; }
		std::string getAllData() const;

		void randomLogin();
		void randomPassword();
	
	private:
		std::string username = "User";
		std::string password;
		bool checkUsername(const std::string& userName) const;
		bool checkPassword(const std::string& Password) const;
};