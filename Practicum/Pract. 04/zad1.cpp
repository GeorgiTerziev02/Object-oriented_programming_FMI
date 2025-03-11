#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "Offers.bin";
constexpr char FILE_NAME_PERFECT[] = "PerfectOffers.bin";

const unsigned NAME_LENGHT = 26;

void clearCin()
{
	std::cin.clear();
	while (std::cin.get() !='\n')
	{

	}
}

struct WorkOffer
{
	char companyName[NAME_LENGHT];
	unsigned programersCount;
	unsigned vacationDaysCount;
	long long totalPay;

};
void ReadOfferFromConsole(WorkOffer& offer)
{
	clearCin();
	char buffer[NAME_LENGHT];
	do
	{
		
			if (!std::cin)
			{
				clearCin();
			}
			std::cout << "Enter company name,with 25 symbols max: ";
			std::cin.getline(buffer, NAME_LENGHT);
		
	} while (!std::cin);
	strcpy_s(offer.companyName, buffer);


	unsigned programmers = 0;
	do
	{

		if (!std::cin || programmers > 100)
		{
			clearCin();
		}
		std::cout << "Enter programmersCount between 0 and 100 : ";
		std::cin >> programmers;

	} while (!std::cin || programmers > 100);
	offer.programersCount = programmers;

	unsigned vacationDays = 0;
	do
	{

		if (!std::cin || vacationDays > 100)
		{
			clearCin();
		}
		std::cout << "Enter vacation days between 0 and 100 : ";
		std::cin >> vacationDays;

	} while (!std::cin || vacationDays > 100);
	offer.vacationDaysCount = vacationDays;

	unsigned totalPayVar = 0;
	do
	{

		if (!std::cin || totalPayVar > 100)
		{
			clearCin();
		}
		std::cout << "Enter totalPay  between 0 and 100: ";
		std::cin >> totalPayVar;

	} while (!std::cin || totalPayVar > 100);
	offer.totalPay = totalPayVar;

}

void printWorkOffer(const WorkOffer& offer)
{
	std::cout << "Company name: " << offer.companyName << "\n";
	std::cout << "Programes count: " << offer.programersCount << "\n";
	std::cout << "vacationDaysCount: " << offer.vacationDaysCount << "\n";
	std::cout << "totalPay: " << offer.totalPay << "\n";

}

void filterOffers(const char* filePath, long long minSalary)
{
	WorkOffer readWorkOffer;
	std::ifstream in(filePath,std::ios::binary | std::ios::in);

	if (!in)
	{
		std::cerr << "Error with opening for reading file " << filePath << "\n";
		return;
	}

	std::cout << "The ones who have salary above " << minSalary << "are\n";
	while (in.read(reinterpret_cast<char*>(&readWorkOffer),sizeof(readWorkOffer)))
	{
		if (readWorkOffer.totalPay >= minSalary)
		{
			printWorkOffer(readWorkOffer);
		}
	}
	if (in.fail() && !in.eof())
	{
		std::cerr << "Error reading the file with filterOffer" << filePath << "\n";
	}
	
}

bool existOffer(const char* filePath, const char* name)
{
	WorkOffer readWorkOffer;
	std::ifstream in(filePath, std::ios::binary | std::ios::in);

	if (!in)
	{
		std::cerr << "Error with opening for reading file " << filePath << "\n";
		return false;
	}

	while (in.read(reinterpret_cast<char*>(&readWorkOffer), sizeof(readWorkOffer)))
	{
		if (strcmp(readWorkOffer.companyName, name) == 0)
		{
			return true;
		}
	}

	if (in.fail() && !in.eof())
	{
		std::cerr << "Error reading the file with existOffer " << filePath << "\n";
	}

	return false; 
}


unsigned perfectOffer(const char* filePath, int maxCoworkers,
				  int minVacancyDays, int minSalary)
{
	unsigned count = 0;
	WorkOffer readWorkOffer;
	std::ifstream in(filePath, std::ios::binary | std::ios::in);
	if (!in)
	{
		std::cerr << "Error with opening for reading file " << filePath << "\n";
		return 0;
	}

	while (in.read(reinterpret_cast<char*>(&readWorkOffer), sizeof(readWorkOffer)))
	{
		if (readWorkOffer.programersCount <= maxCoworkers && 
			readWorkOffer.vacationDaysCount >=minVacancyDays &&
			readWorkOffer.totalPay >= minSalary)
		{
			std::ofstream out(FILE_NAME_PERFECT, std::ios::binary | std::ios::app);
			out.write(reinterpret_cast<const char*>(&readWorkOffer),
			sizeof(readWorkOffer));
			count++;
		}
	}
	if (in.fail() && !in.eof())
	{
		std::cerr << "Error reading the file with perfectOffer " << filePath << "\n";
		return 0;
	}
	return count;
		
}

void writeOffersToFile(const WorkOffer * offers,std::ofstream& out,unsigned count)
{
	for (size_t i = 0; i < count; i++)
	{
		out.write(reinterpret_cast<const char*>(&offers[i]), sizeof(offers[i]));
	}

}

void readOffer(WorkOffer* offer, std::ifstream& in,unsigned n)
{
	for (size_t i = 0; i < n; i++)
	{
		in.read(reinterpret_cast<char*>(&offer[i]), sizeof(offer[i]));	
	}
	if (in.fail() && !in.eof())
	{
		std::cerr << "Problem reading with readOffer\n";	
		return;
	}

}
int main()
{
	unsigned n;
	std::cout << "Enter number of offers: ";
	std::cin >> n;
	WorkOffer* offers = new WorkOffer[n];


	for (size_t i = 0; i < n; i++)
	{
		ReadOfferFromConsole(offers[i]);
	}

	std::ofstream out(FILE_NAME,std::ios::binary | std::ios::app);


	if (!out)
	{
		std::cerr << "Problem with opening file " << FILE_NAME << "\n";
		return -1;
	}

	writeOffersToFile(offers,out,n);
	out.close();

	std::cout << "-------------------------------------------------filterOffer\n";
	filterOffers(FILE_NAME,10);
	std::cout << "-------------------------------------------------existOffer\n";
	if (existOffer(FILE_NAME, "Metro"))
	{
		std::cout << "There exist offer from Metro\n";
	}

	std::cout << "-------------------------------------------------perfectOffer\n";
	unsigned perfectOfferCount = 0;
	perfectOfferCount = perfectOffer(FILE_NAME, 5, 5, 5);
	WorkOffer* perfectOffer = new WorkOffer[n];

	std::ifstream in(FILE_NAME_PERFECT, std::ios::binary | std::ios::in);
	if (!in)
	{
		std::cerr << "Problem with opening file " << FILE_NAME_PERFECT << "\n";
		return -1;
	}
	readOffer(perfectOffer, in,perfectOfferCount);
	in.close();

	for (size_t i = 0; i < perfectOfferCount; i++)
	{
		printWorkOffer(perfectOffer[i]);
	}

	
	
	delete[] offers;
	delete[] perfectOffer;
	
	



}