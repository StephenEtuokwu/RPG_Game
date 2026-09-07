#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

#include "Warrior.h"
#include "Mage.h"
#include "Alchemist.h"
#include "Battle.h"
#include "Enemies.h"
#include "Rooms.h"
#include "CharacterClass.h"
#include "Classes.h"


void saveCharacter(CharacterClass& character) 
{
    ofstream file("SaveFile");
    file << "Class: " << character.getClassType() << endl;
    file << "Name: " << character.getName() << endl;
    file << "Weapon Name: " << character.getWeaponName() << endl;
    file << "Weapon Type: " << character.getWeaponType() << endl;
    file << "Skill: " << character.getSkill() << endl;
    file << "Area: " << character.getArea() << endl;
    file.close();
}

void loadCharacter(CharacterClass& character) 
{
    ifstream file("SaveFile");
    string line;
    while (getline(file, line)) 
    {
        if (!line.empty() && line[0] == 'C')
            character.setClassType(line.substr(line.find(":") + 2));
        if (!line.empty() && line[0] == 'N')
            character.setName(line.substr(line.find(":") + 2));
        if (line.find("Weapon Name") != string::npos)
            character.setWeaponName(line.substr(line.find(": ") + 2));
        if (line.find("Weapon Type") != string::npos)
            character.setWeaponType(line.substr(line.find(": ") + 2));
        if (!line.empty() && line[0] == 'S')
            character.setSkill(line.substr(line.find(":") + 2));
        if (!line.empty() && line[0] == 'A')
            character.setArea(line.substr(line.find(":") + 2));
    }

    if (character.getClassType() == "Warrior")
        character.setHP(20);
    else
        character.setHP(15);
    file.close();
}

