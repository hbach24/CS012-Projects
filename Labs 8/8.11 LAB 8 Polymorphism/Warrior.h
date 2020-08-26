#include <iostream>
#include "Character.h"

using namespace std;

#ifndef __WARRIOR_H___
#define __WARRIOR_H___

class Warrior : public Character {
//Warrior does not attack Warriors of the same allegiance
private:
    string allegiance;
    
public:
    Warrior(const string& name, double health, double attackStrength, const string& allegiance );
    void attack(Character& ) override;
};

#endif