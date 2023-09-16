#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>

#include "user.h"
#include "Error.h"

std::vector <std::string> names = {
	"Oliver",
	"Jack",
	"Harry",
	"Jacob",
	"Charley",
	"Thomas",
	"George",
	"Oscar"
};
int sizeNames = names.size();

std::vector <std::string> secondnames = {
	"Smith",
	"Jones",
	"Taylor", 
	"Williams",
	"Brown", 
	"Davies",
	"Evans", 
	"Wilson"
};
int sizeSnames = secondnames.size();

std::vector <std::string> surnme = {
	"Yuryevich",
	"Aleksandrovich",
	"Anatolyevich",
	"Anatolyevna",
	"Vyacheslavovna",
	"Vyacheslavovich",
	"Evgenyevna",
	"Edouardovich",
	"Victorovich",
	"Mikhaylovich"
};
int sizeSurnam = surnme.size();

std::vector <std::string> numberssPhone = {
	"987645321",
	"+792413131123",
	"81999527935",
	"987564231",
	"81992572935",
	"+792413131125",
	"987645321",
	"81999570935",
	"+792466631123",
	"987645132"
};
int sizeNumber = numberssPhone.size();

std::vector<short int> ages = {
	12,
	35,
	50,
	40, 
	67, 
	13,
	14,
	21,
	22,
	90
};
int sizeAges = ages.size();

std::vector <std::string> loggins = {
	"ILdjP",
	"WOHxOMqEGPQ",
	"yAqMEC",
	"g}EZqn",
	"sfx",
	"OoumWLMhiqI",
	"famTwX",
	"famTwX",
	"cqfrgLKM",
	"pcnlnmiv"
};
int sizeLoggins = loggins.size();

std::vector <std::string> passwords = {
	"e)=tH1DsONbx+|c}`OVP?",
	"#ZG#MP2U%NKWPVG:#BL?NJ)",
	"W>_d|&L3zc]*Nku",
	"boGfDs<4XgqruovpY",
	"LIR(--FZ6&Q.",
	"QN:TO)PS5?uYXQ;",
	"Ruxy.qU!3",
	"PjQK%l2pIy",
	"TT$)P@S1(_",
	"IPI(W$:_@BK100H;NY",
	"C>JPalw11j"
};
int sizePasswords = passwords.size();

int getRandomindex(int size) {
	return std::rand() % size;
}

void tableData(); 

int main() {
	std::srand(std::time(nullptr));
	std::ofstream fout("dataUser.txt");
	int i = 0; 
	while (i < 100) {
		std::string nam = names[getRandomindex(sizeNames)];
		std::string snem = secondnames[getRandomindex(sizeSnames)];
		std::string surn = surnme[getRandomindex(sizeSurnam)];
		std::string np = numberssPhone[getRandomindex(sizeNumber)];
		short int a = ages[getRandomindex(sizeAges)];
		std::string l = loggins[getRandomindex(sizeLoggins)];
		std::string p = passwords[getRandomindex(sizePasswords)];

		fout << "User #" << i+1 << "\n";
		try {
			User b{ l, p, nam, snem, surn, np, a };
			fout << b.getAllData();
			fout << "\n";
		}
		catch (const ErrorLoggin& c) {
			fout << "Eerror login:\n";
			fout << c.what() << "\n";
			fout << l << "\n";
		}
		catch (const ErrorPassword& c) {
			fout << "Error password:\n";
			fout << c.what() << "\n" << p << "\n";
		}
		catch (const ErrorAge& c) {
			fout << "Error age:\n";
			fout << c.what() << "\n" << a;
		}
		catch (const ErrorNumber& c) {
			fout << "Error number phone:\n";
			fout << c.what() << "\n" << np << "\n";
		}
		++i;
		fout << "\n\n";
	}
	return 0;
}

