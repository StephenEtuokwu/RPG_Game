#include "Rooms.h"

Rooms::Rooms()
{
	roomsEncountered = 0;
}

void Rooms::Basement(Warrior &temp)
{
	Battle battle;
	srand(time(0));
	int randNum = rand() % 4;
	randNum = 0;
	cout << temp.getName() << " goes ventures into the basement. After going down the creaky stairs, something is sighted in the distance." << endl;
	if (randNum == 0)
	{
		cout << "After closer inspection, it's revealed to be a blade, made of shiny iron. It looks freshly crafted and less dull than your current sword. You pick it up and leave your old sword behind" << endl;
		temp.setWeaponType("Iron Sword");
		cout << "Swinging it around in the darkenes, you can feel that it'll do additional damage to foes when using it (+3 Damage to all Sword Based Moves)" << endl;
		cout << temp.getName() << " leaves the basement and continues their journey with their new Iron Sword!" << endl;
	}
	else
	{
		cout << "It's an enemy, prepare to fight! " << endl;
		battle.startBattle(temp);
	}
	roomsEncountered++;
}
void Rooms::Basement(Mage &temp)
{
	Battle battle;
	srand(time(0));
	int randNum = rand() % 4;
	cout << temp.getName() << " goes ventures into the basement. After going down the creaky stairs, you use your staff to cast a dim light which shines";
	cout << " on something in the distance" << endl;
	if (randNum == 0)
	{
		cout << "After closer inspection, it's revealed to be a long, earthy staff, made of petrified wood. It looks more sturdy than your worn down staff.";
		cout << "You pick it up and leave your old staff behind" << endl;
		temp.setWeaponType("Petrified Staff");
		cout << "Reciting a few spells, you don't feel as tired as you used to beforehand (Spells now use 50% less energy)" << endl;
		cout << temp.getName() << " leaves the basement and continues their journey with their new Petrified Staff!" << endl;
	}
	else
	{
		cout << "It's an enemy, prepare to fight! " << endl;
		battle.startBattle(temp);
	}

	roomsEncountered++;
}
void Rooms::Basement(Alchemist& temp)
{
	Battle battle;
	srand(time(0));
	int randNum = rand() % 4;
	cout << temp.getName() << " goes ventures into the basement. After going down the creaky stairs, you use a potion of night vision to help you see in the dim light." << endl;
	cout << "After a while, you spot something in the distance" << endl;
	if (randNum == 0)
	{
		cout << "After closer inspection, it's revealed to be a new set of flasks. They look better than your current old set.";
		cout << "You toss your flasks and take the new set of flasks" << endl;
		temp.setWeaponType("Splintering Flask");
		cout << "After holding and gripping a new flask, a thin line of blood is drawn. These flasks are really sharp! (Thrown potions now have an additional 2 shrapernal damage)" << endl;
		cout << temp.getName() << " leaves the basement and continues their journey with their new Splintering Flasks" << endl;
	}
	else
	{
		cout << "It's an enemy, prepare to fight! " << endl;
		battle.startBattle(temp);
	}
	roomsEncountered++;
}

void Rooms::Attic(Warrior& temp)
{
	Battle battle;
	srand(time(0));
	int randNum = rand() % 4;
	randNum = 0;
	cout << temp.getName() << " goes ventures into the attic. After going up the creaky stairs, something is sighted in the distance." << endl;
	if (randNum <= 1)
	{
		cout << "After closer inspection, it's revealed to be instructions to preform an echanted move with your sword. It's called Burning Strike." << endl;
		cout << "Burning Strike: If not dodged, you enflame your " << temp.getWeaponName() << " and slash the foe." << endl;
		cout << "Damage 5 - 8 | Accurracy 90% | Critical Hit Chance 30% | Burn Chance 40% | Energy Use: 25" << endl << endl;
		temp.moveListW[2] = "Burning Strike";
		temp.setNewMove("Burning Strike");
		cout << temp.getName() << " leaves the attic and continues their journey with their new move: Burning Strike!" << endl;
	}
	else
	{
		cout << "It's an enemy, prepare to fight! " << endl;
		battle.startBattle(temp);
	}

	roomsEncountered++;
}
void Rooms::Attic(Mage& temp)
{
	Battle battle;
	srand(time(0));
	int randNum = rand() % 4;
	cout << temp.getName() << " goes ventures into the attic. After going up the creaky stairs, you use your staff to cast a dim light which shines";
	cout << " on something in the distance" << endl;
	if (randNum <= 1)
	{
		cout << "After closer inspection, it's revealed to be a scroll with the move name: Thunderclap!" << endl;
		cout << "Thunderclap: If not dodged, you shoot lighting from your " << temp.getWeaponName() << " and electrocute the enemy." << endl;
		cout << "Damage 2 - 6 | Accurracy 85% | Critical Hit Chance 50% | Crit Multiplier: 3x | Energy Use: 30" << endl << endl;
		temp.moveListM[3] = "Thunderclap";
		temp.setNewMove("Thunderclap");
		cout << temp.getName() << " leaves the attic and continues their journey with their new move: Thunderclap!" << endl;
	}
	else
	{
		cout << "It's an enemy, prepare to fight! " << endl;
		battle.startBattle(temp);
	}
	roomsEncountered++;
}
void Rooms::Attic(Alchemist& temp)
{
	Battle battle;
	srand(time(0));
	int randNum = rand() % 4;
	cout << temp.getName() << " goes ventures into the Attic. After going up the creaky stairs, you use a potion of night vision to help you see in the dim light." << endl;
	cout << "After a while, you spot something in the distance" << endl;
	if (randNum == 0)
	{
		cout << "After closer inspection, it's revealed to be a recipie for a more potent verison of Potion Of Damaging (Deals an extra 3 damage, add 10% to poison)" << endl;
		temp.setWeaponType("Potion Of Damaging+");
		cout << temp.getName() << " leaves the attic and continues their journey with their upgraded Potion Of Damaging!" << endl;
	}
	else
	{
		cout << "It's an enemy, prepare to fight!" << endl;
		battle.startBattle(temp);
	}
	roomsEncountered++;
}

