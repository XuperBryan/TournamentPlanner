#include "Bracket.h"
#include <algorithm>

using namespace std;


Bracket::Bracket(int size, std::string event){
	this->size = size;
	this->event = event;
}

Bracket::Bracket(const Bracket& orig){
	size = orig.size;
	event = orig.event;
}

~Bracket(){

}

string Bracket::getEvent(){
	return event;
}

int Bracket::getSize(){
	return size;
}


void Bracket::makeRoundRobin(){
	// size = 2, 3, 4, 5
	// b.size() = n * n-1
	for(int i = 0; i < p.length(); i++) {
		for(int j = i+1; j < p.length(); j++) {
			Bracket::Match m;
			m.team1 = p[i];
			m.team2 = p[j];
			m.sets = 3;
		}
	}
	type = "roundRobin";
}

// makes elimination bracket while respecting seeds
void Bracket::makeElimination(){
	// size = 4, 8, 16, 32
	// b.size() = <2, <4, <8, <16  
	random_shuffle(p.begin(), p.end()); // shuffles the players
	for(int i = 0; i < p.size(); i++){

	}

	type = "elimination";
}


void insertPair(Player person1, Player person2);
void insertPlayer(Player person);

// move players "up" the bracket, updates the bracket?
void progress(){

}

void setScore(std::vector<std::pair<int, int>> points, int matchNum){
	// set score code here
	// set winner code here

	/*if(getType.equals("roundRobin")){
		for(int i = 0; i < b.size(); b++){
			Pair<Player,Player> winners;
			for(int j = 0; j < p.size(); j++){
				if(b[i].winner == p[j]){ // general idea of code
					p[j].matchWins++;
				}

			}
		}
	}*/
}

void makeCons(std::vector<std::pair<Player, Player>>);	
void setSeeds(std::vector<std::pair<Player, Player>>); // replaces entire vector of seeds with input