//#include <algorithm>
#include "Player.h"
using namespace std;

Player::Player(std::string firstName, std::string lastName, std::string gender, 
                int age, std::string club, int phone, std::string email, 
                int seed, std::vector<std::string> events) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->gender = gender;
    this->age = age;
    this->club = club;
    this->phone = phone;
    this->email = email;
    this->seed = seed;
    this->events = events;
}

Player::Player(const Player& orig) {
    firstName = orig.firstName;
    lastName = orig.lastName;
    gender = orig.gender;
    age = orig.age;
    club = orig.club;
    phone = orig.phone;
    email = orig.email;
    seed = orig.seed;
    events = orig.events;
}

Player::~Player() {
}


string Player::getFirstName() const {
    return firstName;
}

string Player::getLastName() const {
    return lastName;
}

string Player::getFullName() const {
    return firstName + " " + lastName;
}

string Player::getGender() const {
    return gender;
}

int Player::getAge() const {
    return age;
}

string Player::getClub() const {
    return club;
}

int Player::getPhone() const {
    return phone;
}

string Player::getEmail() const {
    return email;
}

int Player::getSeed() const {
    return seed;
}

std::vector<std::string> Player::getEvents() const {
    return events;
}


void Player::setFirstName(std::string name) {
    firstName = name;
}

void Player::setLastName(std::string name) {
    lastName = name;
}

void Player::setGender(std::string gender) {
    gender = gender;
}

void Player::setAge(int age) {
    age = age;
}

void Player::setClub(std::string club) {
    club = club;
}

void Player::setPhone(int phone) {
    phone = phone;
}

void Player::setEmail(std::string email) {
    email = email;
}

void Player::setSeed(int seed) {
    seed = seed;
}

void Player::addEvents(std::vector<std::string> newEvents) {
    for(vector<string>::iterator it = newEvents.begin(); it != newEvents.end(); ++it) {
        events.push_back(*it);
    }
}

void Player::removeEvents(std::vector<std::string> newEvents) {
    for (vector<string>::iterator it = events.begin(); it != events.end(); it++) {
        events.erase(events.find(it),events.end());
    }
    /*for(int i = 0; i < newEvents.size(); i++) {
        for(vector<string>::iterator it = events.begin(); it != events.end(); ++it) {
            if(newEvents.at(i) == events.at(*it))
                events.erase(*it);
        }
    }*/

}

void Player::printPlayer() {
  cout << "bryan has a major" << endl;

  /*cout << Player::getFullName() << "\n" <<  Player::getGender() << "\n" <<  Player::getAge() << "\n" << 
             Player::getClub() << "\n" <<  Player::getPhone() << "\n" <<  Player::getEmail() << "\n" << 
             Player::getSeed() << "\n" <<  Player::getEvents() << endl;
*/
}    

