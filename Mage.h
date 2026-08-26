#pragma once
#include "CharacterClass.h"

class Mage : public CharacterClass
{
public:
	Mage();

	int getDamageDealt();

	void printMageSkills();

	bool inMoveListM(string s);

	string getMageSkill();
	void setMageSkill(string s);

	void printMageAttacks();
	void printCondensedMageAttacks();

	int fireball();
	int poisonSpray();
	int magicMissile();
	int thunderclap();

	string* moveListM;

	void printMoveListM();

private:

	int damageDealt = 0;

	CharacterClass userCharM;
	string staffName = "";
	string mageSkill = "";
};