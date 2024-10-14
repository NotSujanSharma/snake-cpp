#include "board.h"
#include <thread>
#include <chrono>
#include <conio.h>

using namespace snake;

bool gameOver = false;

void update(Board *b);
void listenKeyboard(Board *b);

int main()
{
    Board board;
    board.spawn();
    std::thread boardThread(update, &board);
    std::thread inputThread(listenKeyboard, &board);
    boardThread.join();
    inputThread.join();

    return 0;
}

void update(Board *b)
{
    while (!gameOver)
    {
        std::cout << *b;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void listenKeyboard(Board *board)
{
    while (!gameOver)
    {
        if (_kbhit())
        {
            char ch = _getch();
            if (ch != 'q')
            {
                switch (ch)
                {
                case 'a':
                    board->setDirection(Direction::LEFT);
                    break;
                case 'd':
                    board->setDirection(Direction::RIGHT);
                    break;
                case 's':
                    board->setDirection(Direction::DOWN);
                    break;
                case 'w':
                    board->setDirection(Direction::UP);
                    break;
                default:
                    break;
                }
            }
            else
            {
                gameOver = true;
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}