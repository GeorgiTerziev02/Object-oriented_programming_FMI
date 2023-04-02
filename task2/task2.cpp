#include <iostream>
#include<sstream>
#include "ShoppingCart.h"
int main()
{
    ShoppingCart shoppingCart;
    while (true) {
        char userInput[100],command[20];
        std::cout << ">";
        std::cin.getline(userInput,100);
        std::stringstream ss(userInput);
        ss >> command;
        if (strcmp(command, "addItem") == 0) {
            char name[20];
            bool availabilty;
            float price;
            ss >> name >> availabilty >> price;
            shoppingCart.addItem(name, availabilty, price);
        }
        else if (strcmp(command, "removeItem") == 0) {
            char name[20];
            ss >> name;
            shoppingCart.removeItem(name);
        }
        else if (strcmp(command, "getItemsCount")==0) {
            shoppingCart.getItemsCount();
        }
        else if (strcmp(command, "isEmpty") == 0) {
            shoppingCart.isEmpty();
        }
        else if (strcmp(command, "getPriceOf") == 0) {
            char name[20];
            ss >> name;
            shoppingCart.getPriceOf(name);
        }
        else if (strcmp(command, "getTotalPrice") == 0) {
            shoppingCart.getTotalPrice();
        }
        else if (strcmp(command, "sortByName") == 0) {
            shoppingCart.sortByName();
            std::cout << "The cart has been sorted successfully" << std::endl;
        }
        else if (strcmp(command, "save") == 0) {
            char fileName[20];
            ss >> fileName;
            shoppingCart.saveToFile(fileName);

            break;
        }
    }
}
