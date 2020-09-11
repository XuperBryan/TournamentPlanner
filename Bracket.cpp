#include "Bracket.h"
#include <algorithm>
#include <cmath>

using namespace std;


Bracket::Bracket(int size, std::string event){
	this->size = size;
	this->event = event;
}

Bracket::Bracket(const Bracket& orig){
	size = orig.size;
	event = orig.event;
}

Bracket::~Bracket(){

}

string Bracket::getEvent(){
	return event;
}

int Bracket::getSize(){
	return size;
}


void Bracket::updateSize() {
	if (p.size() <= minSize) {
		size = p.size();
	}
	else {
		size = pow(2, ceil(log(p.size())/log(2)));
	}
}

void Bracket::makeRoundRobin(){
	// size = 2, 3, 4, 5
	// b.size() = n * n-1
	Match m;
	for(int i = 0; i < p.size(); i++) {

for(int j = i+1; j < p.size(); j++) {
			m.team1 = p[i];
			m.team2 = p[j];
			m.sets = 3;
			b.push_back(m);
		}
	}
	type = "roundRobin";
}

// makes elimination bracket while respecting seeds
void Bracket::makeElimination(){
	// size = 4, 8, 16, 32
	// b.size() = <2, <4, <8, <16  
	
    int byes = 0;
    pair<Player*, Player*> bye;

    if(size > p.size()) {
        byes = size - p.size();
    }

    vector<pair<Player*, Player*>> firstMatches;


    for(int i = 0; i < seeds.size(); i+=2) {
        firstMatches.at(seeding(i, firstMatches.size())) = seeds.at(i);
    }

    for(int i = 0; i < p.size(); i++) {
        for(int j = 0; j < seeds.size(); j++) {
            if(p.at(i) == seeds.at(j)) {
                p.erase(p.begin()+i);
             }
        }
    }

    while(byes > 0) {
        for(int i = 0; i < firstMatches.size(); i++) {
            if(!firstMatches[i].first) {
                firstMatches.at(i) = bye;
                byes--;
            }
        }
    }

    random_shuffle(p.begin(), p.end()); // shuffles the player*s

    while(!p.empty()) {
        for(int i = 0; i < firstMatches.size(); i++){
            if(!firstMatches[i].first) {
                firstMatches.at(i) = p.at(0);
                p.erase(p.begin());
            }
        }
	}

	type = "elimination";
}

int Bracket::seeding(int seed, int size) {
    if(seed <= 1)
        return 0;

    if(seed % 2 == 0) 
        return size/2 + seeding(seed/2, size/2);

    return seeding(seed/2+1, size/2);

}
    


void Bracket::insertPair(Player* person1, Player* person2) {
	entrants += 2;
	p.push_back(pair<Player*,Player*>(person1,person2));
	updateSize();
	return;
}

void Bracket::insertPlayer(Player* person) {
	entrants++;
	p.push_back(pair<Player*,Player*>(person,nullptr));
	updateSize();
	return;
}

// move players "up" the bracket, updates the bracket
void Bracket::progress(){

}

void Bracket::setScore(std::vector<std::pair<int, int>> points, int matchNum){
	// set score code here
	// set winner code here

	/*if(getType.equals("roundRobin")){
		for(int i = 0; i < b.size(); b++){
			Pair<Player*,Player*> winners;
			for(int j = 0; j < p.size(); j++){
				if(b[i].winner == p[j]){ // general idea of code
					p[j].matchWins++;
				}

			}
		}
	}*/
}

void Bracket::makeCons(std::vector<std::pair<Player*, Player*>>) {

}	

void Bracket::setSeeds(std::vector<std::pair<Player*, Player*>>) { // replaces entire vector of seeds with input

}

void Bracket::printMatch(int num) {	// prints using the match number which signifies the index of the match in the bracket
	Match* m = &b[num];

	// prints the names of the first team, if statement prevents the second name from being printed if its a signles event
	cout << (m->team1.first->getFullName()) << '\n';
	if (m->team1.second) {
		cout << (m->team1.second->getFullName()) << '\n';
	}

	// same as top but for second team
	cout << (m->team2.first->getFullName()) << '\n';
	if (m->team2.second) {
		cout << (m->team2.second->getFullName()) << '\n';
	}

	// prints out the scores for each set
	for (int i = 0; i < m->sets; i++) {
		cout << (m->points[i].first) << ':' << (m->points[i].second) << endl;
	}
	return;
}
