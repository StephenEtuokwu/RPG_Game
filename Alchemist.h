#pragma once
#include "CharacterClass.h"

class Alchemist : public CharacterClass
{
public:
	Alchemist();

	int getDamageDealt();

	void printAlchemistSkills();

	string getAlchemistSkill();
	void setAlchemistSkill(string s);

	void printAlchemistAttacks();
	void printCondensedAlchemistAttacks();

	int potionOfDamaging();
	int potionOfWeakening();
	void potionOfHealing();


	void printMoveListA();

	int moveListSizeA();

private:
	string* moveListA;

	int theDamageDealt = 0;
	int timesUsed = 0;

	string flaskType = "Old Flask";

	CharacterClass userCharA;
	string alchemistSkill = "";
};