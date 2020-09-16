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

	Player people [6];
	people[0].setFirstName("Henry");
	people[1].setFirstName("Daniel");
	people[2].setFirstName("Nicole");
	people[3].setFirstName("Martin");
	people[4].setFirstName("Karissa");
	people[5].setFirstName("Marc");
	//people[6].setFirstName("Tony");

	Bracket AMS(0,"AMS");

	vector<pair<Player*, Player*>> vect;
	pair<Player*, Player*> yoyoma(&people[1],nullptr);
	//pair<Player*, Player*> yoyomather(&people[5],nullptr);
	vect.push_back(yoyoma);
	//vect.push_back(yoyomather);

	for (int i = 0; i < 6; i++) {
		AMS.insertPlayer(&people[i]);
	}

	AMS.setSeeds(vect);

    AMS.makeElimination();


    vector<pair<int, int>> points;
    pair<int, int> set1(21, 1);
    pair<int, int> set2(1, 21);
    pair<int, int> set3(21, 19);

    points.push_back(set1);
    points.push_back(set2);
    points.push_back(set3);

    AMS.setScore(points, 1);
	
	for (int j = 0; j < 4; j++) {
		AMS.printMatch(j);
	}
    return 0;
}