void tableData() {
		int maxsize = 50;
		std::ofstream fout("dataForUser.txt");

		for (int i = 0; i < (maxsize - 4) / 2; ++i)
			fout << "-";
		fout << "Name";
		for (int i = 0; i < (maxsize - 4) / 2; ++i)
			fout << "-";
		fout << "\n";
		for (int i = 0; i < names.size() / 2; ++i) {
			fout << "|" << names[i];
			for (int j = 0; j < (maxsize - names[i].size() - names[i + 1].size() - 2); ++j)
				fout << " ";
			fout << names[i + 1] << "|\n";
		}
		fout << "|";
		for (int i = 0; i < (maxsize - 11) / 2; ++i)
			fout << "-";
		fout << "Secondname";
		for (int i = 0; i < (maxsize - 11) / 2; ++i)
			fout << "-";
		fout << "|\n";
		for (int i = 0; i < secondnames.size() / 2; ++i) {
			fout << "|" << secondnames[i];
			for (int j = 0; j < (maxsize - secondnames[i].size() - secondnames[i + 1].size() - 2); ++j)
				fout << " ";
			fout << secondnames[i + 1] << "|\n";
		}

		fout << "|";
		for (int i = 0; i < (maxsize - 9) / 2; ++i)
			fout << "-";
		fout << "Surnames";
		for (int i = 0; i < (maxsize - 9) / 2; ++i)
			fout << "-";
		fout << "|\n";
		for (int i = 0; i < surnme.size() / 2; ++i) {
			fout << "|" << surnme[i];
			for (int j = 0; j < (maxsize - surnme[i].size() - surnme[i + 1].size() - 2); ++j)
				fout << " ";
			fout << surnme[i + 1] << "|\n";
		}

		fout << "|";
		for (int i = 0; i < (maxsize - 15) / 2; ++i)
			fout << "-";
		fout << "Numbers phones";
		for (int i = 0; i < (maxsize - 15) / 2; ++i)
			fout << "-";
		fout << "|\n";
		for (int i = 0; i < numberssPhone.size() / 2; ++i) {
			fout << "|" << numberssPhone[i];
			for (int j = 0; j < (maxsize - numberssPhone[i].size() - numberssPhone[i + 1].size() - 2); ++j)
				fout << " ";
			fout << numberssPhone[i + 1] << "|\n";
		}

		fout << "|";
		for (int i = 0; i < (maxsize - 5) / 2; ++i)
			fout << "-";
		fout << "Ages";
		for (int i = 0; i < (maxsize - 5) / 2; ++i)
			fout << "-";
		fout << "|\n";
		for (int i = 0; i < ages.size() / 2; ++i) {
			fout << "|" << ages[i];
			for (int j = 0; j < (maxsize - 6); ++j)
				fout << " ";
			fout << ages[i + 1] << "|\n";
		}
		fout << "|";
		for (int i = 0; i < (maxsize - 7) / 2; ++i)
			fout << "-";
		fout << "loggin";
		for (int i = 0; i < (maxsize - 7) / 2; ++i)
			fout << "-";
		fout << "|\n";
		for (int i = 0; i < loggins.size() / 2; ++i) {
			fout << "|" << loggins[i];
			for (int j = 0; j < (maxsize - loggins[i].size() - loggins[i + 1].size() - 2); ++j)
				fout << " ";
			fout << loggins[i + 1] << "|\n";
		}

		fout << "|";
		for (int i = 0; i < (maxsize - 9) / 2; ++i)
			fout << "-";
		fout << "password";
		for (int i = 0; i < (maxsize - 9) / 2; ++i)
			fout << "-";
		fout << "|\n";
		for (int i = 0; i < passwords.size() / 2; ++i) {
			fout << "|" << passwords[i];
			for (int j = 0; j < (maxsize - passwords[i].size() - passwords[i + 1].size() - 2); ++j)
				fout << " ";
			fout << passwords[i + 1] << "|\n";
		}
		for (int i = 0; i < maxsize; ++i)
			fout << "-";
		fout << "\n";

		fout.close();
}