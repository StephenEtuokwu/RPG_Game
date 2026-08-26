#include "Warrior.h"
#include "Battle.h"

Warrior::Warrior()
{
	moveListW = new string[3];

	moveListW[0] = "Fists Of Fury";
	moveListW[1] = "Double Slash";
	moveListW[2] = "";

	HP = 20;
	energy = 100;
}

void Warrior::setWarriorSkill(string s)
{
	warriorSkill = s;
	skill = s;
}

string Warrior::getWarriorSkill()
{
	return warriorSkill;
}

int Warrior::getDamageDealt()
{
	return theDamageDealt;
}

void Warrior::printMoveListW()
{
	for (int k = 0; k < 3; k++)
	{
	  cout << moveListW[k];
	  if (moveListW[2] == "" && k >= 1)
		  cout << "";
	  else
		  cout << " | ";
	}
}

bool Warrior::inMoveListW(string s)
{
	for (int k = 0; k < 3; k++)
	{
		if (moveListW[k] == s)
			return true;
	}
	return false;
}

void Warrior::printWarriorSkills()
{
	//Print the Skills Gambler Hustler Oppurtunist

	cout << "Gambler: Increases your max damage rolls by 20% but decreases your minimum damage rolls by 30% " << endl;
	cout << "(Ex: A 5 - 10 damage roll becomes 3 - 12) (Gambler has the minimum damage roll round down unless it rounds down to 0, maximum damage roll round up)" << endl << endl;
	cout << "Hustler: Increases minimum and maximum damage rolls 20% but also increases your chance to miss by 20%" << endl;
	cout << "(Ex A 5 - 10 damage roll with 90% accurracy becomes a 6 - 12 damage roll with 72% accurracy) (Hustler rounds up for both min and max values)" << endl << endl;
	cout << "Oppurtunist: Have a 50% chance of preforming the same move twice in quick sucession, but reduces total damage by 30%" << endl;
	cout << "(Ex: A 5 - 10 damage roll becomes a 3 - 7 damage roll if you don't attack twice and a 6 - 14 damage roll if you do attack twice" << endl << endl;
}

void Warrior::printWarriorAttacks()
{
	cout << "You have two main attacks: Fists Of Fury | Double Slash" << endl << endl; 
	cout << "Fists Of Fury: If not dodged, you hit the enemy with 5 punches." << endl;
	cout << "Damage (per punch) 1 - 3 | Accuracy 90% | Critcal Hit Chance (per punch) 20% | Energy Use: 10" << endl << endl;
	cout << "Double Slash: If not dodged, you slash at the enemy twice with your " << getWeaponName() << "." << endl;
	cout << "Damage (per slash) 2 - 6 | Accurracy 80% | Critical Hit Chance (per slash) 10% | Energy Use: 15" << endl << endl;
	cout << "Now for some information about the general battle" << endl;
	cout << "Critical hits do 2x the normal amount of damage that would've happened if the move hadn't crit" << endl << endl;
	cout << "Your max energy is 100, using moves uses up energy. When energy hits 0, you deal only 75% of your total damage and you take 25% more damage" << endl << endl;
	cout << "Your HP and Energy will be replensihed to full after every battle" << endl << endl;
}

