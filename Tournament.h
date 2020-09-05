#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <iostream>
#include <vector>
#include <string>

#include "Bracket.h"

class Tournament {
public:
	Tournament();
	Tournament(const Tournament& orig);
	~Tournament();

    void printTournament();
    void addEvent(std::string name, int size);
    

private:
	std::vector<Bracket> events;

    std::string venue;
    std::string address;
    std::string title;
    std::string startDate;
    std::string endDate;
    std::string startTime;
    std::string endTime;
    std::string contactName;
    int contactPhone;
    std::string entryOpen;
    std::string entryDeadline;
    std::string withdrawalDeadline;
    std::string moreInfo;

    std::vector<std::pair<Player, Player>> winners;


    



};

#endif
