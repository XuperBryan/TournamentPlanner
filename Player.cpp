#include "Player.h"
using namespace std;

Player::Player() {
    this->firstName = "";
    this->lastName = "";
    this->gender = "";
    this->age = 0;
    this->club = "";
    this->phone = 0;
    this->email = "";
    this->events = {""};
}

Player::Player(std::string firstName, std::string lastName, std::string gender, 
                int age, std::string club, int phone, std::string email, 
                std::vector<std::string> events) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->gender = gender;
    this->age = age;
    this->club = club;
    this->phone = phone;
    this->email = email;
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

std::vector<std::string> Player::getEvents() const {
    return events;
}


void Player::setFirstName(std::string name) {
    this->firstName = name;
}

void Player::setLastName(std::string name) {
    this->lastName = name;
}

void Player::setGender(std::string gender) {
    this->gender = gender;
}

void Player::setAge(int age) {
    this->age = age;
}

void Player::setClub(std::string club) {
    this->club = club;
}

void Player::setPhone(int phone) {
    this->phone = phone;
}

void Player::setEmail(std::string email) {
    this->email = email;
}


void Player::addEvents(std::vector<std::string> newEvents) {
    for(vector<string>::iterator it = newEvents.begin(); it != newEvents.end(); ++it) {
        events.push_back(*it);
    }
}

void Player::removeEvents(std::vector<std::string> newEvents) {
    for(int i = 0; i < newEvents.size(); i++) {
        for(vector<string>::iterator it = events.begin(); it != events.end(); ++it) {
            if(newEvents[i] == *it)
                events.erase(it);
        }
    }

}

ostream& operator<<(ostream& os, const Player& p)
{
    // condition for checking missing information, also have labels
    os << (p.getFullName()) << "\n" << (p.getGender()) << "\n" <<  (p.getAge()) << "\n" << (p.getClub()) << "\n" << (p.getPhone()) << "\n" <<  (p.getEmail()) << endl;
    vector<string> temp = p.getEvents();
    for (int i = 0; i < temp.size(); i++) {
        os << temp[i] << '\n';
    }
    return os;
}