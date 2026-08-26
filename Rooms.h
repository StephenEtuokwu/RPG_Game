#pragma once
#include "Battle.h"

class Rooms : public Battle
{
	public:

		Rooms();

		void Basement(Warrior &temp);
		void Basement(Mage &m);
		void Basement(Alchemist &a);

		void Attic(Warrior& temp);
		void Attic(Mage& m);
		void Attic(Alchemist& a);

		void puzzleRoom(Warrior& temp);
		void puzzleRoom(Mage& m);
		void puzzleRoom(Alchemist& a);

		int getRoomsEncountered();

	private:

		int roomsEncountered;
};