#include<iostream>
#include<fstream>
#pragma warning (disable: 4996)
using namespace std;
const char fileName[] = "offers.bin";
const char a = 'a';
const char i = 'i';
const char s = 's';
const char f = 'f';
const char q = 'q';
struct Offer {
	char firmName[25];
	int coworkers;
	int offDays;
	long long payment;
};

size_t getFileSize(ifstream& f) {
	size_t currentPos = f.tellg();
	f.seekg(0, ios::end);
	size_t size = f.tellg();

	f.seekg(currentPos);
	return size+1;
}

void enterAttributes(char* firmName, int& coworkers, int& offDays, long long& payment) {
	cout << "What is the name of the firm:";
	cin >> firmName;
	cout<<"How many are the coworkers:";
	cin >> coworkers;
	cout << "How many are the days off:";
	cin >> offDays;
	cout << "How big is the payment";
	cin >> payment;
	cout << "-------------------------" << endl;
}

void createOffer(Offer& offer) {
	char firmName[25];
	int collegues,offDays;
	long long payment;
	enterAttributes(firmName, collegues, offDays, payment);
	
	strcpy(offer.firmName, firmName);
	offer.coworkers = collegues;
	offer.offDays = offDays;
	offer.payment = payment;
}

void writeOneItemTofile(ofstream& out, Offer* offer) {
	out.write((const char*)&offer->firmName, sizeof(offer->firmName));
	out.write((const char*)&offer->coworkers, sizeof(offer->coworkers));
	out.write((const char*)&offer->offDays, sizeof(offer->offDays));
	out.write((const char*)&offer->payment, sizeof(offer->payment));
}

void writeToFileOffers(ofstream& out, Offer* offers, int n) {
	for (int i = 0; i < n; i++) {
		writeOneItemTofile(out,&offers[i]);
	}
}

void readOneItemFromFile(ifstream& in, Offer* offer) {
	in.read((char*)&offer->firmName, sizeof(offer->firmName));
	in.read((char*)&offer->coworkers, sizeof(offer->coworkers));
	in.read((char*)&offer->offDays, sizeof(offer->offDays));
	in.read((char*)&offer->payment, sizeof(offer->payment));
}
void readFromFile(ifstream& in, Offer* offer, int num) {
	for (int i = 0; i < num; i++) {
		readOneItemFromFile(in, &offer[i]);
	}
}
void filterOffers(const char* filePath, long long& minSalary) {
	ifstream in(filePath, ios::binary);
	size_t numOffers = getFileSize(in) / sizeof(Offer);
	Offer* offers=new Offer[numOffers];
	for (size_t i = 0; i < numOffers; i++) {
		readOneItemFromFile(in, &offers[i]);
		if(offers[i].payment>minSalary){
			cout << offers[i].firmName << endl;
		}
	}	
	delete[] offers;
	in.close();
}

void printAllOfferFromFile(const char* filePath) {
	ifstream in(filePath, ios::binary);
	size_t numOffers = getFileSize(in) / sizeof(Offer);
	Offer* offers = new Offer[numOffers];
	for (size_t i = 0; i < numOffers; i++) {
		readOneItemFromFile(in, &offers[i]);
		cout << "Company name: " << offers[i].firmName << endl;
		cout << "Number of coworker: " << offers[i].coworkers << endl;
		cout << "Number of days off " << offers[i].offDays << endl;
		cout << "Salary: " << offers[i].payment << endl;
	}
	delete[] offers;
	in.close();
}

bool existOffer(const char* filePath, const char* name) {
	ifstream in(filePath, ios::binary);
	size_t numOffers = getFileSize(in) / sizeof(Offer)+1;
	Offer* offers = new Offer[numOffers];
	readFromFile(in, offers, numOffers);
	bool areThereOffers = false;
	for (size_t i = 0; i < numOffers; i++) {
		if (strcmp(offers[i].firmName, name) == 0) {
			cout << offers[i].firmName << " has sent job offer" << endl;
			areThereOffers = true;
		}
	}
	in.close();
	return areThereOffers;
}
void addingOffer(const char* filePath) {
	ofstream out(filePath, ios::app | ios::binary);
	size_t numOfoffers;
	cout << "Enter the numbers of offers you like to add:";
	cin >> numOfoffers;

	Offer* offers = new Offer[numOfoffers];

	for (size_t i = 0; i < numOfoffers; i++) {
		createOffer(offers[i]);
	}

	writeToFileOffers(out, offers, numOfoffers);
	delete[] offers;
}
void perfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary) {
	ifstream in(filePath, ios::binary);
	size_t numOffers = getFileSize(in) / sizeof(Offer);
	Offer* offers = new Offer[numOffers];
	for (size_t i = 0; i < numOffers; i++) {
		readOneItemFromFile(in, &offers[i]);
		if (offers[i].coworkers <maxCoworkers && offers[i].offDays>minVacancyDays && offers[i].payment>minSalary) {
			cout << offers[i].firmName << endl;
		}
	}
	delete[] offers;
	in.close();
}
int main() {
	char command;
	while (true) {
		cout << "Choose command:\n 1.a-Adds offer\n 2.i-shows all the offer in the file\n 3.s(company name) - shows if the company exist\n"<<
			" 4.f(number) - shows all the offer with higher payment than the number\n 5.q - Exit" << endl;
		cin >> command;
		if (command == a) {
			addingOffer(fileName);
		}
		else if (command == i) {
			printAllOfferFromFile(fileName);
		}
		else if (command == s) {
			char name[25];
			cout << "Which company would you like to check:";
			cin >> name;
			existOffer(fileName, name);
		}
		else if (command == f) {
			long long salary;
			cout << "What is the min salary Stoicho wants:";
			cin >> salary;
			filterOffers(fileName, salary);
		}
		else if (command == q) {
			break;
		}
	}
}
