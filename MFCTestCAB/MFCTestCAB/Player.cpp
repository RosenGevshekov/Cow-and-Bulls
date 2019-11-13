#include "stdafx.h"
#include "Player.h"


Player::Player() {
}

Player::Player(std::string num) {
	setNumber(num);
}

Player::~Player() {
}


void Player::setNumber(std::string num) {
	number = num;
}

std::string Player::checkNumber() {
	return number;
}

std::string Player::findCowsAndBulls(std::string guess) {
	int bulls(0), cows(0);
	for (int i = 0; i < 4; i++) {
		if (guess[i] == number[i]) {
			bulls++;
		}
		else {
			for (int j = 0; j < 4; j++) {
				if (guess[i] == number[j] && i != j) {
					cows++;
					break;
				}
			}
		}
		
	}



	std::string cowsAndBulls = "	" + guess + " --> " + std::to_string(cows) + " cows and " + std::to_string(bulls) + " bulls\r\n";
	return cowsAndBulls;
}

std::string Player::addGuess(std::string guess) {
	if (checkNumber() == guess) {
		return "		WIN!" ;

	}
	else {
		return findCowsAndBulls(guess);
	}
	
}
