#include "utils.h"
#include <iostream>

void clearScreen() {
    // ANSI escape code to move the cursor to the top-left corner of the console
    std::cout << "\033[H\033[J";
}