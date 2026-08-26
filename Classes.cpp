#include "Classes.h" 

    void Classes::setName(string s) 
    {
       name = s;
    }

    string Classes::getName() 
    {
        return name;
    }

    void Classes::setClassType(string s)
    {
        classType = s;
    }

    string Classes::getClassType() 
    {
        return classType;
    }

    void Classes::setLevel(int i)
    {
        level = i;
    }

    int Classes::getLevel() 
    {
        return level;
    }

    void Classes::setHP(int i) 
    {
        HP = i;
    }

    int Classes::getHP() 
    {
        return HP;
    }

    void Classes::setEnergy(int i) 
    {
        energy = i;
    }

    int Classes::getEnergy() 
    {
        return energy;
    }