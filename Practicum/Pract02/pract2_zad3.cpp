#include <iostream>
#include <fstream>
#include <cstring>

enum class  MultifactorAuthentication
{
	fingerprint = 0,
	facialRecognition = 1,
	smartphoneSMS = 2

};
struct User
{
	char name[128];
	char email[128];
	char password[128];
	MultifactorAuthentication authentication;


};

struct System
{
	int userSize;
	User userArr[100];

};

void writeUserInFile(const User& Pesho, std::ofstream& out)
{
	out << Pesho.name << " ";
	out << Pesho.email << " ";
	out << Pesho.password << " ";
	out << (int)Pesho.authentication << "\n";

}

void readUserFromFile(User& Pesho, std::ifstream& in)
{
	in >> Pesho.name;
	in >> Pesho.email;
	in >> Pesho.password;
	std::cout << Pesho.name << " " << Pesho.email << " " << Pesho.password << " ";
	int num;
	in >> num;
	switch (num)
	{
	case 0:
		Pesho.authentication = MultifactorAuthentication::fingerprint;
		std::cout << "fingerprint";
		break;
	case 1:
		Pesho.authentication = MultifactorAuthentication::facialRecognition;
		std::cout << "facialRecognition";
		break;
	case 2:
		Pesho.authentication = MultifactorAuthentication::smartphoneSMS;
		std::cout << "smartphoneSMS";
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
	std::cout << sys.userSize << "\n";

	for (size_t i = 0; i < sys.userSize; i++)
	{
		readUserFromFile(sys.userArr[i], in);
		std::cout << "\n";
	}

	std::cout << "\n";
}





int main()
{
	System sys;
	sys.userSize = 3;
	sys.userArr[0] = { "IvanIvanov","ivankata@gmail","123", MultifactorAuthentication::facialRecognition };
	sys.userArr[1] = { "PetarPetrov","peshkata@gmail","456", MultifactorAuthentication::fingerprint };
	sys.userArr[2] = { "MartinMartinov","martata@gmail","789", MultifactorAuthentication::smartphoneSMS };

	std::ofstream out("system.txt", std::ios::out | std::ios::trunc);
	if (!out)
	{
		std::cout << "problem with opening the file";
		return -1;
	}

	writeSysToFile(sys, out);
	out.close();

	std::ifstream in("system.txt", std::ios::in);
	if (!in)
	{
		std::cout << "problem with opening the file";
		return -1;
	}

	System sys2;
	sys2.userSize = 3;

	readSysFromFile(sys2, in);
	in.close();



	while (true)
	{
		std::cout << "Enter command:\n>";
		char command[20];
		std::cin >> command;

		if (strcmp(command, "register") == 0)
		{
			User user;
			std::cout << "Enter name:\n>";
			std::cin >> command;
			strcpy_s(user.name, command);

			std::cout << "Enter password:\n>";
			std::cin >> command;
			strcpy_s(user.password, command);

			/* има ли някакъв начин ако човек трябва да въведе enum като string да го конвъртне
			* към enum чрез switch - нещо такова
			switch((int)command)

			case 0: .....
			бях объркал условието и тръгнах да го правя ...

			*/

			std::ofstream out("system.txt", std::ios::app);
			if (!out)
			{
				std::cout << "problem with opening the file";
				return -1;
			}

			writeUserInFile(user, out);
			out.seekp(0, std::ios::beg);

			out.put(++(sys2.userSize)); //увеличаваме бройката хора в системата 
			std::cout << "Registration successful\n";

			out.close();
		}




		else if (strcmp(command, "login") == 0)
		{
			std::cout << "Enter email:\n>";
			std::cin >> command;

			User LoginUser;
			bool found = false;

			for (size_t i = 0; i < sys2.userSize; i++)
			{
				if (strcmp(sys2.userArr[i].email, command) == 0)
				{
					LoginUser = sys2.userArr[i];
					found = true;
					break;
				}
			}

			if (!found)
			{
				std::cout << "User not found\n";
				continue;
			}

			while (true)
			{
				std::cout << "Enter password:\n>";
				std::cin >> command;

				if (strcmp(LoginUser.password, command) == 0)
				{
					std::cout << "Login successful\n";
					break;
				}
				else
				{
					std::cout << "Wrong password, try again, or write {end} to escape\n>";
					std::cin >> command;

					if (strcmp(command, "end") == 0)
						break;
				}
			}
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
