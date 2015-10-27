#include <iostream>
#include <cstdlib>
#include <windows.h>

#include "MapComponents/Level.h"

void SetWindowSize(int height, int width) {
	// Create structure window and defines its coordinates
    SMALL_RECT window;
    window.Top = 0;
    window.Left = 0;
    window.Bottom = height - 1;
    window.Right = width - 1;

    /*
     * Sets the current size and position of a console screen buffer's window.
     * Set the right size of window (avoid scrolling, full map etc)
	 *
     * GetStdHandle function - Retrieves a handle to the specified standard device 
     * (standard input, standard output, or standard error).
     *
     * STD_OUTPUT_HANDLE - The standard output device. Initially, this is the active console screen buffer
     *
     * bAbsolute - If this parameter is TRUE, the coordinates specify the new upper-left and lower-right corners of the window. 
     * If it is FALSE, the coordinates are relative to the current window-corner coordinates
     *
     * lpConsoleWindow  - A pointer to a SMALL_RECT structure 
     * that specifies the new upper-left and lower-right corners of the window
     */
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &window);

    // COORD structure - Defines the coordinates of a character cell in a console screen buffer. 
    // The origin of the coordinate system (0,0) is at the top, left cell of the buffer.
    COORD buffer = { (SHORT)width, (SHORT)height};
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), buffer);
}

int main() {
	SetWindowSize(MAP_HEIGHT + 4, MAP_WIDTH + 4);

    std::cout << "Use 'w', 'a', 's', 'd' buttons to control" << std::endl;
    Sleep(3000);
    std::cout << "Reach exit to win! (Exit marked as '^^' on the top of map)" << std::endl;
    Sleep(3000);
    std::cout << "Prepare for game!" << std::endl;
    Sleep(3000);

    Level* level = new Level();

    std::cout << *level << std::endl;

    for( ; ; ) {
        level->moveAll();
        Sleep(150);
    }
}
