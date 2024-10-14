#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>



namespace snake
{
    class Snake
    {
        int x, y;
        char head = 'O';
        char tail = 'o';
        int tailX[100], tailY[100];
        int length;
         friend class Board;

        public:
            Snake(int xcoord = 7, int ycoord=7);
            ~Snake();
            int getX();
            int getY();
            void moveLeft();
            void moveRight();
            void moveUp();
            void moveDown();
            void addTail();
            void moveTail();
            friend std::ostream &operator<<(std::ostream &ostr, Snake snake);
    };
};

#endif