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
	int getSize();
	std::string getType();

	void updateSize();
	void makeRoundRobin();
	void makeElimination();
	void insertPair(Player* person1, Player* person2);
	void insertPlayer(Player* person);
	void progress();	// move player*s "up" the bracket, updates the bracket?
	void setScore(std::vector<std::pair<int, int>> points, int matchNum);
	void makeCons(std::vector<std::pair<Player*, Player*>> vect);
	void setSeeds(std::vector<std::pair<Player*, Player*>> vect);
	void printMatch(int num);
    int seeding(int seed, int size);
private:
	void shuffle();

	struct Match {
		std::vector<std::pair<int, int>> points;
		std::pair<Player*, Player*> team1;
		std::pair<Player*, Player*> team2;
		std::pair<Player*, Player*> winner;
		int sets;

		Match() {
			points = {std::pair<int, int>(0,0)};
			team1.first = nullptr;
			team1.second = nullptr;
			team2.first = nullptr;
			team2.second = nullptr;
			winner.first = nullptr;
			winner.second = nullptr;
			sets = 0;
		}

		Match(std::pair<Player*, Player*> team1, std::pair<Player*, Player*> team2, int sets) {
			points = {std::pair<int, int>(0,0)};
			this->team1 = team1;
			this->team1 = team2;
			winner.first = nullptr;
			winner.second = nullptr;
			this->sets = sets;
		}

		/*~Match() {
			delete team1.first;
			delete team1.second;
			delete team2.first;
			delete team2.second;
			delete winner.first;
			delete winner.second;
		}*/
	};

	int minSize = 5;
	int size;
	int entrants = 0;
	std::string event;
	std::vector<Match> b;
	std::vector<std::pair<Player*, Player*>> p;
	std::string type = "roundRobin"; // "roundRobin" or "elimination"
	std::vector<std::pair<Player*, Player*>> seeds; 

	Player bye1, bye2;
};
#endif
