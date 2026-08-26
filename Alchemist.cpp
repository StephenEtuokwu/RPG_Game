#include "Alchemist.h"
#include "Battle.h"

class Battle;

Alchemist::Alchemist()
{
	moveListA = new string[4];

	moveListA[0] = "Potion Of Damaging";
	moveListA[1] = "Potion Of Weakening";
	moveListA[2] = "Potion Of Healing";
	moveListA[3] = "";

	HP = 15;
	energy = 100;
}

void Alchemist::setAlchemistSkill(string s)
{
	alchemistSkill = s;
	skill = s;
}

string Alchemist::getAlchemistSkill()
{
	return alchemistSkill;
}

int Alchemist::getDamageDealt()
{
	return theDamageDealt;
}

void Alchemist::printMoveListA()
{
	for (int k = 0; k < 4; k++)
	{
		if (k != 3)
			cout << moveListA[k] << " | ";
		else
			cout << moveListA[k];
	}
	cout << endl;
}

void Alchemist::printAlchemistSkills()
{
	//Print the Skills Medic Vampiric Academic

	cout << "Medic: Increases healing gained by 50% but reduces damage minimum and maximum damage by 30%" << endl;
	cout << "(Ex: A healing move that usually heals 3 now heals 5, but a move that dealt 5 - 10 damage becomes 4 - 7)" << endl << endl;
	cout << "Vampiric: Convert 30% of damage you do to an enemy into self-healing" << endl;
	cout << "(Ex A 5 - 10 damaging move will heal between 2 - 3 HP" << endl << endl;
	cout << "Academic: Increase Critical Hit Chance by 30% but decrease non-critical damage by 20%" << endl;
	cout << "(Ex: A 5 - 10 damaging move with a 20% to crit now has a 50% chance to crit which would deal 10 - 20 damage or 4 - 8 damaging move if it doesn't crit" << endl << endl;
}

void Alchemist::printAlchemistAttacks()
{
	cout << "You have three main attacks: Potion Of Damage | Potion Of Weakening | Potion of Healing" << endl << endl;
	cout << "Potion Of Damaging: If not dodged, you throw a potion that deals damage to an enemy." << endl;
	cout << "Damage 5 - 7 | Accuracy 85% | Critcal Hit Chance 30% | Energy Use: 20" << endl << endl;
	cout << "Potion of Weakening: If not dodged, you throw a potion of weakening that decreases the enemies damage by 25% " << "." << endl;
	cout << "Damage 1 - 3 | Accurracy 90% | Critical Hit Chance 5% | Energy Use: 15" << endl << endl;
	cout << "Potion Of Healing: You heal between 1 - 8 of your HP (You only can use this once per battle" << endl;
	cout << "Energy Use: 30" << endl << endl;
	cout << "Now for some information about the general battle" << endl;
	cout << "Critical hits do 2x the normal amount of damage that would've happened if the move hadn't crit" << endl << endl;
	cout << "Your max energy is 100, using moves uses up energy. When energy hits 0, you deal only 75% of your total damage and you take 25% more damage" << endl << endl;
	cout << "Your HP and Energy will be replensihed to full after every battle" << endl << endl;
}

void Alchemist::printCondensedAlchemistAttacks()
{
	cout << "Potion Of Damaging: If not dodged, you throw a potion that deals damage to an enemy." << endl;
	cout << "Damage 6 - 8 | Accuracy 85% | Critcal Hit Chance 30% | Energy Use: 20" << endl << endl;
	cout << "Potion Of Weakening: If not dodged, you throw a potion of weakening that decreases the enemies damage by 25% " << "." << endl;
	cout << "Damage 1 - 3 | Accurracy 90% | Critical Hit Chance 5% | Energy Use: 15" << endl << endl;
	cout << "Potion Of Healing: You heal between 1 - 6 of your HP (You only can use this once per battle" << endl;
	cout << "Energy Use: 30" << endl << endl;
}

