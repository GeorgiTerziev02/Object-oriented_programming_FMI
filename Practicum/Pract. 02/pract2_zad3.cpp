#include <iostream>
#include <fstream>
#include <cstring>

const unsigned MAX_STRING_LENGHT = 128;
const unsigned MAX_USER_COUNT = 100;

enum class MultifactorAuthentication
{
	none = 0,
	fingerprint = 1 << 0,
	facialRecognition = 1 << 1,
	smartphoneSMS = 1 << 2
};

struct User
{
	char name[MAX_STRING_LENGHT];
	char email[MAX_STRING_LENGHT];
	char password[MAX_STRING_LENGHT];
	MultifactorAuthentication authentication;
};

struct System
{
	int userSize;
	User userArr[MAX_USER_COUNT];
};

void writeUserInFile(const User& user, std::ofstream& out)
{
	out << user.name << " ";
	out << user.email << " ";
	out << user.password << " ";
	out << (int)user.authentication << "\n";
}

void readUserFromFile(User& user, std::ifstream& in)
{
	in >> user.name;
	in >> user.email;
	in >> user.password;
	std::cout << user.name << " " << user.email << " " << user.password << " ";
	int num;
	in >> num;
	switch (num)
	{
	case 0:
		user.authentication = MultifactorAuthentication::none;
		break;
	case 1:
		user.authentication = MultifactorAuthentication::fingerprint;
		break;
	case 2:
		user.authentication = MultifactorAuthentication::facialRecognition;
		break;
	case 4:
		user.authentication = MultifactorAuthentication::smartphoneSMS;
		break;
	case 3:
		user.authentication = static_cast<MultifactorAuthentication>((int)MultifactorAuthentication::fingerprint | (int)MultifactorAuthentication::facialRecognition);
		break;
	case 6:
		user.authentication = static_cast<MultifactorAuthentication>((int)MultifactorAuthentication::facialRecognition | (int)MultifactorAuthentication::smartphoneSMS);
		break;
	case 7:
		user.authentication = static_cast<MultifactorAuthentication>((int)MultifactorAuthentication::fingerprint | (int)MultifactorAuthentication::facialRecognition | (int)MultifactorAuthentication::smartphoneSMS);
		break;
	}
}

void readUserFromKeyboard(User& user, std::istream& in)
{
	std::cout << "Enter name: ";
	in >> user.name;
	std::cout << "Enter email: ";
	in >> user.email;
	std::cout << "Enter password: ";
	in >> user.password;

	std::cout << "Enter authentication, must be a number - {0,1,2,3,4,6,7}: ";
	int num;
	in >> num;
	switch (num)
	{
	case 0:
		user.authentication = MultifactorAuthentication::none;
		break;
	case 1:
		user.authentication = MultifactorAuthentication::fingerprint;
		break;
	case 2:
		user.authentication = MultifactorAuthentication::facialRecognition;
		break;
	case 4:
		user.authentication = MultifactorAuthentication::smartphoneSMS;
		break;
	case 3:
		user.authentication = static_cast<MultifactorAuthentication>((int)MultifactorAuthentication::fingerprint | (int)MultifactorAuthentication::facialRecognition);
		break;
	case 6:
		user.authentication = static_cast<MultifactorAuthentication>((int)MultifactorAuthentication::facialRecognition | (int)MultifactorAuthentication::smartphoneSMS);
		break;
	case 7:
		user.authentication = static_cast<MultifactorAuthentication>((int)MultifactorAuthentication::fingerprint | (int)MultifactorAuthentication::facialRecognition | (int)MultifactorAuthentication::smartphoneSMS);
		break;
	}
}

void writeSysToFile(const System& sys, std::ofstream& out)
{
	out << sys.userSize << "\n";
	for (size_t i = 0; i < sys.userSize; i++)
	{
		writeUserInFile(sys.userArr[i], out);
	}
}

void readSysFromFile(System& sys, std::ifstream& in)
{
	in >> sys.userSize;
	for (size_t i = 0; i < sys.userSize; i++)
	{
		readUserFromFile(sys.userArr[i], in);
	}
}

bool loginUser(System& sys)
{
	char command[30];
	std::cout << "Enter email:\n>";
	std::cin >> command;

	User loginUser;
	bool found = false;

	for (size_t i = 0; i < sys.userSize; i++)
	{
		if (strcmp(sys.userArr[i].email, command) == 0)
		{
			loginUser = sys.userArr[i];
			found = true;
			break;
		}
	}

	if (!found)
	{
		std::cout << "User not found\n";
		return false;
	}

	while (true)
	{
		std::cout << "Enter password:\n>";
		std::cin >> command;

		if (strcmp(loginUser.password, command) == 0)
		{
			std::cout << "Login successful\n";
			return true;
		}
		else
		{
			std::cout << "Wrong password, try again, or write {end} to escape\n>";
			std::cin >> command;

			if (strcmp(command, "end") == 0)
				break;
		}
	}
	return false;
}

int main()
{
	System sys;
	std::ifstream in("system.txt", std::ios::in);
	if (!in)
	{
		std::cout << "problem with opening the file";
		return -1;
	}

	readSysFromFile(sys, in);
	in.close();

	while (true)
	{
		std::cout << "Enter command:\n>";
		char command[30];
		std::cin >> command;

		if (strcmp(command, "register") == 0)
		{
			User user;
			readUserFromKeyboard(user, std::cin);

			sys.userArr[sys.userSize] = user;
			++sys.userSize;

			std::ofstream out("system.txt", std::ios::out | std::ios::trunc);
			if (!out)
			{
				std::cout << "problem with opening the file";
				return -1;
			}

			writeSysToFile(sys, out);
			std::cout << "Registration successful\n";
			out.close();
		}
		else if (strcmp(command, "login") == 0)
		{
			loginUser(sys);
		}
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else
		{
			std::cout << "Invalid command. Try again.\n";
		}
	}

	return 0;
}

//System sys;
//sys.userSize = 3;
//sys.userArr[0] = { "IvanIvanov","ivankata@gmail","123", MultifactorAuthentication::facialRecognition };
//sys.userArr[1] = { "PetarPetrov","peshkata@gmail","456", MultifactorAuthentication::fingerprint };
//sys.userArr[2] = { "MartinMartinov","martata@gmail","789", MultifactorAuthentication::smartphoneSMS };
