#include <iostream>
#include <vector>

#include "Bracket.h"
#include "Player.h"
#include "Tournament.h"

using namespace std;

int main(){
	/*Player p("Hehe", "Haha", "Green", -489527, "Club Penguin", 4, "thisisdumb@dumb.com", 10000, {"A","B","C"});
	vector<string> vect = p.getEvents();
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << endl;
	}
	p.removeEvents({"A","B"});
	p.addEvents({"D"});
	vector<string> vects = p.getEvents();
	for (int j = 0; j < vects.size(); j++) {
		cout << vects[j] << endl;
	}*/

	Player people [4];
	people[0].setFirstName("Henry");
	people[1].setFirstName("Daniel");
	people[2].setFirstName("Nicole");
	people[3].setFirstName("Martin");

	Bracket AMS(0,"AMS");

	for (int i = 0; i < 4; i++) {
		AMS.insertPlayer(&people[i]);
	}

	cout << AMS.getSize() << endl;

	AMS.makeRoundRobin();
	
	for (int j = 0; j < 6; j++) {
		AMS.printMatch(j);
	}
	return 0;
}

