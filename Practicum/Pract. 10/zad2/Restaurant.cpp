#define _CRT_SECURE_NO_WARNINGS
#include "Restaurant.h"
#include <cstring>
const unsigned DEFAULT_CAPACITY = 10;



void Restaurant::copyDynamic(const Restaurant& other)
{
    if (!setProducts(other.capacity))
        throw std::bad_alloc();

    for (size_t i = 0; i < count; i++)
    {
        products[i] = other.products[i];
    }
}

void Restaurant::freeDynamic() noexcept
{
    delete[] products;
    products = nullptr;
}

bool Restaurant::setProducts(size_t capacity)
{

    if (capacity == 0)
    {
        this->capacity = 1;
        capacity = 1;
    }

    // this calls the default ctor for String and every string should be ""
    String* temp = new(std::nothrow) String[capacity];
    if (!temp)
        return false;


    products = temp;
    return true;
}



bool Restaurant::setName(const char* newName)
{
    if (!newName || !*newName)
        return false;
    strncpy(name, newName,25);
    name[25] = '\0'; // guarantee nulltermination
    return true;
}


void Restaurant::resize(size_t newCapacity)
{

    String* temp = new String[newCapacity]; // throws
    for (size_t i = 0; i < count; i++)
    {
        temp[i] = products[i]; // this also throws
    }

    capacity = newCapacity;
    freeDynamic();
    products = temp;
}




Restaurant::Restaurant() : Restaurant("Default name") {}


Restaurant::Restaurant(const char* nameU)
    :capacity(DEFAULT_CAPACITY), count(0), products(nullptr)
{
    if (!setName(nameU))
        throw std::invalid_argument("bad name");

    if(!setProducts(DEFAULT_CAPACITY))  
        throw std::bad_alloc();
}

Restaurant::Restaurant(const Restaurant& other)
    : capacity(other.capacity), count(other.count), products(nullptr)
{
    std::cout << "Copying restaurant: " << other.name << "\n";
    std::strncpy(this->name, other.name, NAME_MAX_LENGTH);
    this->name[NAME_MAX_LENGTH] = '\0';
    std::cout << "Copied name: " << this->name << "\n";
    copyDynamic(other);
}

Restaurant::Restaurant(Restaurant&& other) noexcept
    :  capacity(other.capacity), count(other.count), products(other.products)
{
    other.products = nullptr;
}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
    if (this != &other)
    {
        freeDynamic();
        std::strncpy(this->name, other.name, NAME_MAX_LENGTH);
        this->name[NAME_MAX_LENGTH] = '\0';
        count = other.count;
        capacity = other.capacity;
        copyDynamic(other);
    }
    return *this;
}


Restaurant& Restaurant::operator=(Restaurant&& other) noexcept
{
    if (this != &other)
    {
        count = other.count;
        capacity = other.capacity;
        products = other.products;

        other.products = nullptr;
    }
    return *this;

}

Restaurant::~Restaurant() noexcept
{
    freeDynamic();
}

void Restaurant::ensureCapacity()
{
    if (count == capacity)
        resize(capacity);
}
    

void Restaurant::addProduct(const String& product)
{
    ensureCapacity(); // throws

    products[count++] = product; // throws
}

void Restaurant::receiveOrder(const Order& order)
{

    if(strcmp(order.getName(), this->getName()) != 0)
        throw std::logic_error("Name of order and restaurant must match");

    for (size_t i = 0; i < order.getCount(); i++)
    {
        bool found = false;
        for (size_t i = 0; i < count; i++)
        {
            if (*order.getProduct(i) == products[i])
            {
                found = true;
                continue;
            }
                
        }
        if (!found)
            throw std::logic_error("There is no such product in restaurant");
    }
}
