#include <iostream>
#include "Library.h"

int main() {
	try {

		Book b1("1984", "George Orwell", false);
		Book b2("Dune", "Frank Herbert", false);
		Book b3("The Hobbit", "J.R.R. Tolkien", false);


		User user("JohnDoe", "0888123456");


		Library lib;
		lib.addBook(b1);
		lib.addBook(b2);
		lib.addBook(b3);

		std::cout << b1.getAuthor() << "\n";
		std::cout << b2.getId() << "\n";
		std::cout <<b2.getStatus()  << "\n";
		std::cout <<b2.getTitle()  << "\n";

		std::cout << "Books in library before taking:\n";
		lib.printInfo(0);
		lib.printInfo(1);
		lib.printInfo(2);

		if (lib.takeBook(1, user)) {
			std::cout << "\nUser successfully took book 1.\n";
		}
		else {
			std::cout << "\nFailed to take book 1.\n";
		}

		
		std::cout << "\nBook info after taking:\n";
		lib.printInfo(1);

	
		if (lib.returnBook(1, user)) {
			std::cout << "\nUser successfully returned book 1.\n";
		}
		else {
			std::cout << "\nFailed to return book 1.\n";
		}

		
		std::cout << "\nFinal book info:\n";
		lib.printInfo(1);

	}
	catch (const std::bad_alloc&) {
		std::cerr << "Memory allocation failed.\n";
	}
	catch (const char* err) {
		std::cerr << "Exception: " << err << "\n";
	}
	catch (std::invalid_argument&) {
		std::cerr << "Invalid argument : input cannot be null\n";
	}

	return 0;
}
