#include <iostream>
#include "Warrior.h"
#include "Character.h"
using namespace std;

Warrior::Warrior(const string& name, double health, double attackStrength, const string& allegiance) : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) { }

void Warrior::attack(Character& opponent) {
    if(opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.allegiance == allegiance) {
            cout << "Warrior " << name << " does not attack " << "Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
        else 
        {
           double dmg = (health / MAX_HEALTH) * attackStrength;
           opponent.damage(dmg); 
           cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
           cout << opponent.getName() << " takes " << dmg << " damage." << endl; 
          
        }
    }
    else {
           double dmg = (health / MAX_HEALTH) * attackStrength;
           opponent.damage(dmg); 
           cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
           cout << opponent.getName() << " takes " << dmg << " damage." << endl; 
         }
}

