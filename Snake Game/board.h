#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "snake.h"
#include "food.h"

#define BOARD_HEIGHT 15
#define BOARD_WIDTH 30

namespace snake
{
    enum Direction
    {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        NONE
    };
    class Board
    {
        char wall = '#';
        int length;
        int width;
        int score;

        Snake* snake;
        Food* food;

        Direction direction;

    public:
        
        Board(int l = BOARD_HEIGHT, int b = BOARD_WIDTH);
        ~Board();
        void spawn();
        void update(std::ostream &ostr=std::cout);
        void moveSnake();
        void setDirection(Direction d);
    };
    std::ostream &operator<<(std::ostream &ostr, Board &board);
};

#endif