int Alchemist::potionOfDamaging()
{
	//A move that deals 5 - 7 damage before modifiers

	lastMove = "Potion Of Damaging";

	srand(time(0));
	double accuracy = 85;

	double accuracyRoll = rand() % 100 + 1;
	int damageDealt = 0;

	int minDamage = 5;
	int maxDamage = 7;

	cout << "You threw a Potion of Damaging which";

	if (accuracyRoll > accuracy)
	{
		cout << " misses. The enemy has evaded your Potion Of Damaging" << endl;
		theDamageDealt = 0;
	}
	else
	{
		cout << " lands! Now to see how effective the potion was!" << endl << endl;

		if (getAlchemistSkill() == "Medic")
		{
			damageDealt = (rand() % (static_cast<int>(ceil(maxDamage * .8)) + 1 - static_cast<int>(ceil(minDamage * .8))) + static_cast<int>(ceil(minDamage * .8)));
			if (rand() % 10 < 3)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Potion of Damaging does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Potion of Damaging does " << damageDealt << " damage" << endl;
		}
		else if (getAlchemistSkill() == "Academic")
		{
			damageDealt = rand() % (maxDamage + 1 - minDamage) + minDamage;
			if (rand() % 10 < 6)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Potion of Damaging does " << damageDealt << " damage" << endl;
			}
			else
			{
				damageDealt = ceil(damageDealt * .7);
				cout << "Potion Of Damaging does " << damageDealt << " damage" << endl;
			}
		}
		else
		{
			damageDealt = rand() % (maxDamage + 1 - minDamage) + minDamage;
			if (rand() % 100 + 1 <= 30)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! The Potion of Damaging does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Potion of Damaging does " << damageDealt << " damage" << endl;

			theDamageDealt = damageDealt;
		}
	}
	return theDamageDealt;
}

int Alchemist::potionOfWeakening()
{
	//Throw a potion that deals low damage, but weakens the enemies attack by 25%

	lastMove = "Potion Of Weaking";

	srand(time(0));
	double accuracy = 80;

	double accuracyRoll = rand() % 100 + 1;
	int damageDealt = 0;

	int minDamage = 1;
	int maxDamage = 3;

	cout << "You throw a Potion of Weakening which";
	if (accuracyRoll > accuracy)
	{
		cout << " misses. The enemy has evaded your Potion Of Weakening." << endl;
		theDamageDealt = 0;
	}
	else
	{
		cout << " lands! The enemy is now weakened! Let's see how much damage they take" << endl << endl;
		if (getAlchemistSkill() == "Medic")
		{
			damageDealt = ((rand() % (static_cast<int>(ceil(maxDamage * .7)) + 1 - static_cast<int>(floor(minDamage * .7)))) + static_cast<int>(floor(minDamage * .7)));
			if (rand() % 100 <= 5)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Your Potion of Weakening does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Your Potion of Weakening does " << damageDealt << " damage" << endl;
		}
		else if (getAlchemistSkill() == "Academic")
		{
			damageDealt = rand() % (maxDamage + 1 - minDamage) + minDamage;
			if (rand() % 100 + 1 <= 35)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Potion of Weakening does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Potion of Weakening does " << damageDealt << " damage" << endl;
		}
		else
		{
			damageDealt = rand() % (maxDamage + 1 - minDamage) + minDamage;
			if (rand() % 100 <= 5)
			{
				damageDealt *= 2;
				cout << "A Critical Hit! Potion of Weakening does " << damageDealt << " damage" << endl;
			}
			else
				cout << "Potion of Weakening does " << damageDealt << " damage" << endl;
			if (getHP() < 12)
			{
				cout << "You healed " << (getHP() + ceil(damageDealt * .3)) << endl;
				setHP(getHP() + ceil(damageDealt * .3));
			}
			theDamageDealt = damageDealt;
		}
	}
	if (getWeaponType() == "Splintering Flask")
	{
		cout << "You deal an extra 2 damage with the glass shrapnel! You actually do " << theDamageDealt + 2 << " damage" << endl;
		theDamageDealt += 2;
	}
	return theDamageDealt;
}
void Alchemist::potionOfHealing()
{
	//A Potion that allows the user to Heal 1 - 8 HP, can be used once per battle

	srand(time(0));

	int amountHealed = 0;
	int extraAmountHealed = 0;

	int minHealing = 1;
	int maxHealing = 8;

	if(timesUsed == 0)
	{
		cout << "You've used The Potion of Healing, let's see how much health you recover!" << endl;
		amountHealed = (rand() % (maxHealing - minHealing + 1)) + minHealing;
		if (getAlchemistSkill() == "Medic")
		{
			extraAmountHealed = amountHealed;
			amountHealed = ceil(amountHealed * 1.5);
			extraAmountHealed = amountHealed - extraAmountHealed;
			cout << "Thanks to your Medic skill, you've recovered an additional " << extraAmountHealed << " HP" << endl;
		}
		cout << "You've healed " << amountHealed << " with your Potion Of Healing" << endl;
		cout << "You can no longer use this move, any other attempts will just waste energy." << endl;
		timesUsed++;
		if (getHP() < 12)
			setHP(getHP() + amountHealed);
		if (getHP() > 12)
			setHP(12);
	}
	else
		cout << "You tried to use Potion of Healing, but it failed" << endl;
}