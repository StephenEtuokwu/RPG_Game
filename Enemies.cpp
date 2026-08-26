#include "Enemies.h"

Enemies::Enemies()
{
	srand(time(0));

	int num = rand() % 3;

	if (num == 0)
	{
		//Ranger
		enemyHP = 15;
		enemyName = "Ranger";
		moveList = new string[2];

		moveList[0] = "Shoot Arrow";
		moveList[1] = "Stab";

	}
	else if (num == 1)
	{
		//Skeleton
		enemyHP = 20;
		enemyName = "Skeleton";
		moveList = new string[2];

		moveList[0] = "Bony Barrage";
		moveList[1] = "Bone Bash";
	}
	else if(num == 2)
	{
		//Spider
		enemyHP = 12;
		enemyName = "Spider";
		moveList = new string[2];

		moveList[0] = "String Shot";
		moveList[1] = "Bite";
	}
}

int Enemies::getEnemyHP()
{
	return enemyHP;
}
void Enemies::setEnemyHP(int i)
{
	enemyHP = i;
}

string Enemies::getEnemyName()
{
	return enemyName;
}

void Enemies::setEnemyName(string s)
{
	enemyName = s;
}
int Enemies::getDamageDealt()
{
	return damageDealt;
}

string Enemies::getEnemyMove(int k)
{
	return moveList[k];
}
//Ranger Attacks
void Enemies::shootArrow()
{
	int minDamage = 3;
	int maxDamage = 6;

	int accuracy = 90;
	int accuracyRoll = (rand() % 100) + 1;

	cout << "The Ranger steadies his bow and shoots an arrow at you. The arrow ";
	if (accuracyRoll >= accuracy)
	{
		cout << "misses! You've successfully dodged the arrow." << endl;
		damageDealt = 0;
	}
	else
	{
		cout << "hits. Let's see how much damage you take." << endl;

		damageDealt = (rand() % (maxDamage - minDamage + 1)) + minDamage;
		
		if (rand() % 5 == 0)
		{
			damageDealt *= 2;
			cout << "The arrow scored a critical hit against you" << endl;
		}
		cout << "You take " << damageDealt << " damage from the Ranger's arrow" << endl;
	}
}
void Enemies::stab()
{
	int minDamage = 1;
	int maxDamage = 3;

	cout << "The Ranger unsheathes his dagger and stabs you" << endl;

	damageDealt = (rand() % (maxDamage - minDamage + 1)) + minDamage;

	if (rand() % 3 == 0)
	{
		damageDealt *= 2;
		cout << "The dagger scored a critical hit against you" << endl;
	}
	cout << "You take " << damageDealt << " damage from the Ranger's stabbing" << endl; 
}

//Skeleton Attacks
void Enemies::boneBarrage()
{
	int minDamage = 1;
	int maxDamage = 2;

	int tempDamage = 0;
  
	int accurracy = 85;
	int accurracyRoll = (rand() % 100) + 1;

	damageDealt = 0;

	int numOfBones = 0;
	numOfBones = rand() % 3 + 3;

	cout << "The Skeleton looks to be preparing a move that ";
	if (accurracyRoll >= accurracy)
	{
		cout << "misses. You evade the skeleton's Bone Barrage" << endl;
		damageDealt = 0;
	}
	else
	{
		cout << "hits. The Skeleton begins his Bone Barrage" << endl;
		cout << "Bone Barrage will hit " << numOfBones << " times" << endl;

		for (int k = 1; k <= numOfBones; k++)
		{
			tempDamage = (rand() % (maxDamage - minDamage + 1)) + minDamage;
			if (rand() % 4 == 0)
			{
				tempDamage *= 2;
				cout << "A Critical Hit! ";
			}
			cout << "Bone " << k << " does " << tempDamage << " damage  ";
			damageDealt += tempDamage;
		}
		cout << endl << "The skeleton deals " << damageDealt << " damage with its Bone Barrage" << endl;
	}
}

void Enemies::bonyBash()
{
	int minDamage = 3;
	int maxDamage = 5;

	cout << "The Skeleton lunges at you with a bone club" << endl;

	damageDealt = (rand() % (maxDamage - minDamage + 1)) + minDamage;

	if(rand() % 5 == 0)
	{
		damageDealt *= 2;
		cout << "The bone club scored a critical hit against you" << endl;
	}
	cout << "You take " << damageDealt << " damage from the Skelton's Bony Bash" << endl;
	if (rand() % 3 == 0)
	{
		cout << "Wait, the skeleton's not done yet and strikes you again" << endl;
		damageDealt += ((rand() % (maxDamage - minDamage + 1)) + minDamage)*.5;
		cout << "You actually take " << damageDealt << " damage from the Skelton's Bony Bash" << endl;
	}
}

//Spider Attacks
void Enemies::stringShot()
{
	int minDamage = 2;
	int maxDamage = 4;

	cout << "The Spider shoots out string from its abdomen which ";

	int accurracy = 90;
	int accurracyRoll = (rand() % 100) + 1;

	if (accurracyRoll >= accurracy)
	{
		cout << "misses! You have evaded the Spider's String Shot" << endl;
		damageDealt = 0;
	}
	else
	{
		damageDealt = (rand() % (maxDamage - minDamage + 1)) + minDamage;

		if (rand() %  3 == 0)
		{
			damageDealt *= 2;
			cout << "The String Shot scored a critical hit against you" << endl;
		}
		cout << "You take " << damageDealt << " damage from the Spider's String Shot" << endl;
	}
}
void Enemies::bite()
{
	int minDamage = 1;
	int maxDamage = 3;

	cout << "The Spider reveals its fangs and bites you" << endl;

	damageDealt = (rand() % (maxDamage - minDamage + 1)) + minDamage;

	if (rand() % 3 == 0)
	{
		damageDealt *= 2;
		cout << "The bite scored a critical hit against you" << endl;
	}
	cout << "You take " << damageDealt << " damage from the Spider's bite" << endl;
}

void Enemies::dragonClaw()
{
	int minDamage = 3;
	int maxDamage = 6;

	cout << "The Dragon uncleanches it's fists and slashes at you with it's sharp claws" << endl;

	damageDealt = (rand() % (maxDamage - minDamage + 1)) + minDamage;

	if (rand() % 4 == 0)
	{
		damageDealt *= 2;
		cout << "The Dragon Claw scored a critical hit against you" << endl;
	}
	cout << "You take " << damageDealt << " damage from the Dragon Claw " << endl;
}
void Enemies::flameBreath()
{
	int minDamage = 2;
	int maxDamage = 6;

	cout << "The Dragon shoots a stream of hot flames which ";

	int accurracy = 90;
	int accurracyRoll = (rand() % 100) + 1;

	if (accurracyRoll >= accurracy)
	{
		cout << "misses! You have evaded the dragon's Flame Breath" << endl;
		damageDealt = 0;
	}
	else
	{
		cout << "hits." << endl;
		damageDealt = (rand() % (maxDamage - minDamage + 1)) + minDamage;
		if (rand() % 5 == 0)
		{
			damageDealt *= 2;
			cout << "The Flame Breath scored a critical hit against you" << endl;
		}
		cout << "You take " << damageDealt << " damage from the Dragon's Flame Breath" << endl;
	}
}