void Warrior::printCondensedWarriorAttacks()
{
	cout << "Fists Of Fury: If not dodged, you hit the enemy with 5 punches." << endl;
	cout << "Damage (per punch) 1 - 3 | Accuracy 90% | Critcal Hit Chance (per punch) 20% | Energy Use: 10" << endl << endl;
	cout << "Double Slash: If not dodged, you slash at the enemy twice with your " << getWeaponName() << "." << endl;
	cout << "Damage (per slash) 2 - 6 | Accurracy 80% (per slash) | Critical Hit Chance (per slash) 10% | Energy Use: 15" << endl << endl;
}
int Warrior::fistsOfFury()
{
	//A move that hits 5 times, each hit dealing a base 1 - 3 damage before modifiers

	lastMove = "Fists Of Fury";

	srand(time(0));
	double accuracy = 90;

	if (getWarriorSkill() == "Hustler")
		accuracy *= .80;

	double accuracyRoll = rand() % 100 + 1;
	int totalDamageDealt = 0;
	int tempDamageDealt = 0;
	int numPunch = 1;

	int minDamage = 1;
	int maxDamage = 3;
	
	bool missed = false;

	cout << " You used Fists of Fury which";

	if (accuracyRoll > accuracy)
	{
		cout << " misses. The enemy has evaded your Fists of Fury." << endl;
		damageDealt = 0;
	}
	else
	{
		cout << " lands! Now to see how your flurry punches land!" << endl << endl;

		for (int k = 0; k < 5; k++)
		{
			if (getSkill() == "Gambler")
			{
				tempDamageDealt = (rand() % (static_cast<int>(ceil(maxDamage * 1.2)) + 1 - minDamage) + minDamage);
				if (rand() % 5 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Punch " << numPunch << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Punch " << numPunch << " does " << tempDamageDealt << " damage  ";
				}
			}
			else if (getSkill() == "Hustler")
			{
				tempDamageDealt = (rand() % (static_cast<int>(ceil(maxDamage * 1.2)) + 1 - static_cast<int>(ceil(minDamage * 1.2)))) + static_cast<int>(ceil(minDamage * 1.2));
				if (rand() % 5 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Punch " << numPunch << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Punch " << numPunch << " does " << tempDamageDealt << " damage  ";
				}
			}
			else
			{
				tempDamageDealt = ceil(((rand() % (maxDamage + 1 - minDamage)) + minDamage) * .7);
				if (rand() % 5 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Punch " << numPunch << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Punch " << numPunch << " does " << tempDamageDealt << " damage  ";
				}
			}
			numPunch++;
		}
		if (rand() % 2 == 1 && getWarriorSkill() == "Oppurtunist")
		{
			if (missed == false)
				cout << endl << "A moment of oppurtunity has arisen, time to start pummeling!" << endl;
			else
				cout << endl << "Amazingly, an opputunity has arisen because of your miss, time to start pummeling!" << endl;
			for (int k = 0; k < 5; k++)
			{
				tempDamageDealt = ceil(((rand() % (maxDamage + 1 - minDamage)) + minDamage) * .7);
				if (rand() % 5 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Punch " << numPunch << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Punch " << numPunch << " does " << tempDamageDealt << " damage  ";
				}
				numPunch++;
			}
		}
		cout << endl << "You did a total of " << totalDamageDealt << " points of damage with your furious flurry!" << endl;
		damageDealt = totalDamageDealt;
	}
	return damageDealt;
}
int Warrior::doubleSlash()
{
	//A move that hits twice, each hit doing 2 - 6 damage before modifiers

	lastMove = "Double Slash";

	srand(time(0));
	double accuracy = 80;

	if (getWarriorSkill() == "Hustler")
		accuracy *= .80;

	double accuracyRoll = rand() % 100 + 1;
	int totalDamageDealt = 0;
	int tempDamageDealt = 0;
	int numSlash = 1;

	int minDamage = 2;
	int maxDamage = 6;

	bool missed = false;

	cout << "You use Double Slash which";
	if (accuracyRoll > accuracy)
	{
		cout << " misses. The enemy has evaded your Double Slash." << endl;
		damageDealt = 0;
	}
	else
	{
		cout << " lands! Now to see how your slashes land!" << endl << endl;

		for (int k = 0; k < 2; k++)
		{
			if (getWarriorSkill() == "Gambler")
			{
				tempDamageDealt = ((rand() % (static_cast<int>(ceil(maxDamage * 1.2)) + 1 - static_cast<int>(floor(minDamage*.7)))) + static_cast<int>(floor(minDamage * .7)));
				if (rand() % 10 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Your " << numSlash << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Slash " << numSlash << " does " << tempDamageDealt << " damage  ";
				}
			}
			else if (getWarriorSkill() == "Hustler")
			{
				tempDamageDealt = ((rand() % (static_cast<int>(ceil(maxDamage * 1.2)) + 1 - static_cast<int>(ceil(minDamage * 1.2)))) + static_cast<int>(ceil(minDamage * 1.2)));
				if (rand() % 10 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Slash " << numSlash << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Slash " << numSlash << " does " << tempDamageDealt << " damage  ";
				}
			}
			else
			{
				tempDamageDealt = ceil(((rand() % (maxDamage + 1 - minDamage)) + minDamage) * .7);
				if (rand() % 10 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Slash " << numSlash << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Slash " << numSlash << " does " << tempDamageDealt << " damage  ";
				}
			}
			numSlash++;
		}
		if (rand() % 2 == 1 && getWarriorSkill() == "Oppurtunist")
		{
			if (missed == false)
				cout << endl << "A moment of oppurtunity has arisen, time to start slashing!" << endl;
			else
				cout << endl << "Amazingly, an opputunity has arisen because of your miss, time to start slashing!" << endl;
			for (int k = 0; k < 5; k++)
			{
				tempDamageDealt = ceil(((rand() % (maxDamage + 1 - minDamage)) + minDamage) * .7);
				if (rand() % 5 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Slash " << numSlash << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Slash " << numSlash << " does " << tempDamageDealt << " damage  ";
				}
				numSlash++;
			}
		}
		damageDealt = totalDamageDealt;
	}
	return damageDealt;
}

