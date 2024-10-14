#include "snake.h"
namespace snake{
    Snake::Snake(int xcoord, int ycoord):length(0){
        x = xcoord;
        y = ycoord;
    }
    Snake::~Snake(){
        x = 0;
        y = 0;
    }
    void Snake::moveRight(){
        ++x;
        
    }
    void Snake::moveLeft()
    {
        
        --x;

       
    }
    void Snake::moveDown()
    {
        y++;
       
    }
    void Snake::addTail()
    {
        	length++;
            tailX[length-1] = x;
            tailY[length-1] = y;
    }
    void Snake::moveUp()
    {
        y--;
      
    }

    int Snake::getX(){
        return x;
    }
    int Snake::getY(){
        return y;
    }
    std::ostream &operator<<(std::ostream &ostr, Snake snake){
        ostr << snake.head;
        return ostr;
    }

    void Snake::moveTail() {
        for (int i = length; i > 0; i--) {
			tailX[i-1] = tailX[i - 2];
			tailY[i-1] = tailY[i - 2];
		}
		tailX[0] = x;
		tailY[0] = y;
    }
}