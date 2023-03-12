#include <iostream>
#include <fstream>

const char* ALL_OFFERS_BINARY_FILE_PATH = "all_offers.bin";
const char* PERFECT_OFFERS_BINARY_FILE_PATH = "perfect_offers.bin";
const size_t MAX_COMPANY_NAME_LENGTH = 26;

struct JobOffer
{
	char companyName[MAX_COMPANY_NAME_LENGTH];
	int coworkers;
	int numberOfVacancyDays;
	long long salary;
};

size_t strLength(const char* str)
{
	size_t length = 0;

	while (*str != 0)
	{
		str++;
		length++;
	}

	return length;
}

int strCompare(const char* str1, const char* str2)
{
	size_t str1Len = strLength(str1);
	size_t str2Len = strLength(str2);

	size_t lenToUse = str1Len >= str2Len ? str1Len : str2Len;

	for (size_t i = 0; i < lenToUse; i++)
	{
		if (str1[i] > str2[i])
			return -1;

		if (str1[i] < str2[i])
			return 1;
	}

	return 0;
}

size_t getFileSize(std::ifstream& in)
{
	size_t currentPos = in.tellg();
	in.seekg(0, std::ios::end);
	size_t fileSize = in.tellg();
	in.seekg(currentPos);
	return fileSize;
}


void strCopy(char* direction, const char* toCopy)
{
	size_t toCopyLen = strLength(toCopy);

	for (size_t i = 0; i < toCopyLen; i++)
		direction[i] = toCopy[i];

	direction[toCopyLen] = '\0';
}

void saveJobOffer(std::ofstream& out, const JobOffer& offer)
{
	out.write((const char*)&offer, sizeof(JobOffer));
}

JobOffer readJobOfferFromFile(std::ifstream& in)
{
	JobOffer offer;
	in.read((char*)&offer, sizeof(JobOffer));
	return offer;
}

bool existOffer(const char* filePath, const char* companyName)
{
	std::ifstream in(filePath, std::ios::binary);

	if (!in.is_open())
	{
		std::cerr << "Couldn't find file!";
		return false;
	}

	while (!in.eof())
	{
		JobOffer offer = readJobOfferFromFile(in);

		if (strCompare(offer.companyName, companyName) == 0)
			return true;
	}

	in.close();
	return false;
}

void saveJobOffers(const JobOffer* offers, const size_t numberOfOffers)
{
	std::ofstream out(ALL_OFFERS_BINARY_FILE_PATH, std::ios::app | std::ios::binary);

	if (!out.is_open())
	{
		std::cerr << "File couldn't open";
		return;
	}

	for (size_t i = 0; i < numberOfOffers; i++)
		saveJobOffer(out, offers[i]);

	out.close();
}

JobOffer createJobOffer(const char* companyName, const int coworkers, const int numberOfVacancyDays, const long long salary)
{
	JobOffer offer;
	strCopy(offer.companyName, companyName);
	offer.coworkers = coworkers;
	offer.numberOfVacancyDays = numberOfVacancyDays;
	offer.salary = salary;
	return offer;
}

void readJobOfferFromConsole(JobOffer& offer)
{
	char companyName[MAX_COMPANY_NAME_LENGTH];
	long long salary;
	int numberOfVacancyDays;
	int coworkers;

	std::cout << "Enter company name: ";
	std::cin >> companyName;

	if (existOffer(ALL_OFFERS_BINARY_FILE_PATH, companyName))
	{
		std::cout << "The company already exists!" << std::endl;
		readJobOfferFromConsole(offer);
	}
	else
	{
		std::cout << "Enter Number of coworkers: ";
		std::cin >> coworkers;
		std::cout << "Enter number of days of paid leave: ";
		std::cin >> numberOfVacancyDays;
		std::cout << "Enter salary: ";
		std::cin >> salary;

		offer = createJobOffer(companyName, coworkers, numberOfVacancyDays, salary);
	}
}

void printJobOffer(JobOffer& offer)
{
	std::cout << "Company Name: " << offer.companyName
		<< "  Number of coworkers: " << offer.coworkers
		<< "  Number of vacancy days: " << offer.numberOfVacancyDays
		<< "  Salary: " << offer.salary
		<< std::endl;
}

