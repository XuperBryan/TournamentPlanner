#ifndef BRACKET_H
#define BRACKET_H

#include <iostream>
#include <vector>
#include <string>

#include "Player.h"

class Bracket {
public:
	Bracket(int size, std::string event);
	Bracket(const Bracket& orig);
	~Bracket();
	
	std::string getEvent();

	void arrangeBracket();
	void insertPair(Player person1, Player person2);
	void insertPlayer(Player person);
	void progress();	// move players "up" the bracket, updates the bracket?
	void setScore(std::vector<std::pair<int, int>> points, int matchNum);
	void makeCons(std::vector<std::pair<Player, Player>>);
private:
	void shuffle();

	struct Match {
		std::vector<std::pair<int, int>> points;
		std::pair<Player, Player> team1;
		std::pair<Player, Player> team2;
		std::pair<Player, Player> winner;
		int sets;
	};

	int size;
	int entrants = 0;
	std::string event;
	std::vector<Match> b;
};
#endif