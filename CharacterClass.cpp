#include "CharacterClass.h"

void CharacterClass::setName(string s)
{
	name = s;
}
string CharacterClass::getName()
{
	return name;
}

void CharacterClass::setClassType(string s)
{
	classType = s;
}

string CharacterClass::getClassType()
{
	return classType;
}

void CharacterClass::setSkill(string s)
{
	skill = s;
}

string CharacterClass::getSkill()
{
	return skill;
}

void CharacterClass::setEndGame(bool b)
{
	endGame = b;
}

bool CharacterClass::getEndGame()
{
	return endGame;
}

void CharacterClass::setNewMove(string s)
{
	newMove = s;
}

string CharacterClass::getNewMove()
{
	return newMove;
}

int CharacterClass::getDamageDealt()
{
	return theDamageDealt;
}
void CharacterClass::setWeaponName(string s)
{
	weaponName = s;
}
string CharacterClass::getWeaponName()
{
	return weaponName;
}

void CharacterClass::setWeaponType(string s)
{
	weaponType = s;
}
string CharacterClass::getWeaponType()
{
	return weaponType;
}

void CharacterClass::setHP(int i)
{
	HP = i;
}
int CharacterClass::getHP()
{
	return HP;
}

void CharacterClass::setEnergy(int i)
{
	energy = i;
}

int CharacterClass::getEnergy()
{
	return energy;
}

string CharacterClass::getLastMove()
{
	return lastMove;
}

void CharacterClass::setArea(string s)
{
	area = s;
}
string CharacterClass::getArea()
{
	return area;
}
