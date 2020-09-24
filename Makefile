# Makefile

CXX = g++

TournamentPlanner: Tournament.o Bracket.o Player.o TournamentPlanner.o
	${CXX} $^ -o $@

clean:
	rm *.o TournamentPlanner