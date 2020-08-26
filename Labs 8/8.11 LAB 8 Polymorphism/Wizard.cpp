#include "Wizard.h"
#include <iostream>
#include "Character.h"
using namespace std;

Wizard::Wizard(const string& name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength), rank(rank) {}

void Wizard::attack(Character& opponent) {
    double dmg;
    if(opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        dmg = attackStrength * ((double)rank / opp.rank);

        
        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        cout << opp.getName() << " takes " << dmg << " damage." << endl;
        opponent.damage(dmg);
    }
    else {
        dmg = attackStrength;
        opponent.damage(dmg);
        
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << dmg << " damage." << endl;
        
    }
}