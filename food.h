#ifndef FOOD_H
#define FOOD_H

#include<windows.h>
#include<cstdio>

#define BREADTH 25
#define LENGTH 50

class food
{
    private:
        COORD position;

    public:
        void generatefood()
        {
            position.X=(rand()% (LENGTH-2))+1;
            position.Y=(rand()%(BREADTH-2))+1;
        }

        COORD getposition()
        {
            return position;
        }
};

#endif       // FOOD_h
