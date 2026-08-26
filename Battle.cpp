#include "Battle.h"
#include <cctype>

Battle::Battle()
{
	playerRoll = 0;
	enemyRoll = 0;
}

void Battle::startBattle(CharacterClass c)
{
	e = Enemies();

	if (c.getEndGame())
	{
		e.setEnemyHP(30);
		e.setEnemyName("Dragon");
		e.moveList = new string[2];

		e.moveList[0] = "Dragon Claw";
		e.moveList[1] = "Flame Breath";
	}

	srand(time(0));
	playerRoll = rand() % 20 + 1;
	enemyRoll = rand() % 20 + 1;

	cout << "What's this? You've encountered a " << e.getEnemyName() << "! Let the battle between " << c.getName() << " and " << e.getEnemyName() << " commnece!" << endl;
	cout << "Whoever gets closer to 20 get gets to go first " << endl << endl;
	cout << "Your roll: " << playerRoll << endl;
	cout << "Enemy roll: " << enemyRoll << endl << endl;

	if (playerRoll > enemyRoll)
	{
		cout << "Your initiative roll of " << playerRoll << " beats out the enemy's roll of " << enemyRoll << "!" << endl;
		userTurn(c);
	}
	else if (playerRoll == enemyRoll)
	{
		while (playerRoll == enemyRoll)
		{
			cout << "Oh what luck, you and the enemy have tied! Time to reroll!" << endl;
			playerRoll = rand() % 20 + 1;
			enemyRoll = rand() % 20 + 1;
			cout << "Your roll: " << playerRoll << endl;
			cout << "Enemy roll: " << enemyRoll << endl << endl;
		}
		if (playerRoll > enemyRoll)
		{
			cout << "Your initiative roll of " << playerRoll << " beats out the enemy's roll of " << enemyRoll << "! What action will you take?" << endl <<endl;
			userTurn(c);
		}
		else
		{
			cout << "Your initiative roll of " << playerRoll << " loses to the enemy's roll of " << enemyRoll << ". The enemy will now attack you" << endl << endl;
			enemyTurn(c);
		}
	}
	else
	{
		cout << "Your initiative roll of " << playerRoll << " loses to the enemy's roll of " << enemyRoll << ". The enemy will now attack you" << endl << endl;
		enemyTurn(c);
	}
}

void Battle::endBattle(CharacterClass c)
{
	if (c.getHP() <= 0)
	{
		cout << "And with that last hit, you have failed to finish your quest. Please the game over from the beginning or your last save." << endl;
		exit(2);
	}
	else if (e.getEnemyHP() <= 0)
		cout << "And with that last hit, you've slain the " << e.getEnemyName() << "!" << endl;
	return;
}
void Battle::enemyTurn(CharacterClass c)
{
	srand(time(0));

	if (c.getHP() <= 0)
		endBattle(c);
	if (e.getEnemyHP() <= 0)
		endBattle(c);
	else
	{
		cout << "It's now enemy " << e.getEnemyName() << "'s turn to attack" << endl << endl;
		int num = rand() % 2;

		if (e.getEnemyMove(num) == "Shoot Arrow")
			e.shootArrow();
		else if (e.getEnemyMove(num) == "Stab")
			e.stab();
		else if (e.getEnemyMove(num) == "Bony Barrage")
			e.boneBarrage();
		else if (e.getEnemyMove(num) == "Bone Bash")
			e.bonyBash();
		else if (e.getEnemyMove(num) == "String Shot")
			e.stringShot();
		else if(e.getEnemyMove(num) == "Bite")
			e.bite();
		else if (e.getEnemyMove(num) == "Dragon Claw")
			e.dragonClaw();
		else if (e.getEnemyMove(num) == "Flame Breath")
		{
			e.flameBreath();
			if(rand() % 5 == 0 && userBurned == false)
			{
				userBurned = true;
				cout << "The Flame Breath has burned you, you will be take 1 damage at the end of your turn and you will deal 25% less damage" << endl;
			}
		}
		if (enemyBurned || enemyWeakened)
			c.setHP(ceil(c.getHP() - (e.getDamageDealt() * .75)));
		else if(c.getEnergy() < 0)
			c.setHP(ceil(c.getHP() - (e.getDamageDealt() * 1.25)));
		else if (c.getSkill() == "Etheral")
		{
			int randNum = rand() % 3;
			if (randNum == 0)
			{
				c.setHP(c.getHP() - (e.getDamageDealt() * .5));
				cout << "Thanks to your Etheral Skill, you only take " << e.getDamageDealt() * .5;
			}
			else
				c.setHP(c.getHP() - e.getDamageDealt());
		}
		else
		  c.setHP(ceil(c.getHP() - e.getDamageDealt()));

		if (enemyPoisoned)
		{
			e.setEnemyHP(e.getEnemyHP() - 3);
			cout << "Enemy took 3 damage from the poison" << endl;
			cout << e.getEnemyHP() << endl;
		}
		if (enemyBurned)
		{
			e.setEnemyHP(e.getEnemyHP() - 1);
			cout << "Enemy took 1 damage from the burn" << endl;
		}

		cout << endl << "Your HP: " << c.getHP() << endl << endl;

		userTurn(c);
	}
}