void Rooms::puzzleRoom(Warrior& temp)
{
	string guess = "";

	cout << "You run and run and run and run, until you find yourself in strange room. A Shrill voice from an unknown location booms:" << endl;
	cout << "\"Hello there! Solve the puzzle, you're free to leave this illusion-scape, fail to solve this puzzle, and you will be punished""\"" << endl;
	cout << "The puzzle is as follows: Find the sum of all 6 factors of 32" << endl;
	cout << "Sounds easy enough right? Wrong, afterwards take the sqaure root of the sum, then square the sum. Good luck :)" << endl;
	getline(cin,guess);
	while (guess != "63")
	{
		temp.setHP(temp.getHP() - 1);
		if (temp.getHP() == 0)
		{
			cout << "\"I didn't actually think you were going to die due to math, guess you weren't that smart of a warrior after all..\"" << endl;
			cout << "And with that, you've been slain. Your journey comes to an end, please start again" << endl;
			exit(2);
		}
		cout << "\"Oh well, that's not the right answer, try again :)\"" << endl;
		getline(cin,guess);
	}
	
	cout << "\"I'm impressed, you got it right. I guess I will have to let you go then, ta-ta""\"" << endl;
}
void Rooms::puzzleRoom(Mage& temp)
{
	string guess = "";
	cout << "You run and run and run and run, until you find yourself in strange room. A Shrill voice from an unknown location booms:" << endl;
	cout << "\"Hello there! Solve the puzzle, you're free to leave this illusion-scape, fail to solve this puzzle, and you will be punished""\"" << endl;
	cout << "The puzzle is as follows: Find 2 solutions to the equation 2x^2 = 8 (Put a space between your answers)" << endl;
	getline(cin, guess);
	while (guess != "2 -2" && guess != "-2 2")
	{
		temp.setHP(temp.getHP() - 1);
		if (temp.getHP() == 0)
		{
			cout << "\"I didn't actually think you were going to die due to math, guess you weren't that smart of a warrior after all..\"" << endl;
			cout << "And with that, you've been slain. Your journey comes to an end, please start again" << endl;
			exit(2);
		}
		cout << "\"Oh well, that's not the right answer, try again :)\"" << endl;
		getline(cin, guess);
	}
	cout << "\"I'm impressed, you got it right. I guess I will have to let you go then, ta-ta""\"" << endl;
}

void Rooms::puzzleRoom(Alchemist& temp)
{
	string guess = "";
	cout << "You run and run and run and run, until you find yourself in strange room. A Shrill voice from an unknown location booms:" << endl;
	cout << "\"Hello there! Solve the puzzle, you're free to leave this illusion-scape, fail to solve this puzzle, and you will be punished""\"" << endl;
	cout << "The puzzle is as follows: How many even numbers are prime?" << endl;
	while (guess != "1")
	{
		temp.setHP(temp.getHP() - 1);
		if (temp.getHP() == 0)
		{
			cout << "\"I didn't actually think you were going to die due to math, guess you weren't that smart of a warrior after all..\"" << endl;
			cout << "And with that, you've been slain. Your journey comes to an end, please start again" << endl;
			exit(2);
		}
		cout << "\"Oh well, that's not the right answer, try again :)\"" << endl;
		getline(cin,guess);
	}
	cout << "\"I'm impressed, you got it right. I guess I will have to let you go then, ta-ta""\"" << endl;
}