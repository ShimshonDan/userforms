#include "user.h"
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <random>
#include <ctime>
#include <clocale>

#define CONST_MAX_LENGHT_LOGIN 20
#define CONST_MAX_LENGHT_PASSWORD 25

bool User::checkUsername(std::string userName) const {
	if (userName.size() < 2)
		return false;
	for (int i = 0; i < userName.size(); ++i)
		if (std::isalpha(userName[i]))
			if (!(std::tolower(userName[i]) >= 'a' && std::tolower(userName[i]) <= 'z'))
				return false;
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
			if (std::tolower(Password[i]) <= 'à' && std::tolower(Password[i]) >= 'ÿ')
				return false;
			countAlpha = true;
		}

		if (std::isspace(Password[i]))
			return false;

		if (std::isdigit(Password[i]))
			countDigit = true;

		if (std::ispunct(Password[i]))
			countPunct = true;
	}

	if (countAlpha && countDigit && countPunct)
		return true;
	return false;
}

User::User(const std::string& nUsername, const std::string& nPassword) {
	if (!checkUsername(nUsername))
		throw std::invalid_argument("unccorect UserName");
	if (!checkPassword(nPassword))
		throw std::invalid_argument("unccorect Password");

	username = nUsername;
	password = nPassword;
}

void User::setUsername(std::string nUsername) {
	if (!checkUsername(nUsername))
		throw std::invalid_argument("unccorect UserName");
	username = nUsername;
}

void User::setPassword(std::string nPassword) {
	if (!checkPassword(nPassword))
		throw std::invalid_argument("unccorect Password");
	password = nPassword;
}

std::string User::randomLogin() {
	std::string data_bE_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string data_sE_alpha = "abcdefghijklmnopqrstuvwxyz";
	std::string data_symbol = "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";

	std::srand(std::time(nullptr));

	int lenghtLogin = std::rand() % (CONST_MAX_LENGHT_LOGIN + 1);
	while (lenghtLogin < 2)
		lenghtLogin = std::rand() % (CONST_MAX_LENGHT_LOGIN + 1);

	std::string loginUser;
	int count_E_symbol = std::rand() % (lenghtLogin + 1);
	int count_bE_symbol = 0;
	int count_sE_symbol = 0;
	if (count_E_symbol) {
		count_bE_symbol = std::rand() % (count_E_symbol);
		count_sE_symbol = count_E_symbol - count_bE_symbol;
	}

	int count_symbol = lenghtLogin - count_E_symbol;
	int indexSymbol = 0;
	while (indexSymbol <= lenghtLogin) {
		int numberOper = std::rand() % 3;
		switch (numberOper) {
		case 0:
			if (count_symbol) {
				char symbol = data_bE_alpha[std::rand() % (data_bE_alpha.size())];
				loginUser += symbol;
				++indexSymbol;
			}
			continue;
		case 1:
			if (count_sE_symbol) {
				char symbol = data_sE_alpha[std::rand() % data_bE_alpha.size()];
				loginUser += symbol;
				++indexSymbol;
			}
			continue;
		case 2:
			if (count_bE_symbol) {
				char symbol = data_symbol[std::rand() % data_symbol.size()];
				loginUser += symbol;
				++indexSymbol;
			}
			continue;
		}
	}
	return loginUser;
}

std::string User::randomPassword() {
	std::string data_bE_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string data_sE_alpha = "abcdefghijklmnopqrstuvwxyz";
	std::string data_symbol = "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";
	std::string number = "0123456789";

	std::srand(std::time(nullptr));

	std::string passwordUser;
	int lenghtPassword = std::rand() % (CONST_MAX_LENGHT_PASSWORD + 1);
	while (lenghtPassword < 8) {
		lenghtPassword = std::rand() % (CONST_MAX_LENGHT_PASSWORD + 1);
	}

	int count_alpha = std::rand() % (lenghtPassword);
	if (!count_alpha)
		count_alpha += 1;

	int count_bE_alpha = std::rand() % (count_alpha);
	int count_sE_alpha = count_alpha - count_bE_alpha;

	int countSymbol = lenghtPassword - count_alpha;
	int countNumber = lenghtPassword - count_alpha - countSymbol;

	int indexPassword = 0;
	while (indexPassword <= lenghtPassword) {
		int numberOperation = std::rand() % 4;
		switch (numberOperation) {
		case 0:
			if (count_bE_alpha) {
				char symbol = data_bE_alpha[std::rand() % (data_bE_alpha.size())];
				passwordUser += symbol;
				++indexPassword;
			}
			continue;
		case 1:
			if (count_sE_alpha) {
				char symbol = data_sE_alpha[std::rand() % (data_symbol.size())];
				passwordUser += symbol;
				++indexPassword;
			}
			continue;
		case 2:
			if (countNumber) {
				char symbol = number[std::rand() % (number.size())];
				passwordUser += symbol;
				++indexPassword;
			}
			continue;
		case 3:
			if (countSymbol) {
				char symbol = data_symbol[std::rand() % (data_symbol.size())];
				passwordUser += symbol;
				++indexPassword;
			}
			continue;
		}
	}
	return passwordUser;
}

#undef CONST_MAX_LENGHT_PASSWORD
#undef CONST_MAX_LENGHT_LOGIN