void filterBySalaryOffers(const char* filePath, const long long minSalary)
{
	std::ifstream in(filePath, std::ios::binary);

	if (!in.is_open())
	{
		std::cerr << "Couldn't find file!";
		return;
	}

	while (!in.eof())
	{
		JobOffer offer = readJobOfferFromFile(in);

		if (offer.salary >= minSalary)
			printJobOffer(offer);
	}

	in.close();
}

void readNJobOffersFromConsole()
{
	size_t numberOfOffers;
	std::cout << "Enter number of job offers: ";
	std::cin >> numberOfOffers;

	JobOffer* offers = new JobOffer[numberOfOffers];

	for (size_t i = 0; i < numberOfOffers; i++)
		readJobOfferFromConsole(offers[i]);

	saveJobOffers(offers, numberOfOffers);

	delete[] offers;
}

bool isPerfectOffer(const JobOffer& offer, const int maxCoworkers, const int minVacancyDays, const long long minSalary)
{
	return offer.coworkers <= maxCoworkers && offer.numberOfVacancyDays >= minVacancyDays && offer.salary >= minSalary;
}

void perfectOffer(const char* filePath, const int maxCoworkers, const int minVacancyDays, const long long minSalary)
{
	std::ifstream in(ALL_OFFERS_BINARY_FILE_PATH, std::ios::binary);
	std::ofstream out(PERFECT_OFFERS_BINARY_FILE_PATH, std::ios::app, std::ios::binary);

	if (!in.is_open())
	{
		std::cerr << "Couldn't find file to read from!";
		return;
	}

	if (!out.is_open())
	{
		std::cerr << "Couldn't find file to write into!";
		return;
	}

	while (!in.eof())
	{
		JobOffer offer = readJobOfferFromFile(in);

		if (isPerfectOffer(offer, maxCoworkers, minVacancyDays, minSalary) && !existOffer(PERFECT_OFFERS_BINARY_FILE_PATH, offer.companyName))
			saveJobOffer(out, offer);
	}

	in.close();
	out.close();
}

void printAllJobOffersFromFile(const char* filePath)
{
	std::ifstream in(filePath, std::ios::binary);

	if (!in.is_open())
	{
		std::cerr << "Couldn't find fie!";
		return;
	}

	size_t fileSize = getFileSize(in);
	size_t numberOfOffers = fileSize / sizeof(JobOffer);
	JobOffer* offers = new JobOffer[numberOfOffers];

	in.read((char*)offers, fileSize);

	for (size_t i = 0; i < numberOfOffers; i++)
		printJobOffer(offers[i]);

	in.close();
}

void addJobOffer()
{
	std::ofstream out(ALL_OFFERS_BINARY_FILE_PATH, std::ios::app | std::ios::binary);

	if (!out.is_open())
	{
		std::cerr << "Couldn't find file to add to!";
		return;
	}

	JobOffer offer;
	readJobOfferFromConsole(offer);
	saveJobOffer(out, offer);

	out.close();
}

void checkIfCompanyExists()
{
	char companyName[26];

	std::cout << "Enter company name: ";
	std::cin >> companyName;
	std::cout << existOffer(ALL_OFFERS_BINARY_FILE_PATH, companyName) << std::endl;
}

void runApp()
{
	bool endApp = false;
	while (!endApp)
	{
		std::cout << "Enter 'a' to add offer;" << std::endl
			<< "Enter 'i' to print all offers;" << std::endl
			<< "Enter 's' to check if job offer exists;" << std::endl
			<< "Enter 'f' to print all offers with salary above certain number;" << std::endl
			<< "Enter 'q' to exit." << std::endl
			<< "Enter a key: ";

		char key;
		std::cin >> key;
		switch (key)
		{
		case 'a':
			std::cout << "Add offer" << std::endl;
			addJobOffer();
			break;
		case 'i':
			std::cout << "Print:" << std::endl;
			printAllJobOffersFromFile(ALL_OFFERS_BINARY_FILE_PATH);
			break;
		case 's':
			std::cout << "Check if company exists" << std::endl;
			checkIfCompanyExists();
			break;
		case 'f':
			long long minSalary;
			std::cout << "Print all offers with salary more than: ";
			std::cin >> minSalary;
			filterBySalaryOffers(ALL_OFFERS_BINARY_FILE_PATH, minSalary);
			break;
		case 'q':
			endApp = true;
			break;
		}
	}
}

int main()
{
	runApp();
	return 0;
}