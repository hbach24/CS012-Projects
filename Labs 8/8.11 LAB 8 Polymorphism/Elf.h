#include <iostream>
#include "Character.h"
using namespace std;

#ifndef __ELF_H___
#define __ELF_H___

class Elf : public Character {
//Warrior does not attack Warriors of the same allegiance
private:
    string family;
    
public:
    Elf(const string& name, double health, double attackStrength, const string& family );
    void attack(Character& ) override;
};

#endif