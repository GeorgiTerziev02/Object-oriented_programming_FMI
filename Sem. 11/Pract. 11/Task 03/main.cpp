#include <iostream>
#include "User.h"
#include "Guest.h"
#include "PremiumPlayer.h"

int main()
{
	try {
		Guest g(777);
		g.completeMission(2000);
		g.levelUp();

		PremiumPlayer premium(123, "username", "passs");
		premium.login(123, "passs");

		premium.completeMission(1060);
		premium.levelUp();
		premium.levelUp();
		premium.levelUp();
		premium.levelUp();

		User user(111, "userpass");
		user.login(111, "userpass");
		user.completeMission(1060);
		user.levelUp();
		user.levelUp();
		user.levelUp();
		user.levelUp();

	}
	catch (std::exception e) {
		std::cout << e.what();
	}
}