#include "Order.h"
#include <stdexcept>
#include <new>
#include <cstring>


unsigned Order::sum = 0;
unsigned Order::prevCount = 0;

void Order::freeDynamic() noexcept
{
    delete[] products;
    products = nullptr;
}

void Order::copyDynamic(const Order& other)
{
    if (!setProducts(other.capacity))
        throw std::bad_alloc();

    for (size_t i = 0; i < count; i++)
    {
        products[i] = other.products[i];
    }
}

bool Order::setProducts(size_t capacity)
{
    if (capacity == 0)
    {
        this->capacity = 1;
        capacity = 1;
    }
    // this calls the default ctor for String and every string should be ""
    String* temp = new String[capacity]; 
    if (!temp)
        return false;
    
    products = temp;

    return true;
}


void Order::resize(size_t newCapacity)
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
void Order::ensureCapacity()
{
    if (count == capacity)
        resize(capacity * 2);
}

Order::Order() : Order("default name", 0) {}


Order::Order(const char* name, size_t count)
    : name(name), count(count), capacity(count*2), products(nullptr)
{
    if (!setProducts(capacity))
        throw std::bad_alloc();
}

Order::Order(const Order& other)
    :name(other.name), count(other.count), capacity(other.capacity)
{
    copyDynamic(other);
    Order::sum = other.sum;
    Order::prevCount = other.prevCount;
}

Order::Order(Order&& other) noexcept
    :name(other.name), count(other.count), 
    capacity(other.capacity), products(other.products)
{
    other.products = nullptr;
    Order::sum = other.sum;
    Order::prevCount = other.prevCount;
}

Order& Order::operator=(const Order& other)
{
    if (this != &other)
    {
        Order copy(other); // this throws
        freeDynamic();
        *this = std::move(copy);
        Order::sum = other.sum;
        Order::prevCount = other.prevCount;
    }
    return *this;
}

Order& Order::operator=(Order&& other) noexcept
{
    if (this != &other)
    {
        freeDynamic();
        products = other.products;
        other.products = nullptr;
        Order::sum = other.sum;
        Order::prevCount = other.prevCount;
    }
    return *this;
}

Order::~Order() noexcept
{
    freeDynamic();
}

void Order::addProduct(const String& str)
{
    ensureCapacity(); // throws
    products[count] = str;
    Order::sum += products[count].length() + 1;
    prevCount = ++count;
}

unsigned Order::calculateTime()
{
    if (Order::sum == 0)
    {
        Order::sum = count;
        for (size_t i = 0; i < count; i++)
        {
            sum += products[i].length();
        }
        return sum;
    }
   
    else if (Order::prevCount == count)
    {
        return sum;
    }
    
    else
    {
        throw std::logic_error("unexpected happend");
    }
}

const String* Order::getProduct(size_t index) const
{
    if (index >= count)
        return nullptr;
    else
        return &products[index];
}

