#pragma once

class GameFacade {
	// gameLogicSubSystem
	// settingsSubSystem
public:
	void startGame() { 
		// request input
		// start game logic from gameLogicSubSystem
		// end game
	}
	
	void getUsersInfo() {
		// fetch users from db
		// prepare data to display
		// dispay data
	}

	void displaySettings () {
		// fetch user's settings from settingsSubSystem
		// display settings
	}
};