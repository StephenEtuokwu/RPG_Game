#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Classes
{
	public:

		void setName(string s);
		string getName();

		void setClassType(string s);
		string getClassType();

		void setLevel(int i);
		int getLevel();

		void setHP(int i);
		int getHP();

		void setEnergy(int i);
		int getEnergy();

	protected:

		string name;
		string classType;

		int HP;
		int energy;
		int level;
};