#include "Bracket.h"
#include <algorithm>
#include <cmath>

using namespace std;

Bracket::Bracket(int size, std::string event){
	this->size = size;
	this->event = event;
	bye1.setFirstName("Bye");
	bye2.setFirstName("Bye");
}

Bracket::Bracket(const Bracket& orig){
	size = orig.size;
	event = orig.event;
	bye1.setFirstName("Bye");
	bye2.setFirstName("Bye");
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
	
    int byes = size - p.size() - seeds.size() + 1;

    vector<pair<Player*, Player*>> firstMatches;

    // fills firstMatches with nullptrs
    for(int w = 0; w < size; w++) {
    	pair<Player*, Player*> temp(nullptr, nullptr);
    	firstMatches.push_back(temp);
    } 

    for(int i = 1; i < seeds.size(); i++) {
        firstMatches.at(seeding(i, size)) = seeds.at(i);
        if (byes > 0) {
        	firstMatches.at(seeding(i, size)+1).first = &bye1;
        	firstMatches.at(seeding(i, size)+1).second = &bye2;
        	byes--;
        }
    }

    for(int i = 1; i < firstMatches.size() && byes > 0; i+=2) {
        if(!firstMatches[i].first) {
            firstMatches[i].first = &bye1;
            firstMatches[i].second = &bye2;
            byes--;
        }
    }

    random_shuffle(p.begin(), p.end()); // shuffles the player*s

    int tsize = p.size();

    // nested for loop adds in the rest of the players into the bracket
    for(int i = 0; i < firstMatches.size() && p.size() > 0; i++){
        if(!(firstMatches[i].first)) {
            firstMatches[i] = p[0];
            p.erase(p.begin());
        }
    }

	/*for(int t = 0; t < firstMatches.size(); t++) {
		cout << t << endl;
		cout << firstMatches[t].first->getFirstName() << endl;
	}*/

	for (int p = 0; p < firstMatches.size(); p += 2) {
		Match m;
		m.team1.first = firstMatches[p].first;
		m.team1.second = firstMatches[p].second;
		m.team2.first = firstMatches[p+1].first;
		m.team2.second = firstMatches[p+1].second;
		m.sets = 3;
		b.push_back(m);
	}

	type = "elimination";
	
	// pushes the rest of the matches onto b
	for(int i = firstMatches.size()/2; i < size-1; i++){
		Match m;
		m.sets = 3;
		b.push_back(m);
	}

	// sets all match's next match 
	int tempSize = size/2; 
	for(int i = 0; i < size-2; i++){
		b[i].nextMatch = &b[i/2 + tempSize];
	}
	return;
}

int Bracket::seeding(int seed, int tempSize) {
    if(seed <= 1)
        return 0;

    if(seed % 2 == 0) 
        return tempSize/2 + seeding(seed/2, tempSize/2);

    return seeding(seed/2+1, tempSize/2);
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
	for(int i = 0; i < size-1; i++){ // size-2 should be index of last match
		if(b[i].winner.first != NULL && b[i].team1.first != NULL && b[i].team2.first != NULL){ 
			//cout << "checking index " << i << endl;
			if(i%2==0){ // even index, uses first team
				if(b.at(i).nextMatch->team1.first==NULL){
					b.at(i).nextMatch->team1.first = b.at(i).winner.first;
					b.at(i).nextMatch->team1.second = b.at(i).winner.second;
				}
			} else { // odd index, uses second team
				if(b.at(i).nextMatch->team2.first==NULL){
					b.at(i).nextMatch->team2.first = b.at(i).winner.first;
					b.at(i).nextMatch->team2.second = b.at(i).winner.second;
				}
			}
			//cout << "finished checking index " << i << endl;
		}
	}
}

// sets the scoure of the matchNum match
void Bracket::setScore(std::vector<std::pair<int, int>> points, int matchNum){
	b[matchNum].points = points;
	

    int t1 = 0;
    int t2 = 0;

    for(int i = 0; i < points.size(); i++) {
        if(points[i].first > points[i].second) {
            t1++;
        } else if (points[i].first < points[i].second) {
            t2++;
        }
    }

    if(t1 > t2) {
        b[matchNum].winner = b[matchNum].team1;
    } else {
        b[matchNum].winner = b[matchNum].team2;
    }

}

void Bracket::makeCons(std::vector<std::pair<Player*, Player*>> vect) {

}	

void Bracket::setSeeds(std::vector<std::pair<Player*, Player*>> vect) { // replaces entire vector of seeds with input
	pair<Player*, Player*> temp(nullptr, nullptr);
	seeds.push_back(temp);
	for (int w = 0; w < vect.size(); w++) {
		seeds.push_back(vect[w]);
	}
	for(int i = 0; i < p.size(); i++) {
        for(int j = 1; j < seeds.size(); j++) {
            if(p[i].first == seeds[j].first) {
                p.erase(p.begin()+i);
            }
        }
    }
	return;
}

void Bracket::printMatch(int num) {	// prints using the match number which signifies the index of the match in the bracket
	Match* m = &b[num];

	// prints the names of the first team, if statement prevents the second name from being printed if its a signles event
	cout << "Match " << (num+1) << " ";

	
	if(m->winner.first != nullptr) {
		cout << "(" << m->winner.first->getFullName();
		if(m->winner.second != nullptr) 
			cout << ", " << m->winner.second->getFullName();

        cout << ")";
	}

	if (!(m->team1.first)) {
		cout << "Uninitialized Team 1" << endl;
		return;
	}

    cout << endl;
	cout << "Team 1: " << (m->team1.first->getFullName());
	if (m->team1.second) {
		cout << ", " << (m->team1.second->getFullName());
	}
    
    cout << endl;

	// same as top but for second team
	if (!(m->team2.first)) {
		cout << "Uninitialized Team 2" << endl;
		return;
	}
	if(m->team2.first->getFullName() != "Bye ") {
        cout << "Team 2: " << (m->team2.first->getFullName());
	    if (m->team2.second) {
		    cout << ", " << (m->team2.second->getFullName());
	    }
    }

	if(m->team2.first->getFirstName() == "Bye") {
        cout << "Team 2: " << (m->team2.first->getFirstName());
    }
    cout << endl;

	// prints out the scores for each set
	for (int i = 0; i < m->sets; i++) {
		if(m->points[i].first != 0 && m->points[i].second != 0) 
            cout << (m->points[i].first) << ':' << (m->points[i].second) << endl;
	}
    cout << endl;
	return;
}

