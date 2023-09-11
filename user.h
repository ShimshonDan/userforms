#include <iostream>
#include <string>

class User {
private:
	std::string username;
	std::string password;
	bool checkUsername(std::string userName) const;
	bool checkPassword(std::string Password) const;

public:
	User(const std::string& nUsername, const std::string& nPassword);

	void setUsername(std::string nUsername);
	void setPassword(std::string nPassword);

	std::string getUsername() const { return username; }
	std::string getPassword() const { return password; }

	std::string randomLogin();
	std::string randomPassword();
};