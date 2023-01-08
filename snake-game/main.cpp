#include <iostream>
#include <windows.h>

#define WIDTH 50
#define HEIGHT 25
using namespace std;
int x = 10, y = 10;

void board()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "#"; // printing wall ki left waali row
        for (int j = 0; j < WIDTH - 2; j++)
        {
            if (i == 0 || i == HEIGHT - 1) cout << "#";
            else if (i == y || j == x) cout << "0";
            else cout << " ";
        }
        cout << "#\n"; //printing right waali row of wall
        
    }
    
}

int main()
{
    board();
    x++;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0}); //cursor utha ke origin par bhejing
    return 0;
}cd