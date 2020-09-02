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
private:
	std::vector<Bracket> flights;
};

#endif