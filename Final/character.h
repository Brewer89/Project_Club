#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using namespace std;

class character{
private:
    string name;
    string race;
    string charClass;
    int armor;
    int health;
    int stamina;
    int magic;
    int strength;
public:
    character();
    void setName(string inName) {this->name = inName;}
    void setRace(string inRace) {this->race = inRace;}
    void setCharClass(string inChar) {this->charClass = inChar;}
    void setArmor(int inArmor) {this->armor = inArmor;}
    void setHealth(int inHealth) {this->health = inHealth;}
    void setStamina(int inStamina) {this->stamina = inStamina;}
    void setMagic(int inMagic) {this->magic = inMagic;}
    void setStrength(int inStrength) {this->strength = inStrength;}
    string getName() const { return name; }
    string getRace() const { return race; }
    string getCharClass() const { return charClass; }
    int getArmor() const { return armor; }
    int getHealth() const { return health; }
    int getStamina() const { return stamina; }
    int getMagic() const { return magic; }
    int getStrength() const { return strength; }

};

#endif // CHARACTER_H
