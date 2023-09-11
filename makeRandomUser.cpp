#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <random>
#include <ctime>
#include <clocale>

#define CONST_COUNT_RANDOM 100
#define CONST_COUNT_R_RANDOM 100
#define CONST_MAX_LENGHT_LOGIN 20
#define CONST_MAX_LENGHT_PASSWORD 25

void allSymbols() {
	std::ofstream fout("dataSymbols.txt");
	for (char i = 'à'; i <= 'ÿ'; ++i) // à - ÿ
		fout << i;
	fout << "\n";
	for (char i = 'À'; i <= 'ß'; ++i) // À - ß
		fout << i;
	fout << "\n";
	for (char i = 'a'; i <= 'z'; ++i)
		fout << i;
	fout << "\n";
	for (char i = 'A'; i <= 'Z'; ++i)
		fout << i;
	fout << "\n";
	for (int i = 0; i <= 9; ++i)
		fout << i;
	fout << "\n!#$%&'()*+,-./:;<=>?@[]^_`{|}~";
	fout.close();
}

void randomSymbol(const std::vector<std::string>& dataSymbols) {
	std::srand(std::time(nullptr));
	std::ofstream fout("randomSymbol.txt");
	for (int i = 0; i < 100; ++i) {
		fout << i << ":\n";
		int index = std::rand() % (dataSymbols[0].size());
		fout << "[0, " << dataSymbols[0].size() << "] " << index << " -> " << dataSymbols[0][index] << "\n";
		index = std::rand() % (dataSymbols[1].size());
		fout << "[0, " << dataSymbols[1].size() << "] " << index << " -> " << dataSymbols[1][index] << "\n";
		index = std::rand() % (dataSymbols[2].size());
		fout << "[0, " << dataSymbols[2].size() << "] " << index << " -> " << dataSymbols[2][index] << "\n";
		index = std::rand() % (dataSymbols[3].size());
		fout << "[0, " << dataSymbols[3].size() << "] " << index << " -> " << dataSymbols[3][index] << "\n";
		index = std::rand() % (dataSymbols[4].size());
		fout << "[0, " << dataSymbols[4].size() << "] " << index << " -> " << dataSymbols[4][index] << "\n";
		index = std::rand() % (dataSymbols[5].size());
		fout << "[0, " << dataSymbols[5].size() << "] " << index << " -> " << dataSymbols[5][index] << "\n";
		fout << std::endl;
	}
	fout.close();
}

void randomUncorectLogin(const std::vector<std::string>& dataSymbols) {
	std::srand(std::time(nullptr));
	std::setlocale(LC_ALL, "Ru");
	std::ofstream fout("randomUncorectUserLogin.txt");
	int countUser = 0;
	while (countUser < CONST_COUNT_RANDOM) {
		int lenghtLogin = std::rand() % (CONST_MAX_LENGHT_LOGIN + 1);
		std::string loginUser;
		while (lenghtLogin < 2)
			lenghtLogin = std::rand() % (CONST_MAX_LENGHT_LOGIN + 1);
		int count_E_symbol = std::rand() % (lenghtLogin + 1);
		int count_bE_symbol = 0;
		int count_sE_symbol = 0;
		if (count_E_symbol) {
			count_bE_symbol = std::rand() % (count_E_symbol);
			count_sE_symbol = count_E_symbol - count_bE_symbol;
		}

		int count_R_symbol = lenghtLogin - count_E_symbol;
		int count_bR_symbol = 0;
		int count_sR_symbol = 0;
		if (count_R_symbol) {
			count_bR_symbol = std::rand() % (count_R_symbol);
			count_sR_symbol = count_R_symbol - count_bR_symbol;
		}

		int indexSymbol = 0;
		while (indexSymbol <= lenghtLogin) {
			int numberOper = std::rand() % 4;
			switch (numberOper) {
			case 0:
				if (count_bR_symbol) {
					char symbol = dataSymbols[0][std::rand() % (dataSymbols[0].size())];
					loginUser += symbol;
					++indexSymbol;
				}
				continue;
			case 1:
				if (count_sR_symbol) {
					char symbol = dataSymbols[1][std::rand() % (dataSymbols[1].size())];
					loginUser += symbol;
					++indexSymbol;
				}
				continue;
			case 2:
				if (count_sE_symbol) {
					char symbol = dataSymbols[2][std::rand() % dataSymbols[2].size()];
					loginUser += symbol;
					++indexSymbol;
				}
				continue;
			case 3:
				if (count_bE_symbol) {
					char symbol = dataSymbols[3][std::rand() % dataSymbols[3].size()];
					loginUser += symbol;
					++indexSymbol;
				}
				continue;
			}
		}
		fout << loginUser << "\n";
		++countUser;
	}

	fout.close();
}

void randomCorectLogin(const std::vector<std::string>& dataSymbols) {
	std::srand(std::time(nullptr));
	std::ofstream fout("randomCorectUserLogin.txt");
	int countUser = 0;
	while (countUser < CONST_COUNT_RANDOM) {
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
					char symbol = dataSymbols[5][std::rand() % (dataSymbols[5].size())];
					loginUser += symbol;
					++indexSymbol;
				}
				continue;
			case 1:
				if (count_sE_symbol) {
					char symbol = dataSymbols[2][std::rand() % dataSymbols[2].size()];
					loginUser += symbol;
					++indexSymbol;
				}
				continue;
			case 2:
				if (count_bE_symbol) {
					char symbol = dataSymbols[3][std::rand() % dataSymbols[3].size()];
					loginUser += symbol;
					++indexSymbol;
				}
				continue;
			}
		}
		fout << loginUser << "\n";
		++countUser;
	}
	fout.close();
}

