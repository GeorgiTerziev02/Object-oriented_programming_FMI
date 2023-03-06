#include <iostream>
#include <fstream>
using namespace std;
const int MAX_SYMBOLS = 128;
const int MAX_USERS = 100;
const char LOGIN[6] = "login";
const char REGISTER[9] = "register";
const char EXIT[5] = "exit";
struct User {
	char name[MAX_SYMBOLS];
	char email[MAX_SYMBOLS];
	char password[MAX_SYMBOLS];
};
struct System {
	User systemOfUser[MAX_USERS];
};
void writeUserToFile(ofstream& out, User& user) {
	if (!out.is_open()) {
		return;
	}
	out << user.name << endl << user.email << endl << user.password << endl;
}
void readUserFromFile(ifstream& in, User& user) {
	if (!in.is_open()) {
		return;
	}
	int iteratorOne = 0, iteratorTwo = 0, iteratorThree = 0;
	char bufferName[MAX_SYMBOLS], bufferEmail[MAX_SYMBOLS], bufferPassword[MAX_SYMBOLS];
	in.getline(bufferName, MAX_SYMBOLS);
	in.getline(bufferEmail, MAX_SYMBOLS);
	in.getline(bufferPassword, MAX_SYMBOLS);

	while (bufferName[iteratorOne] != '\0') {
		user.name[iteratorOne] = bufferName[iteratorOne];
		iteratorOne++;
	}
	while (bufferEmail[iteratorTwo] != '\0') {
		user.email[iteratorTwo] = bufferEmail[iteratorTwo];
		iteratorTwo++;
	}
	while (bufferPassword[iteratorThree] != '\0') {
		user.password[iteratorThree] = bufferPassword[iteratorThree];
		iteratorThree++;
	}
}
void writeSystemToFile(ofstream& out, System& users, int& numOfUsers) {
	if (!out.is_open()) {
		return;
	}
	for (int i = 0; i < numOfUsers; i++) {
		writeUserToFile(out, users.systemOfUser[i]);
	}
}
void readSystemFromFile(ifstream& in, System(&users)[MAX_USERS], int& numOfUsers) {
	if (!in.is_open()) {
		return;
	}
	numOfUsers = 0;
	while (!in.eof()) {
		readUserFromFile(in, users->systemOfUser[numOfUsers]);
	}
}
bool checkForLogin(ifstream& in, char* email, char* password) {
	bool flagForEmail = false, flagForPassword = false;
	if (!in.is_open()) {
		return 0;
	}
	while (!in.eof()) {
		char buffer[MAX_SYMBOLS];
		in.getline(buffer, MAX_SYMBOLS);
		if (strcmp(buffer, email) == 0) {
			flagForEmail = true;
		}
		else if (strcmp(buffer, password) == 0) {
			flagForPassword = true;
		}
	}
	if (flagForEmail && flagForPassword) {
		return true;
	}
	return false;
}
int main()
{
	char command[MAX_SYMBOLS];
	System users;
	ofstream out;
	out.open("system.txt");
	int numOfUsers = 0;
	while (true) {
		cout << "Enter command: " << endl;
		cin.getline(command, MAX_SYMBOLS);
		if (strcmp(command, EXIT)==0) {
			break;
		}
		else if (strcmp(command, REGISTER) == 0) {
			int i = 0;
			char name[MAX_SYMBOLS] = { 0 }, email[MAX_SYMBOLS] = { 0 }, password[MAX_SYMBOLS] = { 0 };
			cout << "Enter name: " << endl;
			cin.getline(name, MAX_SYMBOLS);
			cout << "Enter email: " << endl;
			cin.getline(email, MAX_SYMBOLS);
			cout << "Enter password: " << endl;
			cin.getline(password, MAX_SYMBOLS);
			while (name[i] != '\0') {
				users.systemOfUser[numOfUsers].name[i] = name[i];
				i++;
				if (name[i] == '\0') {
					users.systemOfUser[numOfUsers].name[i] = '\0';
				}
			}
			i = 0;
			while (email[i] != '\0') {
				users.systemOfUser[numOfUsers].email[i] = email[i];
				i++;
				if (email[i] == '\0') {
					users.systemOfUser[numOfUsers].email[i] = '\0';
				}
			}
			i = 0;
			while (password[i] != '\0') {
				users.systemOfUser[numOfUsers].password[i] = password[i];
				i++;
				if (password[i] == '\0') {
					users.systemOfUser[numOfUsers].password[i] = '\0';
				}
			}
			numOfUsers++;
			cout << "Registration successful." << endl;
		}
		else if (strcmp(command, LOGIN) == 0) {
			int i = 0;
			char email[MAX_SYMBOLS], password[MAX_SYMBOLS];
			cout << "Enter email: " << endl;
			cin.getline(email, MAX_SYMBOLS);
			cout << "Enter password: " << endl;
			cin.getline(password, MAX_SYMBOLS);
			ifstream in;
			in.open("system.txt");
			if (checkForLogin(in, email, password)) {
				cout << "Login successful." << endl;
			}
			else {
				cout << "Login unsuccessful." << endl;
			}
			in.close();
		}
	}
	writeSystemToFile(out, users, numOfUsers);
	out.close();
}
