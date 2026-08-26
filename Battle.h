#pragma once
#include "Warrior.h"
#include "Mage.h"
#include "Alchemist.h"
#include "Enemies.h"

class Battle : public Warrior, public Mage, public Alchemist, public Enemies
{
	public:
		Battle();
		void startBattle(CharacterClass c);
		void endBattle(CharacterClass c);
		void enemyTurn(CharacterClass c);
		void userTurn(CharacterClass c);

	private:
		CharacterClass c;

		Enemies e;

		int playerRoll = 0;
		int enemyRoll = 0;

		bool enemyBurned = false;
		bool enemyPoisoned = false;
		bool enemyWeakened = false;

		bool userBurned = false;

};
