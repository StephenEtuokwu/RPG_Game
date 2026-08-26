#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
class CharacterClass
{
	public:

		void setName(string s);
		string getName();

		void setClassType(string s);
		string getClassType();

		void setWeaponName(string s);
		string getWeaponName();

		int getDamageDealt();

		void setHP(int i);
		int getHP();

		void setEnergy(int i);
		int getEnergy();

		void setSkill(string s);
		string getSkill();

		void setNewMove(string s);
		string getNewMove();

		void setArea(string s);
		string getArea();

		string getLastMove();


		void setEndGame(bool b);

		bool getEndGame();

		void setWeaponType(string s);
		string getWeaponType();

		int theDamageDealt = 0;

	protected:
		string name = "";
		string classType = "";
		string lastMove = "";
		string weaponName = "";
		string weaponType = "Basic";
		string skill = "";
		string newMove = "";
		string area = "";

		int HP = 0;
		int energy = 0;

		bool endGame = false;

};