int main()
{
    string userName;
    string userClass;
    string userWeapon;
    string userSkill;
    string confirmSkill;
    string testMove;
    string roomChoice = "";
    string illusionChoice = "";
    string choice;
    string area = "";

    CharacterClass theUser;
    Warrior w;
    w.setHP(0);
    Mage m;
    m.setHP(0);
    Alchemist a;
    a.setHP(0);

    Battle battle;
    Rooms room;

    cout << "Make sure to play this on full screen!!!" << endl;
    ifstream file("SaveFile");
    string line;
    
    getline(file, line);
    file.close();

    if (!line.empty())
    {
        cout << "It appears you have a character saved, loading previous save..." << endl;
        if (line.find("Class: Warrior") != string::npos)
        {
            loadCharacter(w);
            userName = w.getName();
        }
        else if (line.find("Class: Mage") != string::npos)
        {
            loadCharacter(m);
            userName = m.getName();
        }
        else if (line.find("Class: Alchemist") != string::npos)
        {
            loadCharacter(a);
            userName = a.getName();
        }
    }
    else
    {
        cout << "Welcome...erm....This is embarissing, what was your name again?" << endl;
        
        getline(cin, userName);

        while (userName.length() < 3 || userName.length() > 16)
        {
            if (userName.length() < 3)
            {
                cout << "I'm pretty sure it was longer than that, please tell me your actual name" << endl;
                getline(cin, userName);
            }
            else
            {
                cout << "I'm pretty sure it was shorter than that, please tell me your actual name" << endl;
                getline(cin, userName);
            }
        }
        theUser.setName(userName);
        cout << "Ah that's right, " + theUser.getName() + " How can I forget. " + theUser.getName() + " the...ummm...the...Sorry, I forgot your title, can you help me remember?" << endl;
        cout << "Was it Warrior, Mage, or Alchemist? " << endl;
        getline(cin, userClass);
        while (userClass != "Warrior" && userClass != "Mage" && userClass != "Alchemist")
        {
            cout << "Oh come on now, I can faintly recall that you were either a Warrior Mage or Alchemist" << endl;
            getline(cin, userClass);
        }
        theUser.setClassType(userClass);

        if (theUser.getClassType() == "Warrior")
        {
            cout << "That's right, you were a " << theUser.getClassType() << ", a good one too! You weilded a...the...what was the name of your sword again?" << endl;
            
            getline(cin, userWeapon);
            while (userWeapon.length() < 3 || userWeapon.length() > 15)
            {
                if (userWeapon.length() < 3)
                {
                    cout << "No that can't be it, a sword as mighty as yours has a much cooler, longer name than " << userWeapon << endl;
                    getline(cin, userWeapon);
                }
                else
                {
                    cout << "Woah there, that's quite the mouthful, mind shortening that? Or perhaps it was another, shorter name" << endl;
                    getline(cin, userWeapon);
                }
            }
            Warrior user;
            user.setName(userName);
            user.setClassType(userClass);
            theUser.setWeaponName(userWeapon);
            user.setWeaponName(userWeapon);
            user.setWeaponType("Basic");

            cout << "That's right, the " << theUser.getWeaponName() << " ,how can I forget a name as powerful as that" << endl << endl;
            cout << "You may be wondering who I am, you can refer to me as S.C.E, your guide to glory!" << endl;
            cout << "As your guide I will grant you one of three wonderful skills to help with your adventure! Choose wisely" << endl << endl;
            user.printWarriorSkills();
            cout << "So which will you choose?" << endl;
            getline(cin, userSkill);
            while (userSkill != "Gambler" && userSkill != "Hustler" && userSkill != "Oppurtunist")
            {
                cout << "Sorry, that wasn't an option, please select between Gambler Hustler or Oppurtunist" << endl;
                getline(cin, userSkill);
            }
            cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
            getline(cin, confirmSkill);
            while (confirmSkill != "Y" && confirmSkill != "N")
            {
                cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
                getline(cin, confirmSkill);
            }
            if (confirmSkill == "N")
            {
                while (confirmSkill == "N")
                {
                    user.printWarriorSkills();
                    cout << "So which will you choose?" << endl;
                    getline(cin, userSkill);
                    while (userSkill != "Gambler" && userSkill != "Hustler" && userSkill != "Oppurtunist")
                    {
                        cout << "Sorry, that wasn't a skill I mentioned, please select between Gambler Hustler or Oppurtunist" << endl;
                        getline(cin, userSkill);
                    }
                    cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
                    getline(cin, confirmSkill);
                    while (confirmSkill != "Y" && confirmSkill != "N")
                    {
                        cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
                        getline(cin, confirmSkill);
                    }
                }
            }
            user.setWarriorSkill(userSkill);
            user.setHP(20);
            cout << endl << "So then it is settled, you are " << theUser.getName() << " the " << theUser.getClassType() << " who weilds " << theUser.getWeaponName() << " and has the skill of the " << user.getWarriorSkill() << endl;
            cout << "Your future seems bright, I bid you good luck on your jou... Silly me, you don't know how to fight, let's dive into that area, shall we?" << endl << endl;
            user.printWarriorAttacks();
            cout << "These are your moves you get to use during your adventure, test one out: " << endl;
            cout << "Fists Of Fury | Double Slash" << endl;
            
            getline(cin, testMove);
            while (testMove != "Fists Of Fury" && testMove != "Double Slash")
            {
                cout << "Please select either Fists Of Fury or Double Slash" << endl;
                getline(cin, testMove);
            }
            if (testMove == "Fists Of Fury")
                user.fistsOfFury();
            else if (testMove == "Double Slash")
                user.doubleSlash();
            user.setEnergy(100);
            cout << endl << "Nicely done! I have taken the liberty of refilling your energy back to 100, you'll need it for the enemies you'll face" << endl << endl;
            cout << "Now you understand the art of battle. I do believe this is an actual goodbye now " << theUser.getName() << " have safe journeys ahead!" << endl;
            cout << "If you need help, I will be around, probally. Until we meet again :)" << endl << endl;

            w = user;
            cout << "Would you like to save your character and exit the game? (Y/N)" << endl;
            getline(cin, choice);
            if (choice == "Y")
            {
                saveCharacter(w);
                cout << "Character sucessfully saved! Now exiting..." << endl;
                exit(0);
            }
        }
        else if (theUser.getClassType() == "Mage")
        {
            cout << "That's right, you were a " << theUser.getClassType() << ", a good one too! You weilded a...the...what was the name of your staff again?" << endl;
            
            getline(cin, userWeapon);
            while (userWeapon.length() < 3 || userWeapon.length() > 15)
            {
                if (userWeapon.length() < 3)
                {
                    cout << "No that can't be it, a staff as powerful as yours has a much cooler, longer name than " << userWeapon << endl;
                    getline(cin, userWeapon);
                }
                else
                {
                    cout << "Woah there, that's quite the mouthful, mind shortening that? Or perhaps it was another, shorter name" << endl;
                    getline(cin, userWeapon);
                }
            }
            Mage user;
            user.setName(userName);
            user.setClassType(userClass);
            theUser.setWeaponName(userWeapon);
            user.setWeaponName(userWeapon);
            user.setWeaponType("Basic");

            cout << "That's right, the " << theUser.getWeaponName() << " ,how can I forget a name as powerful as that" << endl << endl;
            cout << "You may be wondering who I am, you can refer to me as S.C.E, your guide to glory!" << endl;
            cout << "As your guide I will grant you one of three wonderful skills to help with your adventure! Choose wisely" << endl << endl;
            user.printMageSkills();
            cout << "So which will you choose?" << endl;
            getline(cin, userSkill);
            while (userSkill != "Elemental" && userSkill != "Etheral" && userSkill != "Maximal")
            {
                cout << "Sorry, that wasn't an option, please select between Elemental Etheral or Maximal" << endl;
                getline(cin, userSkill);
            }
            cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
            getline(cin, confirmSkill);
            while (confirmSkill != "Y" && confirmSkill != "N")
            {
                cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
                getline(cin, confirmSkill);
            }
            if (confirmSkill == "N")
            {
                while (confirmSkill == "N")
                {
                    user.printMageSkills();
                    cout << "So which will you choose?" << endl;
                    getline(cin, userSkill);
                    while (userSkill != "Elemental" && userSkill != "Etheral" && userSkill != "Maximal")
                    {
                        cout << "Sorry, that wasn't a skill I mentioned, please select between Elemental Etheral or Maximal" << endl;
                        getline(cin, userSkill);
                    }
                    cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
                    getline(cin, confirmSkill);
                    while (confirmSkill != "Y" && confirmSkill != "N")
                    {
                        cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
                        getline(cin, confirmSkill);
                    }
                }
            }
            user.setMageSkill(userSkill);
            user.setHP(15);
            cout << endl << "So then it is settled, you are " << theUser.getName() << " the " << theUser.getClassType() << " who weilds " << theUser.getWeaponName() << " and has the skill of the " << user.getMageSkill() << endl;
            cout << "Your future seems bright, I bid you good luck on your jou... Silly me, you don't know how to fight, let's dive into that area, shall we?" << endl << endl;
            user.printMageAttacks();
            cout << "These are your moves you get to use during your adventure, test one out: " << endl;
            cout << "Fireball | Poison Spray | Magic Missile" << endl;
            
            getline(cin, testMove);
            while (testMove != "Fireball" && testMove != "Poison Spray" && testMove != "Magic Missile")
            {
                cout << "You don't know a move by name. I think you know either Fireball | Poison Spray | Magic Missile" << endl;
                getline(cin, testMove);
            }
            if (testMove == "Fireball")
                user.fireball();
            else if (testMove == "Poison Spray")
                user.poisonSpray();
            else
                user.magicMissile();
            user.setEnergy(100);
            cout << endl << "Nicely done! I have taken the liberty of refilling your energy back to 100, you'll need it for the enemies you'll face" << endl << endl;
            cout << "Now you understand the art of battle. I do believe this is an actual goodbye now " << theUser.getName() << " have safe journeys ahead!" << endl;
            cout << "If you need help, I will be around, probally. Until we meet again :)" << endl << endl;

            m = user;
            cout << "Would you like to save your character and exit the game? (Y/N)" << endl;
            getline(cin, choice);
            if (choice == "Y")
            {
                saveCharacter(m);
                cout << "Character sucessfully saved! Now exiting..." << endl;
                exit(0);
            }
        }
        else
        {
            Alchemist user;
            user.setName(userName);
            user.setClassType(userClass);
            user.setWeaponType("Basic");

            cout << "You may be wondering who I am, you can refer to me as S.C.E, your guide to glory!" << endl;
            cout << "As your guide I will grant you one of three wonderful skills to help with your adventure! Choose wisely" << endl << endl;
            user.printAlchemistSkills();
            cout << "So which will you choose?" << endl;
            getline(cin, userSkill);
            while (userSkill != "Medic" && userSkill != "Vampiric" && userSkill != "Academic")
            {
                cout << "Sorry, that wasn't an option, please select between Medic Vampiric or Academic" << endl;
                getline(cin, userSkill);
            }
            cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
            getline(cin, confirmSkill);
            while (confirmSkill != "Y" && confirmSkill != "N")
            {
                cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
                getline(cin, confirmSkill);
            }
            if (confirmSkill == "N")
            {
                while (confirmSkill == "N")
                {
                    user.printAlchemistSkills();
                    cout << "So which will you choose?" << endl;
                    getline(cin, userSkill);
                    while (userSkill != "Medic" && userSkill != "Vampiric" && userSkill != "Academic")
                    {
                        cout << "Sorry, that wasn't a skill I mentioned, please select between Medic Vampiric or Academic" << endl;
                        getline(cin, userSkill);
                    }
                    cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
                    getline(cin, confirmSkill);
                    while (confirmSkill != "Y" && confirmSkill != "N")
                    {
                        cout << "Are you sure you want to pick the skill: " << userSkill << "? This can not be changed. (Y or N)" << endl;
                        getline(cin, confirmSkill);
                    }
                }
            }
            user.setAlchemistSkill(userSkill);
            user.setHP(15);
            cout << endl << "So then it is settled, you are " << theUser.getName() << " the " << theUser.getClassType() << " who has the skill of the " << user.getAlchemistSkill() << endl;
            cout << "Your future seems bright, I bid you good luck on your jou... Silly me, you don't know how to fight, let's dive into that area, shall we?" << endl << endl;
            user.printAlchemistAttacks();
            cout << "These are your moves you get to use during your adventure, test one out: " << endl;
            cout << "Potion Of Damaging | Potion Of Weakening | Potion Of Healing" << endl;
            
            getline(cin, testMove);
            while (testMove != "Potion Of Damaging" && testMove != "Potion Of Weakening" && testMove != "Potion Of Healing")
            {
                cout << "You don't know a move by name. I think you know either Potion Of Damaging | Potion Of Weakening | Potion Of Healing" << endl;
                getline(cin, testMove);
            }
            if (testMove == "Potion Of Damaging")
                user.potionOfDamaging();
            else if (testMove == "Potion Of Weakening")
                user.potionOfWeakening();
            else
                user.potionOfHealing();
            user.setEnergy(100);
            cout << endl << "Nicely done! I have taken the liberty of refilling your energy back to 100, you'll need it for the enemies you'll face" << endl << endl;
            cout << "Now you understand the art of battle. I do believe this is an actual goodbye now " << theUser.getName() << " have safe journeys ahead!" << endl;
            cout << "If you need help, I will be around, probally. Until we meet again :)" << endl << endl;

            a = user;
            cout << "Would you like to save your character and exit the game? (Y/N)" << endl;
            getline(cin, choice);
            if (choice == "Y")
            {
                saveCharacter(a);
                cout << "Character sucessfully saved! Now exiting..." << endl;
                exit(0);
            }
        }
    }

    if (w.getHP() != 0)
        area = w.getArea();
    else if (m.getHP() != 0)
        area = m.getArea();
    else if (a.getHP() != 0)
        area = a.getArea();

    if (area == "")
    {
        if (w.getHP() != 0)
            cout << "And with that " << w.getName() << " embarks on their quest for glory!" << endl;
        else if (m.getHP() != 0)
            cout << "And with that " << m.getName() << " embarks on their quest for glory!" << endl;
        else if (a.getHP() != 0)
            cout << "And with that " << a.getName() << " embarks on their quest for glory!" << endl;
        cout << "*****************************************" << endl << endl;

        cout << "After walking for a bit, you find an old abadoned house, do you pass it by, go into the basement, or go into the attic (Pass/Basement/Attic)" << endl;
        getline(cin, roomChoice);

        while (roomChoice != "Pass" && roomChoice != "Basement" && roomChoice != "Attic")
        {
            cout << "Would you like to pass the house, go to the basement or go to the Attic? (Pass/Basement/Attic)" << endl;
            getline(cin, roomChoice);
        }

        if (roomChoice == "Basement")
            area = "Basement";
        else if (roomChoice == "Attic")
            area = "Attic";
        else if (roomChoice == "Pass")
            area = "Pass";
    }

    if (area == "Basement")
    {
        if (w.getHP() != 0) w.setArea("Basement");
        else if (m.getHP() != 0) m.setArea("Basement");
        else if (a.getHP() != 0) a.setArea("Basement");


        if (w.getHP() != 0) room.Basement(w);
        else if (m.getHP() != 0) room.Basement(m);
        else if (a.getHP() != 0) room.Basement(a);

        area = "Illusion";
    }
    else if (area == "Attic")
    {
        if (w.getHP() != 0) w.setArea("Attic");
        else if (m.getHP() != 0) m.setArea("Attic");
        else if (a.getHP() != 0) a.setArea("Attic");

        if (w.getHP() != 0) room.Attic(w);
        else if (m.getHP() != 0) room.Attic(m);
        else if (a.getHP() != 0) room.Attic(a);

        area = "Illusion";
    }
    else if (area == "Pass")
    {
        cout << "You've decided to pass on the old house and continue onward." << endl;
        area = "Illusion";
    }

    if (area == "Illusion")
    {
        cout << "\"Heyyo, it's your pal SCE! Nicely done at the house. Your journey is still underway.\"" << endl;
        cout << "\"Just keep your wits about you, procceed with caution to the dragon's lair up ahead, you're not too far.\"" << endl;
        cout << "\"Farewell " << userName << ", until we meet again\"" << endl << endl;

        cout << "Would you like to save your character and exit the game? All your progress will be saved (Y/N)" << endl;
        getline(cin, choice);
        if (choice == "Y")
        {
           if (w.getHP() != 0) saveCharacter(w);
           else if (m.getHP() != 0) saveCharacter(m);
           else if (a.getHP() != 0) saveCharacter(a);
           cout << "Character sucessfully saved! Now exiting..." << endl;
           exit(0);
        }

        cout << "After talking to SCE, you walk past a strange looking area, everything seems slightly disorted" << endl;
        cout << "Soon you realize it's an illusion, a trap by an enemy, what do you do? (Run or Attack)" << endl;
        getline(cin, illusionChoice);
        while (illusionChoice != "Run" && illusionChoice != "Attack")
        {
            cout << "You realize it's an illusion, a trap by an enemy, what do you do? (Run or Attack)" << endl;
            getline(cin, illusionChoice);
        }
        
        if (illusionChoice == "Run")
        {
            if (w.getHP() != 0) w.setArea("Illusion");
            else if (m.getHP() != 0) m.setArea("Illusion");
            else if (a.getHP() != 0) a.setArea("Illusion");


            if (w.getHP() != 0) room.puzzleRoom(w);
            else if (m.getHP() != 0) room.puzzleRoom(m);
            else if (a.getHP() != 0) room.puzzleRoom(a);
        }
        else if (illusionChoice == "Attack")
        {
            if (w.getHP() != 0)
            {
                cout << "Looking around, you take a hard slash at a weird tree which breaks the illusion!" << endl;
                cout << "Small crystaline fragments line your sword, you don't know what they are, but you clean them off and comtinue on your journey!" << endl;
            }
            else if (m.getHP() != 0)
            {
                cout << "Looking around, you blindly cast magic missiles towards the sky which breaks the illusion!" << endl;
                cout << "Small crystaline fragments line your staff, you don't know what they are, but you clean them off and comtinue on your journey!" << endl;
            }
            else if (a.getHP() != 0)
            {
                cout << "Looking around, you blindly throw multiple potions of damaging at a weird looking rock which breaks the illusion!" << endl;
                cout << "Small crystaline fragments line your flasks, you don't know what they are, but you clean them off and comtinue on your journey!" << endl;
            }
        }

        area = "Forced Enemy Attack";
    }

    if (area == "Forced Enemy Attack")
    {
        if (w.getHP() != 0) w.setArea("Forced Enemy Attack");
        else if (m.getHP() != 0) m.setArea("Forced Enemy Attack");
        else if (a.getHP() != 0) a.setArea("Forced Enemy Attack");

        cout << "As you continue on your trek, you feel the gaze of an enemy near you" << endl;
        cout << "Suddenly, you're attacked!" << endl << endl;        

        cout << "Would you like to save your character and exit the game? All your progress will be saved (Y/N)" << endl;
        getline(cin, choice);
        if (choice == "Y")
        {
            if (w.getHP() != 0) saveCharacter(w);
            else if (m.getHP() != 0) saveCharacter(m);
            else if (a.getHP() != 0) saveCharacter(a);
            cout << "Character sucessfully saved! Now exiting..." << endl;
            exit(0);
        }

        if (w.getHP() != 0) battle.startBattle(w);
        else if (m.getHP() != 0) battle.startBattle(m);
        else if (a.getHP() != 0) battle.startBattle(a);

        area = "Final Boss";
    }

    if (area == "Final Boss")
    {
        cout << "\"SCE Here! You're almost done with your journey, you just need to defeat the dragon! I know I haven't told you that was the end goal, but yeah, have fun!\"" << endl;
        cout << "\"Just over that hill, you can enter the lair of the dragon! You've trained for this moment (somwehat), I believe in you " << userName << "\"" << endl << endl;
        cout << "And with that, SCE is gone. You take the route SCE told you about and you enter the Dragon's lair. There the dragon seems eager to see you there." << endl;
        cout << "Suddenly, the dragon attacks!" << endl;

        w.setEndGame(true);
        m.setEndGame(true);
        a.setEndGame(true);

        if (w.getHP() != 0) w.setArea("Final Boss");
        else if (m.getHP() != 0) m.setArea("Final Boss");
        else if (a.getHP() != 0) a.setArea("Final Boss");

        cout << "Would you like to save your character and exit the game? All your progress will be saved (Y/N)" << endl;
        getline(cin, choice);
        if (choice == "Y")
        {
            if (w.getHP() != 0) saveCharacter(w);
            else if (m.getHP() != 0) saveCharacter(m);
            else if (a.getHP() != 0) saveCharacter(a);
            cout << "Character sucessfully saved! Now exiting..." << endl;
            exit(0);
        }

        if (w.getHP() != 0) battle.startBattle(w);
        else if (m.getHP() != 0) battle.startBattle(m);
        else if (a.getHP() != 0) battle.startBattle(a);

        cout << "After defeating the dragon, you limp out the cave and you see a familar face, SCE" << endl;
        cout << "\"You've done it! You've completed the quest, thank you for emabrking on the journey, I know it's been difficult\"" << endl;
        cout << "This will conclude the game, thank you for playing :) " << endl;

        ofstream ofs("SaveFile", ios::trunc);
        ofs.close();
    }
}
