#ifndef FOOD_H
#define FOOD_H
#include <iostream>

namespace snake
{   

    class Food
    {
        int x, y;
        char food = 'f';
        // friend class Board;

    public:
        Food();
        ~Food();
        void generate();
        void spawn();
        int getX();
        int getY();
        friend std::ostream &operator<<(std::ostream& ostr, const Food &food);
    };
};

#endif