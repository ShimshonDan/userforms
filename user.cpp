#include "user.h"
#include "Error.h"
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <random>
#include <ctime>
#include <clocale>

#define CONST_MAX_LENGHT_LOGIN 20
#define CONST_MAX_LENGHT_PASSWORD 25
#define getRandom(max) rand()%max

bool User::checkUsername(std::string userName) const {
	if (userName.size() < 2)
		return false;
	for (int i = 0; i < userName.size(); ++i)
		if (std::isalpha(userName[i]))
			if (!(std::tolower(userName[i]) >= 'a' && std::tolower(userName[i]) <= 'z'))
				throw ErrorLoggin("a non-English letter is used");
	return true;
}

bool User::checkPassword(std::string Password) const {
	std::setlocale(LC_ALL, "Ru");
	if (Password.size() <= 5)
		return false;

	bool countAlpha = 0;
	bool countPunct = 0;
	bool countDigit = 0;

	for (int i = 0; i < Password.size(); ++i) {
		if (std::isalpha(Password[i])) {
			if (!(std::tolower(Password[i]) <= 'a' && std::tolower(Password[i]) >= 'z'))
				throw ErrorPassword("A non-English letter is used");
			countAlpha = true;
		}

		if (std::isspace(Password[i]))
			throw ErrorPassword("The password must not contain spaces");

		if (std::isdigit(Password[i]))
			countDigit = true;

		if (std::ispunct(Password[i]))
			countPunct = true;
	}

	if (!countAlpha)
		throw ErrorPassword("The password must contain a letter!");
	if (!countDigit)
		throw ErrorPassword("The password must contain a digit!");
	if (!countPunct)
		throw ErrorPassword("The password must contain special characters!");
	return true;
}

User::User(const std::string& nUsername, const std::string& nPassword) {
	if (checkUsername(nUsername))
		username = nUsername;
	if (checkPassword(nPassword))
		password = nPassword;
}

void User::setUsername(const std::string& nUsername) {
	if (checkUsername(nUsername))
		username = nUsername;
}

void User::setPassword(const std::string& nPassword) {
	if (checkPassword(nPassword))
		password = nPassword;
}

void User::randomLogin() {
	const std::string data_bE_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const std::string data_sE_alpha = "abcdefghijklmnopqrstuvwxyz";
	const std::string data_symbol = "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";

	std::srand(std::time(nullptr));

	int lenghtLogin = getRandom(CONST_MAX_LENGHT_LOGIN + 1);
	while (lenghtLogin < 2)
		lenghtLogin = getRandom(CONST_MAX_LENGHT_LOGIN + 1);

	std::string loginUser;
	int count_E_symbol = getRandom(lenghtLogin + 1);
	int count_bE_symbol = 0;
	int count_sE_symbol = 0;
	if (count_E_symbol) {
		count_bE_symbol = getRandom(count_E_symbol);
		count_sE_symbol = count_E_symbol - count_bE_symbol;
	}

	int count_symbol = lenghtLogin - count_E_symbol;
	int indexSymbol = 0;
	while (indexSymbol <= lenghtLogin) {
		int numberOper = getRandom(3);
		switch (numberOper) {
		case 0:
			if (count_symbol) {
				char symbol = data_bE_alpha[getRandom(data_bE_alpha.size())];
				loginUser += symbol;
				++indexSymbol;
			}
			continue;
		case 1:
			if (count_sE_symbol) {
				char symbol = data_sE_alpha[getRandom(data_bE_alpha.size())];
				loginUser += symbol;
				++indexSymbol;
			}
			continue;
		case 2:
			if (count_bE_symbol) {
				char symbol = data_symbol[getRandom(data_symbol.size())];
				loginUser += symbol;
				++indexSymbol;
			}
			continue;
		}
	}
	username =  loginUser;
}

void User::randomPassword() {
	std::string data_bE_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string data_sE_alpha = "abcdefghijklmnopqrstuvwxyz";
	std::string data_symbol = "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";
	std::string number = "0123456789";

	std::srand(std::time(nullptr));

	std::string passwordUser;
	int lenghtPassword = getRandom(CONST_MAX_LENGHT_PASSWORD + 1);
	while (lenghtPassword < 8)
		lenghtPassword = getRandom(CONST_MAX_LENGHT_PASSWORD + 1);

	int count_alpha = getRandom(lenghtPassword);
	if (!count_alpha)
		count_alpha += 1;

	int count_bE_alpha = getRandom(count_alpha);
	int count_sE_alpha = count_alpha - count_bE_alpha;

	int countSymbol = lenghtPassword - count_alpha;
	int countNumber = lenghtPassword - count_alpha - countSymbol;

	int indexPassword = 0;
	while (indexPassword <= lenghtPassword) {
		int numberOperation = std::rand() % 4;
		switch (numberOperation) {
		case 0:
			if (count_bE_alpha) {
				char symbol = data_bE_alpha[getRandom(data_bE_alpha.size())];
				passwordUser += symbol;
				++indexPassword;
			}
			continue;
		case 1:
			if (count_sE_alpha) {
				char symbol = data_sE_alpha[getRandom(data_symbol.size())];
				passwordUser += symbol;
				++indexPassword;
			}
			continue;
		case 2:
			if (countNumber) {
				char symbol = number[getRandom(number.size())];
				passwordUser += symbol;
				++indexPassword;
			}
			continue;
		case 3:
			if (countSymbol) {
				char symbol = data_symbol[getRandom(data_symbol.size())];
				passwordUser += symbol;
				++indexPassword;
			}
			continue;
		}
	}
	password = passwordUser;
}

#undef CONST_MAX_LENGHT_PASSWORD
#undef CONST_MAX_LENGHT_LOGIN
#undef getRandom