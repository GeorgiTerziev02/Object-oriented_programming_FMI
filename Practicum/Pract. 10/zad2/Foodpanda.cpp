#include "Foodpanda.h"
#include <new>
#include <algorithm>

void Foodpanda::copyDynamic(const Foodpanda& other)
{
    if (!setRestaurants(other.capacity))
        throw std::bad_alloc();

    for (size_t i = 0; i < count; i++)
    {
        restaurants[i] = other.restaurants[i];
    }
}

void Foodpanda::freeDynamic() noexcept
{
    delete[] restaurants;
    restaurants = nullptr;
}

bool Foodpanda::setRestaurants(size_t capacity)
{
    if (capacity == 0)
    {
        this->capacity = 1;
        capacity = 1;
    }

    Restaurant* temp = new(std::nothrow) Restaurant[capacity];
    if (!temp)
        return false;
    restaurants = temp;

    return true;

}

void Foodpanda::resize(size_t newCapacity)
{
    Restaurant* temp = new Restaurant[newCapacity]; // throws bad alloc
    for (size_t i = 0; i < count; i++)
    {
        temp[i] = restaurants[i]; // this also throws bad alloc
    }

    capacity = newCapacity;
    freeDynamic();
    restaurants = temp;

}




Foodpanda::Foodpanda(size_t capacityU)
    : capacity(capacityU), count(0), restaurants(nullptr)
{
    if (!setRestaurants(capacity)) // if there is another dynamic memory
        // i will write it here in the if and call freedynamic before throw for all;
        throw std::bad_alloc();
}

Foodpanda::Foodpanda(const Foodpanda& other)
    :capacity(other.capacity), count(other.count), restaurants(nullptr)
{
    copyDynamic(other);
}

Foodpanda::Foodpanda(Foodpanda&& other) noexcept
    : capacity(other.capacity), count(other.count), restaurants(other.restaurants)
{
    other.restaurants = nullptr;
}

Foodpanda& Foodpanda::operator=(const Foodpanda& other)
{
    if (this != &other)
    {
        Foodpanda copy(other);
        std::swap(restaurants,copy.restaurants);
        std::swap(count,copy.count);
        std::swap(capacity,copy.capacity);
        
    }
    return *this;
}

Foodpanda& Foodpanda::operator=(Foodpanda&& other) noexcept
{
    if (this != &other)
    {
        std::swap(restaurants, other.restaurants);
        std::swap(count, other.count);
        std::swap(capacity, other.capacity);
        // isnt this just better??
    }
    return *this;
}

Foodpanda::~Foodpanda() noexcept
{
    freeDynamic();
}

void Foodpanda::ensureCapactiy()
{
    if (count == capacity)
        resize(capacity * 2);
}


int Foodpanda::findRestaurant(const String& name)
{
    bool found = false;
    int index;
    for (size_t i = 0; i < count; i++)
    {
        std::cout << "Total count: " << count << "\n";
        std::cout << "Comparing '" << restaurants[i].getName()
            << "' with '" << name.c_str() << "'\n";
        if (strcmp(restaurants[i].getName(), name.c_str()) == 0)
        {
            index = i;
            found = true;
            break;
        }
    }
    return (found) ? index : -1;
}

void Foodpanda::addProductToRestaurant(const String& str)
{
    int index;
    
   index = findRestaurant(str);
    if (index == -1)
        throw std::invalid_argument("couldn't find restaurant name");

    restaurants[index].addProduct(str); // throws

}

void Foodpanda::addNewRestaurant(const Restaurant& rest)
{
    int index;

    index = findRestaurant(rest.getName());
    if (index != -1)
        throw std::invalid_argument(" restaurant already exist");
    
    ensureCapactiy(); // throws bad alloc
    restaurants[count++] = rest;

}

void Foodpanda::addOrder(const Order& order,const Restaurant& rest)
{
    int index;

    index = findRestaurant(rest.getName());


    if (index == -1)
        throw std::invalid_argument("couldnt find restaurant name");

    restaurants[index].receiveOrder(order); // throws

}


