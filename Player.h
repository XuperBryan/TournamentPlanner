#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>

class Player {
	public:
		Player(std::string name, std::string gender, int age, std::string club, int phone, std::string email);
		Player(const Player& orig);
		~Player();

		std::string getName() const;
		std::string getGender() const;
		int getAge() const;
		std::string getClub() const;
		int getPhone() const;
		std::string getEmail() const;

		void setName(std::string name);
		void setGender(std::string gender);
		void setAge(int age);
		void setClub(std::string club);
		void setPhone(int phone);
		void setEmail(std::string);
		
	private:
		std::string name;
		std::string gender;
		std::string club;
		int phone;
		int age;
		std::string email;
}


#endif