int Warrior::burningStrike()
{
	//Cast a fireball that does between 6 - 9 damage before modifiers
	lastMove = "Burning Strike";

	srand(time(0));

	double accuracy = 90;

	if (getSkill() == "Husteler")
		accuracy *= .8;

	double accuracyRoll = rand() % 100 + 1;

	int minDamage = 5;
	int maxDamage = 8;
	bool missed = false;

	cout << "You enflame your sword and swing at the enemy which";

	if (accuracyRoll >= accuracy)
	{
		cout << " misses. The enemy has evaded your Burning Strike." << endl;
		missed = true;
		damageDealt = 0;
	}
	else
	{
		cout << " lands! Now to see how your strike did!" << endl << endl;

		if (getSkill() == "Gambler")
		{
			damageDealt = (rand() % (static_cast<int>(ceil(maxDamage * 1.2)) + 1 - static_cast<int>(floor(minDamage * .7))) + static_cast<int>(floor(minDamage * .7)));
			if (rand() % 10 <= 2)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Burning Strike does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Burning Strike does " << damageDealt << " damage" << endl;
		}
		else if (getSkill() == "Hustler")
		{
			damageDealt = (rand() % ((static_cast<int>(ceil(maxDamage * 1.2)) + 1 - static_cast<int>(ceil(minDamage * 1.2)))) + static_cast<int>(ceil(minDamage * 1.2)));
			if (rand() % 10 <= 2)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Burning Strike does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Burning Strike does " << damageDealt << " damage" << endl;
		}
		else
		{
			damageDealt = ceil(((rand() % (maxDamage + 1 - minDamage)) + minDamage) * .7);
			if (rand() % 10 <= 2)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Burning Strike does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Burning Strike does " << damageDealt << " damage" << endl;
		}
		if (rand() % 2 == 1 && getWarriorSkill() == "Oppurtunist")
		{
			if (missed == false)
				cout << endl << "A moment of oppurtunity has arisen, time to strike again!" << endl;
			else
				cout << endl << "Amazingly, an opputunity has arisen because of your miss, time to strike!" << endl;
			damageDealt = ceil(((rand() % (maxDamage + 1 - minDamage)) + minDamage) * .7);
			if (rand() % 5 == 0)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Burning Strike does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Burning Strike does " << damageDealt << " damage" << endl;
		}
	}
	return damageDealt;
}