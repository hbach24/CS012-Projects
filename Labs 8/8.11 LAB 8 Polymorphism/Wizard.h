#include "Character.h"
#include <iostream>

using namespace std;

#ifndef __WIZARD_H__
#define __WIZARD_H__

class Wizard : public Character {
    private: 
        int rank;
    
    public:
        Wizard(const string& name, double health, double attackStrength, int rank);
        void attack(Character& ) override;
        //int getRank();
};

#endif
