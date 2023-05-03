#include <iostream>
#include "MyString.h"
#include "Foodpanda.h"
#include "Restaurant.h"
int main()
{
    Foodpanda foodpanda(10);
    Restaurant r1(10, "restaurant 1");
    Restaurant r2(10, "second restaurant");

    //...

    foodpanda.addRestaurant(r1);
    foodpanda.addRestaurant(r2);

    //...

    foodpanda.manageOrders();

}