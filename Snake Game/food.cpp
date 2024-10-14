#include "food.h"
#include <random>
namespace snake
{
    Food::Food()
    {
        generate();
    }
    void Food::generate()
    {
        std::random_device rd;  // Seed for random number generator
        std::mt19937 gen(rd()); // Mersenne Twister random number generator

        // Define a distribution range
        std::uniform_int_distribution<> xcoord(1, 29); // Random integers between 1 and 100
        std::uniform_int_distribution<> ycoord(1, 14);

        // Generate a random number
        int randomX = xcoord(gen);
        int randomY = ycoord(gen);

        x = randomX;
        y = randomY;
    }

    int Food::getX()
    {
        return x;
    }
    int Food::getY()
    {
        return y;
    }

    Food::~Food()
    {
        x = 0;
        y = 0;
    }

    std::ostream &operator<<(std::ostream &ostr, const Food &food)
    {
        ostr << food.food;
        return ostr;
    }
}