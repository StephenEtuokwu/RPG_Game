#pragma once

#include "CharacterClass.h"

class Enemies: public CharacterClass
{
	public:

		Enemies();

		int getEnemyHP();
		void setEnemyHP(int i);

		string getEnemyName();
		void setEnemyName(string s);

		string getEnemyMove(int k);

		//Ranger Attacks
		void shootArrow();
		void stab();

		//Skeleton Attacks
		void boneBarrage();
		void bonyBash();

		//Spider Attacks
		void stringShot();
		void bite();

		//Dragon Attacks
		void dragonClaw();
		void flameBreath();

		int getDamageDealt();

		string* moveList;

	private:

		int damageDealt = 0;
		int enemyHP = 0;
		string enemyName = "";
};