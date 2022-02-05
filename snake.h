#ifndef SNAKE_H
#define SNAKE_H

#include<windows.h>
#include<vector>


#define LENGTH 50
#define BREADTH 25

using namespace std;

class snake
{
    private:
        COORD position;
        int length;
        char direction;
        int velocity;
        vector<COORD> body;

    public:
        snake(COORD position, int velocity);

        void snakegrowth()
        {
            length++;
        }

        void snake_motion()   //to move the snake in a particular direction
        {
            switch(direction)
            {
                case 'l':
                    position.X=position.X-velocity;
                    break;

                case 'r':
                    position.X=position.X+velocity;
                    break;

                case 'u':
                    position.Y=position.Y-velocity;
                    break;

                case 'd':
                    position.Y=position.Y+velocity;
                    break;

            }

            body.push_back(position);
            if(body.size() > length)
            {
                body.erase(body.begin());
            }
        }

        void direction_change(char direction)  //function for changing direction
        {
            this->direction=direction;
        }

        vector<COORD> getbody()
        {
            return body;
        }


        bool snakecollide()
        {
            if(position.X < 1 || position.X>LENGTH-2 || position.Y < 1 || position.Y>BREADTH-2)
            {
                return true;
            }

            for(int i=0;i<length-1;i++)
            {
                if(position.X==body[i].X && position.Y==body[i].Y)
                {
                    return true;
                }
            }
            return false;
        }

         bool foodeaten(COORD foodposition)
        {
            if(position.X==foodposition.X && position.Y==foodposition.Y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        COORD getposition()   //function to get the current position of the snake
        {
            return position;
        }

};

#endif // SNAKE_H
