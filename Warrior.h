#pragma once
#include "CharacterClass.h"

class Warrior : public CharacterClass
{
	public:
		Warrior();

		void printWarriorSkills();

		string getWarriorSkill();
		void setWarriorSkill(string s);

		void printWarriorAttacks();
		void printCondensedWarriorAttacks();

		int fistsOfFury();
		int doubleSlash();
		int burningStrike();

		bool inMoveListW(string s);

		void printMoveListW();

		int getDamageDealt();

		string* moveListW;

	private:

		int damageDealt = 0;

		CharacterClass userCharW;
		string swordName = "";
		string warriorSkill = "";
};