void Battle::userTurn(CharacterClass c)
{
	if (e.getEnemyHP() <= 0)
		endBattle(c);
	if (c.getHP() <= 0)
		endBattle(c);
	else
	{
		string currMove;
		cout << c.getName() << ", what move do you want to use?" << endl << endl;
		if (c.getClassType() == "Warrior")
		{
			Warrior temp;

			temp.setHP(c.getHP());
			temp.setSkill(c.getSkill());
			string s = c.getNewMove();
			temp.moveListW[2] = s;

			getline(cin, currMove);
			while (temp.inMoveListW(currMove) == false)
			{
				cout << "Please select from the following moves: ";
				printMoveListW();
				if (temp.moveListW[2] != "")
					cout << " | " << temp.moveListW[2] << endl;
				else
					cout << endl;
				getline(cin, currMove);
			}

			if (currMove == "Fists Of Fury")
			{
				int damage = temp.fistsOfFury();
				if (userBurned || c.getEnergy() <= 0)
					e.setEnemyHP(e.getEnemyHP() - ceil((damage * .75)));
				else
					e.setEnemyHP(e.getEnemyHP() - damage);
				c.setEnergy(c.getEnergy() - 10);
				cout << "You now have " << c.getEnergy() << " energy after using Fists Of Fury" << endl;

			}
			else if (currMove == "Double Slash")
			{
				int damage = temp.doubleSlash();
				if (c.getWeaponType() == "Iron Sword" && damage != 0)
				{
					cout << "You deal an additonal 3 damage with your Iron Sword!" << endl;
					damage += 3;
				}
				if (userBurned || c.getEnergy() <= 0)
					e.setEnemyHP(e.getEnemyHP() - ceil((damage * .75)));
				else
					e.setEnemyHP(e.getEnemyHP() - damage);
				c.setEnergy(c.getEnergy() - 20);
				cout << "You now have " << c.getEnergy() << " energy after using Double Slash" << endl;
			}
			else if (currMove == "Burning Strike")
			{
				int statusChance = rand() % 10;
				int damage = temp.burningStrike();
				if (c.getWeaponType() == "Iron Sword" && damage != 0)
				{
					cout << "You deal an additonal 3 damage with your Iron Sword!" << endl;
					damage += 3;
				}
				if (userBurned || c.getEnergy() <= 0)
					e.setEnemyHP(e.getEnemyHP() - ceil((damage * .75)));
				else
					e.setEnemyHP(e.getEnemyHP() - damage);
				c.setEnergy(c.getEnergy() - 25);
				cout << "You now have " << c.getEnergy() << " energy after Burning Strike" << endl;
				if (statusChance < 4 && enemyBurned == false)
				{
					enemyBurned = true;
					cout << endl << "Your Burning Strike has burned the enemy! They will now take 1 damage at the end of their turn and will deal 25% less damage for the rest of the battle" << endl;
				}
			}
			if (e.getEnemyHP() < 0)
			{
				cout << " Overkill by " << (0 - e.getEnemyHP()) << " damage!" << endl;
				e.setEnemyHP(0);
			}
			cout << endl << "Enemy HP: " << e.getEnemyHP() << endl;

		}
		else if (c.getClassType() == "Mage")
		{
			Mage temp;
			temp.setSkill(c.getSkill());
			int statusChance = rand() % 10;
			string s = c.getNewMove();
			temp.moveListM[3] = s;
			getline(cin, currMove);
			while (temp.inMoveListM(currMove) == false && currMove != "Thunderclap")
			{
				cout << "Please select from the following moves: ";
				printMoveListM();
				if (temp.moveListM[3] != "")
					cout << " | " << temp.moveListM[3] << endl;
				else
					cout << endl;
				getline(cin, currMove);
			}
			if (currMove == "Fireball")
			{
				if(userBurned || c.getEnergy() <= 0)
					e.setEnemyHP(e.getEnemyHP() - ceil((temp.fireball()*.75)));

				else
					e.setEnemyHP(e.getEnemyHP() - temp.fireball());

				if (temp.getSkill() == "Elemental")
				{
					if (statusChance <= 5 && enemyBurned == false)
					{
						enemyBurned = true;
						cout << endl << "Your Fireball has burned the enemy! They will now take 1 damage at the end of their turn and will deal 25% less damage for the rest of the battle" << endl;
					}
				}
				else if (temp.getSkill() == "Etheral")
				{
					if (statusChance <= 2 && enemyBurned == false)
					{
						enemyBurned = true;
						cout << endl << "Your Fireball has burned the enemy! They will now take 1 damage at the end of their turn and will deal 25% less damage for the rest of the battle" << endl;
					}
				}

				if (c.getWeaponType() == "Petrified Staff")
					c.setEnergy(c.getEnergy() - 5);
				else
					c.setEnergy(c.getEnergy() - 10);
				cout << endl << "You now have " << c.getEnergy() << " energy after using Fireball" << endl;
			}
			else if (currMove == "Poison Spray")
			{
				if(userBurned || c.getEnergy() <= 0)
					e.setEnemyHP(e.getEnemyHP() - ceil((temp.poisonSpray()*.75)));					
				else
					e.setEnemyHP(e.getEnemyHP() - temp.poisonSpray());

				if (temp.getSkill() == "Elemental")
				{
					if (statusChance <= 3 && enemyPoisoned == false)
					{
						enemyPoisoned = true;
						cout << endl << "Your Poison Spray has poisoned the enemy! They will now take 3 damage at the end of their turn for the rest of battle" << endl;
					}
				}
				else if (temp.getSkill() == "Etheral")
				{
					if (statusChance <= 1 && enemyPoisoned == false)
					{
						enemyPoisoned = true;
						cout << endl << "Your Poison Spray has poisoned the enemy! They will now take 3 damage at the end of their turn for the rest of battle" << endl;
					}
				}
				if (c.getWeaponType() == "Petrified Staff")
					c.setEnergy(c.getEnergy() - 10);
				else
					c.setEnergy(c.getEnergy() - 20);
				cout << endl << "You now have " << c.getEnergy() << " energy after using Poison Spray" << endl;

			}
			else if (currMove == "Magic Missile")
			{
				if(userBurned || c.getEnergy() <= 0)
					e.setEnemyHP(e.getEnemyHP() - ceil((temp.magicMissile()*.75)));
				else
					e.setEnemyHP(e.getEnemyHP() - temp.magicMissile());
				if (c.getWeaponType() == "Petrified Staff")
					c.setEnergy(c.getEnergy() - 20);
				else
					c.setEnergy(c.getEnergy() - 40);
				cout << endl << "You now have " << c.getEnergy() << " energy after using Magic Missile" << endl;
			}
			else if (currMove == "Thunderclap")
			{
				if(userBurned || c.getEnergy() <= 0)
					e.setEnemyHP(e.getEnemyHP() - ceil(temp.thunderclap() *.75));
				else
					e.setEnemyHP(e.getEnemyHP() - temp.thunderclap());
				if (c.getWeaponType() == "Petrified Staff")
					c.setEnergy(c.getEnergy() - 15);
				else
					c.setEnergy(c.getEnergy() - 30);
				cout << endl << "You now have " << c.getEnergy() << " energy after using Thunderclap" << endl;
			}
			if (e.getEnemyHP() < 0)
			{
				cout << " Overkill by " << (0 - e.getEnemyHP()) << " damage!" << endl;
				e.setEnemyHP(0);
			}
			cout << endl << "Enemy HP: " << e.getEnemyHP() << endl;
		}
		else if (c.getClassType() == "Alchemist")
		{
			Alchemist temp;
			temp.setSkill(c.getSkill());
			getline(cin, currMove);
			while (currMove != "Potion Of Damaging" && currMove != "Potion Of Weakening" && currMove != "Potion Of Healing")
			{
				cout << "Please select from the following moves: ";
				printMoveListA();
				cout << endl;
				getline(cin, currMove);
			}
			if (currMove == "Potion Of Damaging")
			{
				int damage = temp.potionOfDamaging();
				if (c.getWeaponType() == "Potion Of Damaging+" && damage != 0)
				{
					cout << "You deal an extra 3 damage with the more potent potion! You actually do " << damage + 3 << " damage" << endl;
					damage += 3;
				}
				if (c.getWeaponType() == "Splintering Flask" && damage != 0)
				{
					if (rand() % 10 == 0 && enemyPoisoned == false)
					{
						cout << "Your more potent Potion Of Damaging poisoned the enemy! They will be taking 3 damage at the end of their turn for the rest of the battle" << endl;
						enemyPoisoned = true;
						cout << "You deal an extra 2 damage with the glass shrapnel! You actually do " << damage + 2 << " damage" << endl;
						damage += 3;
					}
					if(userBurned || c.getEnergy() <= 0)
						e.setEnemyHP(e.getEnemyHP() - ceil(damage*.75));
					else
						e.setEnemyHP(e.getEnemyHP() - damage);
					if (temp.getSkill() == "Vampiric" && damage != 0 && c.getHP() != 12)
					{
						c.setHP(c.getHP() + ceil(damage * .3));
						cout << "You healed " << ceil(damage * .3) << " HP which brings you to " << c.getHP() << " HP" << endl;
						if (c.getHP() > 12)
						{
							cout << "You're over your max HP of 12, setting it back down to 12" << endl << endl;
							c.setHP(12);
						}
					}
					c.setEnergy(c.getEnergy() - 20);
					cout << "You now have " << c.getEnergy() << " energy after using Potion Of Damaging" << endl;
				}
				else if (currMove == "Potion Of Weakening")
				{
					int damage = temp.potionOfWeakening();
					if (c.getWeaponType() == "Potion Of Damaging+" && damage != 0)
					{
						cout << "You deal an extra 3 damage with the more potent potion! You actually do " << damage + 3 << " damage" << endl;
						damage += 3;
					}
					if (c.getWeaponType() == "Splintering Flask" && damage != 0)
					{
						cout << "You deal an extra 2 damage with the glass shrapnel! You actually do " << damage + 2 << " damage" << endl;
						damage += 3;
					}
					if (userBurned || c.getEnergy() <= 0)
						e.setEnemyHP(e.getEnemyHP() - ceil(damage * .75));
					else
						e.setEnemyHP(e.getEnemyHP() - damage);
					if (damage != 0 && enemyWeakened == false)
						enemyWeakened = true;

					if (temp.getSkill() == "Vampiric" && damage != 0 && c.getHP() != 12)
					{
						c.setHP(c.getHP() + ceil(damage * .3));
						cout << "You healed " << ceil(damage * .3) << " HP which brings you to " << c.getHP() << " HP" << endl;
						if (c.getHP() > 12)
						{
							cout << "You're over your max HP of 12, setting it back down to 12" << endl << endl;
							c.setHP(12);
						}
					}
					c.setEnergy(c.getEnergy() - 15);
					cout << "You now have " << c.getEnergy() << " energy after using Potion Of Weakening" << endl;
				}
				else
				{
					temp.potionOfHealing();
					c.setEnergy(c.getEnergy() - 30);
					cout << "You now have " << c.getEnergy() << " energy after using Potion Of Healing" << endl;
				}
				if (e.getEnemyHP() < 0)
				{
					cout << " Overkill by " << (0 - e.getEnemyHP()) << " damage!" << endl;
					e.setEnemyHP(0);
				}
				cout << endl << "Enemy HP: " << e.getEnemyHP() << endl;
			}
		}
	}
	if (userBurned)
	{
		cout << "You take 1 damage from the burn" << endl;
		c.setHP(c.getHP() - 1);
	}
	enemyTurn(c);
}