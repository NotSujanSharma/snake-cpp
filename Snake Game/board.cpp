#include "board.h"
#include "utils.h"
#include <cstdlib>
namespace snake
{
    Board::Board(int l, int b):score(0)
    {
        length = l;
        width = b;
        food = new Food();
        snake = new Snake();
        direction = Direction::NONE;
    }
    void Board::spawn()
    {
        update(std::cout);
    }

    void Board::update(std::ostream &ostr)
    {
        clearScreen();
        moveSnake();
        
        if (snake->getX() == food->getX() && snake->getY() == food->getY())
        {
			score++;
			snake->addTail();
			food->generate();
		}
        for (int i = 0; i <= BOARD_WIDTH; i++)
        {

            std::cout << wall;
        }
        std::cout << std::endl;
        std::cout<<"Score: "<<score<<std::endl;
        for (int i = 0; i <= BOARD_WIDTH; i++)
        {

            std::cout << wall;
        }
        std::cout << std::endl;

        for (int j = 0; j <= BOARD_HEIGHT; j++)
        {

            for (int i = 0; i <= BOARD_WIDTH; i++)
            {
                bool printed = false;

                if (i == 0 || i == (BOARD_WIDTH))
                {
                    std::cout << wall;
                    printed = true;
                }

                else if (i == snake->getX() && j == snake->getY())
                {
                    std::cout << *snake;
                    printed = true;
                }
                else if (i == food->getX() && j == food->getY())
                {
                    std::cout << *food;
                    printed= true;
                    
                }             

                else if(snake->length>0)
                {
                    for (int k = 0; k < snake->length; k++) {
                        if (snake->tailX[k] == i && snake->tailY[k] == j) {
							std::cout << snake->tail;
                            printed = true;
						}
					}
                    
                }
                if (!printed)
                {
					std::cout << " ";
				}
            }
            std::cout << std::endl;
        }
        for (int i = 0; i <= BOARD_WIDTH; i++)
        {

            std::cout << wall;
        }
        std::cout << std::endl;
    }
    Board::~Board()
    {
        delete snake;
        delete food;
    }

    std::ostream &operator<<(std::ostream &ostr, Board &board)
    {
        board.update(ostr);
        return ostr;
    }
    void Board::moveSnake(){
        snake->moveTail();
        switch (direction){
            case Direction::LEFT:
                snake->moveLeft();
                break;
            case Direction::RIGHT:
                snake->moveRight(); 
                break;
            case Direction::UP:
                snake->moveUp(); 
                break;
            case Direction::DOWN:
                snake->moveDown();
                break;
            default:
                break;
        }
        
    }
    void Board::setDirection(Direction d)
    {
		direction = d;
    }
}
