#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "PizzaDeliveries.bin";
const unsigned MAX_NAME = 50;
const unsigned MAX_TELEPHONE = 20;
const unsigned MAX_ADDRESS = 100;

enum class PizzaSize
{
	UNKNOWN = -1,
	SMALL,
	MEDIUM,
	LARGE,
	COUNT
};

enum class PizzaType
{
	UNKNOWN = -1,
	MARGARITA,
	KALTSONE,
	BIANKA,
	PROSHUTO,
	COUNT
};

struct Pizza
{
	PizzaType type;
	PizzaSize size;
	double price;
};

struct PizzaDelivery
{
	char clientName[MAX_NAME];
	char telephone[MAX_TELEPHONE];
	char address[MAX_ADDRESS];
	double totalSum;
	unsigned pizzaCount;
	Pizza pizzas[3];
};

void printPizza(const Pizza& pizza)
{
	std::cout << "Pizza type: ";
	switch (pizza.type)
	{
	case PizzaType::UNKNOWN: std::cout << "UKNOWN "; break;
	case PizzaType::MARGARITA: std::cout << "MARGARITA ";break;
	case PizzaType::KALTSONE: std::cout << "KALTSONE ";break;
	case PizzaType::BIANKA: std::cout << "BIANKA ";break;
	case PizzaType::PROSHUTO: std::cout << "PROSHUTO ";break;
	default: std::cout << "Bad name pizza.type\n";break;
	}

	std::cout << "Pizza size: ";
	switch (pizza.size)
	{
	case PizzaSize::UNKNOWN: std::cout << "UKNOWN ";break;
	case PizzaSize::SMALL: std::cout << "SMALL ";break;
	case PizzaSize::MEDIUM: std::cout << "MEDIUM ";break;
	case PizzaSize::LARGE: std::cout << "LARGE ";break;
	default: std::cout << "Bad name pizza.size\n";break;
	}

	std::cout << "Price: " << pizza.price << "\n";
}
void printDelivery(const PizzaDelivery& delivery)
{
	std::cout << delivery.clientName << " ";
	std::cout << delivery.telephone << " ";
	std::cout << delivery.address << " ";
	std::cout << delivery.totalSum << " ";
	std::cout << delivery.pizzaCount << " ";
	for (size_t i = 0; i < 3; i++)
	{
		printPizza(delivery.pizzas[i]);
	}
	
	
}
void writeDeliveryToFile(std::ofstream& out, PizzaDelivery* deliveries, unsigned n)
{
	
	out.write(reinterpret_cast<const char*>(deliveries), sizeof(deliveries[0])* n);
	if (out.fail())
	{
		std::cerr << "Problem writing in file " << FILE_NAME << "\n";
		return;
	}
	
}

void readDeliveryToFile(std::ifstream& in,PizzaDelivery * deliveries,unsigned n)
{
	in.read(reinterpret_cast<char*>(deliveries), sizeof(deliveries[0]) * n);

	if (in.fail() && !in.eof())
	{
		std::cerr << "Problem reading in file " << FILE_NAME << "\n";
		return;
	}
}

void generatePizza(Pizza& pizza)
{
	
	const PizzaType pizzaTypes[] = {PizzaType::MARGARITA,PizzaType::KALTSONE,
	PizzaType::BIANKA, PizzaType::PROSHUTO};


	const PizzaSize pizzaSizes[] = { PizzaSize::SMALL, PizzaSize::MEDIUM,
	 PizzaSize::LARGE};

	const double prices[] = {1.23,5.87,8.34,23.10,22.00};

	pizza.type = pizzaTypes[std::rand() % 4];
	pizza.size = pizzaSizes[std::rand() % 3];
	pizza.price = prices[std::rand() % 5];
}

void generateDelivery(PizzaDelivery& delivery)
{
	const char* names[] = {"Ivan Ivanov","Petar Petrov,", "Ivelin Georgiev","Stoyan st"};
	const char* telephones[] = {"359","088", "078","111"};
	const char* addresses[] = { "Kaloyanska","Vitoshka,","Alekasandorvska",
	"Gurko street" };
	const double sums[] = {5.67,11.68,23.91,79.11,16.60,33,82};
	const unsigned pizzaCounts[] = {1,5,8,3,9,6,11,8,4,};

	strcpy_s(delivery.clientName,names[std::rand() % 4]);
	strcpy_s(delivery.telephone,telephones[std::rand() % 4]);
	strcpy_s(delivery.address,addresses[std::rand() % 4]);
	delivery.totalSum = sums[std::rand() % 6];
	delivery.pizzaCount = pizzaCounts[std::rand() % 9];

	for (size_t i = 0; i < 3; i++)
	{
		generatePizza(delivery.pizzas[i]);
	}

}


int main()
{
	std::srand(std::time(0));


	std::cout << "Enter number of deliveries: ";
	unsigned n;
	std::cin >> n;
	PizzaDelivery * deliveries = new PizzaDelivery[n];

	for (size_t i = 0; i < n; i++)
	{
		generateDelivery(deliveries[i]);
		printDelivery(deliveries[i]);
	}



	std::ofstream out(FILE_NAME,std::ios::binary | std::ios::app);
	
	
	if (!out)
	{
		std::cerr << "Problem opening file for writing " << FILE_NAME << "\n";
		delete[] deliveries;
		return -1;
	}

	writeDeliveryToFile(out,deliveries,n);
	
	out.close();

	PizzaDelivery* deliveriesRead = new PizzaDelivery[n];

	std::ifstream in(FILE_NAME, std::ios::binary | std::ios::in);

	if (!in)
	{
		std::cerr << "Problem opening file for reading " << FILE_NAME << "\n";
		return -1;
	}
	
	readDeliveryToFile(in,deliveriesRead,n);
	
	std::cout << "--------------------------------READ FROM FILE----------------\n";
	std::cout << "--------------------------------READ FROM FILE----------------\n";
	for (size_t i = 0; i < n; i++)
	{
		printDelivery(deliveriesRead[i]);
	}



	delete[] deliveries;
	delete[] deliveriesRead;
}