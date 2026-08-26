#include "Mage.h"
#include "Battle.h"

Mage::Mage()
{
	moveListM = new string[4];

	moveListM[0] = "Fireball";
	moveListM[1] = "Poison Spray";
	moveListM[2] = "Magic Missile";
	moveListM[3] = "";

	HP = 15;
	energy = 100;
}

bool Mage::inMoveListM(string s)
{
	for (int k = 0; k < 3; k++)
	{
		if (moveListM[k] == s)
			return true;
	}
	return false;
}

void Mage::setMageSkill(string s)
{
	mageSkill = s;
	skill = s;
}

string Mage::getMageSkill()
{
	return mageSkill;
}

int Mage::getDamageDealt()
{
	return theDamageDealt;
}

void Mage::printMoveListM()
{
	for (int k = 0; k < 4; k++)
	{
		if (k != 3)
			cout << moveListM[k] << " | ";
		else
			cout << moveListM[k];
	}
}

void Mage::printMageSkills()
{
	//Print the Skills Elemental Etheral Maximal

	cout << "Elemental: Doubles the chances of a status effects but decreases the minimum and maximus damage rolls by 20% " << endl;
	cout << "(Ex: A 5 - 10 damage roll with a 20% chance to poison becomes 4 - 12 damge roll with a 40% to poison) (Elemental has the minimum damage roll round down, maximum damage roll round up)" << endl << endl;
	cout << "Etheral: When taking damage, have a 25% chance to take half damage " << endl;
	cout << "(Ex If you're suppossed to take 8 damage, you have a 25% chance to only take 4 damage)" << endl << endl;
	cout << "Maximmal: Increases minimum and maximum damage rolls by 30% but removes all additional effects from the attack (excluding critical hits)" << endl;
	cout << "(Ex: A 5 - 10 damage roll with a 20% chance to poison becomes a 7 - 13 damage roll that has a 0% to poison)" << endl << endl;
}

void Mage::printMageAttacks()
{
	cout << "You have three main attacks: Fireball | Poison Spray | Magic Missle" << endl << endl; 
	cout << "Fireball: If not dodged, you cast a fireball from your " << getWeaponName() << endl;
	cout << "Damage 6 - 9 | Accuracy 90% | Critcal Hit Chance 20% | Burn Chance 30% | Energy Use: 10" << endl << endl;
	cout << "Poison Spray: If not dodged, you launch 3 volleys of poison from your " << getWeaponName() << "." << endl;
	cout << "Damage (per volley) 2 - 4 | Accurracy 80% | Critical Hit Chance (per volley) 10% | Poison Chance 20% | Energy Use: 20" << endl << endl;
	cout << "Magic Missle: If not dodged, you summon magic missiles using your " << getWeaponName() << ", that can launch between 2 - 4 times." << endl;
	cout << "Damage 4 - 6 (per missile) | Accurracy 70% | Critical Hit Chance 40% (per missle) | Energy Use: 40" << endl << endl;
	cout << "Now for some information about the general battle" << endl;
	cout << "Critical hits do 2x the normal amount of damage that would've happened if the move hadn't crit" << endl << endl;
	cout << "Your max energy is 100, using moves uses up energy. When energy hits 0, you deal only 75% of your total damage and you take 25% more damage" << endl << endl;
	cout << "Your HP and Energy will be replensihed to full after every battle" << endl << endl;
}

void Mage::printCondensedMageAttacks()
{
	cout << "You have three main attacks: Fireball | Poison Spray | Magic Missle" << endl << endl;
	cout << "Fireball: If not dodged, you cast a fireball from your " << getWeaponType() << endl;
	cout << "Damage 6 - 9 | Accuracy 90% | Critcal Hit Chance 20% | Burn Chance 30% | Energy Use: 10" << endl << endl;
	cout << "Poison Spray: If not dodged, you launch 3 volleys of poison from your " << getWeaponType() << "." << endl;
	cout << "Damage (per volley) 2 - 4 | Accurracy 80% | Critical Hit Chance (per volley) 10% | Poison Chance 20% (per volley) | Energy Use: 20" << endl << endl;
	cout << "Magic Missle: If not dodged, you summon magic missiles using your " << getWeaponType() << ", that can launch between 2 - 4 times." << endl;
	cout << "Damage 4 - 6 (per missle)| Accurracy 70% | Critical Hit Chance 40% (per missle) | Energy Use: 40" << endl << endl;
}


