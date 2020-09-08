#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>

class Player {
	public:
		Player();
		Player(std::string firstName, std::string lastName, std::string gender, int age, std::string club, int phone, std::string email, std::vector<std::string> events);
		Player(const Player& orig);
		~Player();

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getFullName() const;
		std::string getGender() const;
		int getAge() const;
		std::string getClub() const;
		int getPhone() const;
		std::string getEmail() const;
		std::vector<std::string> getEvents() const;

		void setFirstName(std::string name);
		void setLastName(std::string name);
		void setGender(std::string gender);
		void setAge(int age);
		void setClub(std::string club);
		void setPhone(int phone);
		void setEmail(std::string email);
		void addEvents(std::vector<std::string> newEvents);
		void removeEvents(std::vector<std::string> newEvents); 

		friend std::ostream& operator<<(std::ostream& os, const Player& p);
	private:
		std::string firstName;
		std::string lastName;
		std::string gender;
		std::string club;
		int phone;
		int age;
		std::string email;
		std::vector<std::string> events;
		/*int totalPoints = 0;
		int matchesWon = 0;*/
};


#endif
