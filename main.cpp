#include <iostream>
#include<conio.h>
#include<ctime>
#include "snake.h"
#include "food.h"

#define BREADTH 25
#define LENGTH 50
using namespace std;

snake s({2,2}, 1);
food f;

int score=0;

//Creating a rectangle for the snake to be inside it

void boundary()
{
    COORD snakeposition=s.getposition();
    COORD foodposition=f.getposition();

    vector<COORD> snakebody=s.getbody();

    cout<<"CURRENT SCORE : "<<score<<"\n\n";

    for (int i = 0; i < BREADTH; i++)
    {
        cout << "\t\t\t#";
        for (int j = 0; j < LENGTH - 2; j++)
        {
            if (i == 0 || i == BREADTH - 1)
            {
                cout << "#";
            }
            else if (j+1 == snakeposition.X && i == snakeposition.Y )
            {
                cout << "O"; // inserting the object in the rectangle
            }
            else if(j+1 ==foodposition.X && i== foodposition.Y)
            {
                cout<<"O";
            }
            else
            {
                bool isbodypart=false;
                for(int k=0;k<snakebody.size()-1;k++)
                {
                    if(j+1==snakebody[k].X && i==snakebody[k].Y)
                    {
                        cout<<"o";
                        isbodypart=true;
                        break;
                    }
                }
                if(!isbodypart)
                {
                    cout<<" ";
                }
            }
        }
        cout << "#" << endl;
    }
}

int main()
{
    srand(time(NULL));
    f.generatefood();

    char gameover=false;
    while (!gameover)
    {
        boundary();

        if(kbhit())
        {
            switch(getch())
            {
                case 77:
                    s.direction_change('r');
                    break;

                case 75:
                    s.direction_change('l');
                    break;

                case 72:
                    s.direction_change('u');
                    break;

                case 80:
                    s.direction_change('d');
                    break;

            }
        }

        if(s.snakecollide())
        {
            gameover=true;
        }

        if(s.foodeaten(f.getposition()))
        {
            f.generatefood();
            s.snakegrowth();
            score+=5;
        }

        s.snake_motion();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    }
    return 0;
}