int Mage::fireball()
{
	//Cast a fireball that does between 6 - 9 damage before modifiers

	lastMove = "Fireball";

	srand(time(0));

	int statusChance = 20;
	double accuracy = 90;

	double accuracyRoll = rand() % 100 + 1;

	int minDamage = 6;
	int maxDamage = 9;


	cout << "You cast Fireball which";

	if (accuracyRoll >= accuracy)
	{
		cout << " misses. The enemy has evaded your Fireball." << endl;
		damageDealt = 0;
	}
	else
	{
		cout << " lands! Now to see how your Fireball did!" << endl << endl;

		if (getSkill() == "Elemental")
		{
			damageDealt = (rand() % (static_cast<int>(ceil(maxDamage * .8)) + 1 - static_cast<int>(floor(minDamage * .8))) + static_cast<int>(floor(minDamage * .8)));
			if (rand() % 5 == 0)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Fireball does " << damageDealt << " damage";
			}
			else
				cout << "Fireball does " << damageDealt << " damage";
		}
		else if (getSkill() == "Maximal")
		{
			damageDealt = (rand() % ((static_cast<int>(ceil(maxDamage * 1.2)) + 1 - static_cast<int>(ceil(minDamage * 1.2)))) + static_cast<int>(ceil(minDamage * 1.2)));
			if (rand() % 5 == 0)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Fireball does " << damageDealt << " damage";
			}
			else
				cout << "Fireball does " << damageDealt << " damage";
		}
		else
		{
			damageDealt = (rand() % (maxDamage + 1 - minDamage ) + minDamage );
			if (rand() % 5 == 0)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Fireball does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Fireball does " << damageDealt << " damage" << endl;
		}
	}
	return damageDealt;
}
int Mage::poisonSpray()
{
	lastMove = "Poison Spray";

	srand(time(0));
	double accuracy = 80;

	double accuracyRoll = rand() % 100 + 1;
	int totalDamageDealt = 0;
	int tempDamageDealt = 0;
	int numSpray = 1;

	int minDamage = 2;
	int maxDamage = 4;

	cout << "You use Poison Spray which";
	if (accuracyRoll >= accuracy)
	{
		cout << " misses. The enemy has evaded your Poison Spray." << endl;
		damageDealt = 0;
	}
	else
	{
		cout << " lands! Now to see how your spray lands!" << endl << endl;

		for (int k = 0; k < 3; k++)
		{
			if (getSkill() == "Elemental")
			{
				tempDamageDealt = (rand() % (static_cast<int>(ceil(maxDamage * .8)) + 1 - static_cast<int>(floor(minDamage*.8))) + static_cast<int>(floor(minDamage * .8)));
				if (rand() % 10 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Spray " << numSpray << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Spray " << numSpray << " does " << tempDamageDealt << " damage  ";
				}
			}
			else if (getMageSkill() == "Maximal")
			{
				tempDamageDealt = (rand() % ((static_cast<int>(ceil(maxDamage * 1.2)) + 1 - static_cast<int>(ceil(minDamage * 1.2)))) + static_cast<int>(ceil(minDamage * 1.2)));
				if (rand() % 10 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Spray " << numSpray << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Spray " << numSpray << " does " << tempDamageDealt << " damage  ";
				}
			}
			else
			{
				tempDamageDealt = (rand() % (maxDamage + 1 - minDamage)) + minDamage;
				if (rand() % 10 == 0)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					cout << "A Critical Hit! Spray " << numSpray << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					cout << "Spray " << numSpray << " does " << tempDamageDealt << " damage  ";
				}
			}
			numSpray++;
		}
		cout << "You did a total of " << totalDamageDealt << " damage with your Poison Spray!" << endl;
		damageDealt = totalDamageDealt;
	}
	return damageDealt;
}
int Mage::magicMissile()
{
	//Cast between 3-5 magical missles that each deal 4-6 Damage

	lastMove = "Magic Missle";

	srand(time(0));
	double accuracy = 70;

	double accuracyRoll = rand() % 100 + 1;
	int totalDamageDealt = 0;
	int tempDamageDealt = 0;


	int numMagicMissles = 0;
	int numMagicMissle = 1;

	int minDamage = 4;
	int maxDamage = 6;

	cout << "You cast Magic Missles which ";
	if (accuracyRoll > accuracy)
	{
		cout << "misses. The enemy has evaded your Magic Missles." << endl;
		damageDealt = 0;
	}
	else
	{
		cout << "hits! Let's see how many missles you summoned" << endl;
		numMagicMissles = rand() % 3 + 3;
		cout << "You've summoned " << numMagicMissles << " missles! Let's see how they land" << endl;
		for (int k = 0; k < numMagicMissles; k++)
		{
			if (getSkill() == "Elemental")
			{
				tempDamageDealt = (rand() % (static_cast<int>(ceil(maxDamage * .8)) + 1 - static_cast<int>(floor(minDamage*.8))) + static_cast<int>(floor(minDamage * .8)));
				if (((rand() % 100) + 1) <= 40)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					if (numMagicMissle == 4)
						cout << endl;
					cout << "A Critical Hit! Magic Missle " << numMagicMissle << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					if (numMagicMissle == 4)
						cout << endl;
					cout << "Magic Missle " << numMagicMissle << " does " << tempDamageDealt << " damage  ";
				}
			}
			else if (getSkill() == "Maximal")
			{
				tempDamageDealt = (rand() % (static_cast<int>(ceil(maxDamage * 1.2)) + 1 - static_cast<int>(ceil(minDamage*1.2))) + static_cast<int>(ceil(minDamage*1.2)));
				if (((rand() % 100) + 1) <= 40)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					if (numMagicMissle == 4)
						cout << endl;
					cout << "A Critical Hit! Magic Missle " << numMagicMissle << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					if (numMagicMissle == 4)
						cout << endl;
					cout << "Magic Missle " << numMagicMissle << " does " << tempDamageDealt << " damage  ";
				}
			}
			else
			{
				tempDamageDealt = (rand() % (maxDamage + 1 - minDamage)) + minDamage;
				if (((rand() % 100) + 1) <= 40)
				{
					tempDamageDealt *= 2;
					totalDamageDealt += tempDamageDealt;
					if (numMagicMissle == 4)
						cout << endl;
					cout << "A Critical Hit! Magic Missle " << numMagicMissle << " does " << tempDamageDealt << " damage  ";
				}
				else
				{
					totalDamageDealt += tempDamageDealt;
					if (numMagicMissle == 4)
						cout << endl;
					cout << "Magic Missle " << numMagicMissle << " does " << tempDamageDealt << " damage  ";
				}
			}
			numMagicMissle++;
		}		
		cout << endl << "You did a total of " << totalDamageDealt << " points of damage with your Magic Missiles!" << endl;
		damageDealt = totalDamageDealt;
	}
	return damageDealt;
}

