#include <string>

//class Player

#ifndef PLAYER_H

#define PLAYER_H

class Player {

public:
	Player();
	Player(std::string num);
	~Player();

	std::string checkNumber();
	std::string addGuess(std::string guess);

private:
	std::string number;
	std::string findCowsAndBulls(std::string);

	void setNumber(std::string);

};



#endif