void randomUncorectPassword(const std::vector<std::string>& dataSymbols) {
	std::srand(std::time(nullptr));
	std::setlocale(LC_ALL, "Ru");
	std::ofstream fout("randomUncorectPassword.txt");

	int countPassword = 0;
	while (countPassword < CONST_COUNT_RANDOM) {
		std::string passwordUser;
		int lenghtPassword = std::rand() % (CONST_MAX_LENGHT_PASSWORD + 1);
		while (lenghtPassword < 5) {
			lenghtPassword = std::rand() % (CONST_MAX_LENGHT_PASSWORD + 1);
		}

		int countAlpha = std::rand() % lenghtPassword;
		int count_E_alpha = std::rand() % (countAlpha + 1);
		int count_bE_alpha = 0;
		int count_sE_alpha = 0;
		if (count_E_alpha) {
			count_bE_alpha = std::rand() % (count_E_alpha + 1);
			count_sE_alpha = count_E_alpha - count_bE_alpha;
		}

		int count_R_alpha = countAlpha - count_E_alpha;
		int count_bR_alpha = 0;
		int count_sR_alpha = 0;
		if (count_R_alpha) {
			count_bR_alpha = std::rand() % (count_R_alpha + 1);
			count_sR_alpha = count_R_alpha - count_bR_alpha;
		}
		int countSymbol = lenghtPassword - countAlpha;
		int countNumber = lenghtPassword - countAlpha - countSymbol;

		int indexPassword = 0;
		while (indexPassword <= lenghtPassword) {
			int numberOperation = std::rand() % 6;
			switch (numberOperation) {
			case 0:
				if (count_bR_alpha) {
					char symbol = dataSymbols[0][std::rand() % (dataSymbols[0].size())];
					passwordUser += symbol;
					++indexPassword;
				}
				continue;
			case 1:
				if (count_sR_alpha) {
					char symbol = dataSymbols[1][std::rand() % (dataSymbols[1].size())];
					passwordUser += symbol;
					++indexPassword;
				}
				continue;
			case 2:
				if (count_bE_alpha) {
					char symbol = dataSymbols[2][std::rand() % (dataSymbols[2].size())];
					passwordUser += symbol;
					++indexPassword;
				}
				continue;
			case 3:
				if (count_sE_alpha) {
					char symbol = dataSymbols[3][std::rand() % (dataSymbols[3].size())];
					passwordUser += symbol;
					++indexPassword;
				}
				continue;
			case 4:
				if (countNumber) {
					char symbol = dataSymbols[4][std::rand() % (dataSymbols[4].size())];
					passwordUser += symbol;
					++indexPassword;
				}
				continue;
			case 5:
				if (countSymbol) {
					char symbol = dataSymbols[5][std::rand() % (dataSymbols[5].size())];
					passwordUser += symbol;
					++indexPassword;
				}
				continue;
			}
		}
		fout << passwordUser << "\n";
		++countPassword;
	}
	fout.close();
}

void randomCorectPassword(const std::vector<std::string>& dataSymbols) {
	std::srand(std::time(nullptr));
	std::setlocale(LC_ALL, "Ru");
	std::ofstream fout("randomCorectPassword.txt");

	int countPassword = 0;
	while (countPassword <= CONST_COUNT_RANDOM) {
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
		while (indexPassword < lenghtPassword) {
			int numberOperation = std::rand() % 4;
			switch (numberOperation) {
			case 0:
				if (count_bE_alpha) {
					char symbol = dataSymbols[2][std::rand() % (dataSymbols[2].size())];
					passwordUser += symbol;
					++indexPassword;
				}
				continue;
			case 1:
				if (count_sE_alpha) {
					char symbol = dataSymbols[3][std::rand() % (dataSymbols[3].size())];
					passwordUser += symbol;
					++indexPassword;
				}
				continue;
			case 2:
				if (countNumber) {
					char symbol = dataSymbols[4][std::rand() % (dataSymbols[4].size())];
					passwordUser += symbol;
					++indexPassword;
				}
				continue;
			case 3:
				if (countSymbol) {
					char symbol = dataSymbols[5][std::rand() % (dataSymbols[5].size())];
					passwordUser += symbol;
					++indexPassword;
				}
				continue;
			}
		}
		fout << passwordUser << "\n";
		++countPassword;
	}
	fout.close();
}

int main() {
	std::srand(std::time(nullptr));
	std::ifstream fin("dataSymbols.txt");
	if (fin) {
		std::vector<std::string> dataSymbols;
		while (fin) {
			std::string data;
			fin >> data;
			dataSymbols.push_back(data);
		}
		fin.close();
		randomUncorectLogin(dataSymbols);
		randomCorectLogin(dataSymbols);
		randomUncorectPassword(dataSymbols);
		randomCorectPassword(dataSymbols);
	}
	return 0;
}

#undef CONST_COUNT_RANDOM 100
#undef CONST_COUNT_R_RANDOM 100
#undef CONST_MAX_LENGHT_LOGIN 20
#undef CONST_MAX_LENGHT_PASSWORD 25