int Mage::thunderclap()
{
	//Cast a small thunderclap that deals 2 - 6 damage with a high critical hit ratio and extra Critical Hit Damage

	lastMove = "Thunderclap";

	srand(time(0));

	double accuracy = 85;

	double accuracyRoll = rand() % 100 + 1;

	int minDamage = 2;
	int maxDamage = 6;


	cout << "You cast Thunderclap which";

	if (accuracyRoll >= accuracy)
	{
		cout << " misses. The enemy has evaded your Thunderclap." << endl;
		damageDealt = 0;
	}
	else
	{
		cout << " lands! Now to see how your Thunderclap did!" << endl << endl;

		if (getSkill() == "Elemental")
		{
			damageDealt = (rand() % (static_cast<int>(ceil(maxDamage * .8)) + 1 - static_cast<int>(floor(minDamage * .8))) + static_cast<int>(floor(minDamage * .8)));
			if (rand() % 2 == 0)
			{
				damageDealt *= 3;
				cout << "A Critical Hit! Thunderclap does " << damageDealt << " damage";
			}
			else
				cout << "Thunderclap does " << damageDealt << " damage";
		}
		else if (getSkill() == "Maximal")
		{
			damageDealt = (rand() % ((static_cast<int>(ceil(maxDamage * 1.2)) + 1 - static_cast<int>(ceil(minDamage * 1.2)))) + static_cast<int>(ceil(minDamage * 1.2)));
			if (rand() % 5 == 0)
			{
				damageDealt *= 3;
				cout << "A Critical Hit! Thunderclap does " << damageDealt << " damage";
			}
			else
				cout << "Thunderclap does " << damageDealt << " damage";
		}
		else
		{
			damageDealt = (rand() % (maxDamage + 1 - minDamage) + minDamage);
			if (rand() % 2 == 0)
			{
				damageDealt *= 3;
				cout << "A Critical Hit! Thunderclap does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Thunderclap does " << damageDealt << " damage" << endl;
		}
	}
	return damageDealt;
}