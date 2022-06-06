#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "util.h"

void cursor_visible(bool type)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = type; // 0: Ŀ�� ���̱�, 1: Ŀ�� ����� 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}


void init() {
	system("mode con cols=70 lines=100 | title desert island");
	cursor_visible(TRUE);
}

// Ŀ�� ��ġ �̵��Լ�  
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

// ù��°: �ؽ�Ʈ, �ι�°: ���  
void setColor(int forground, int background) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

int pressedKey()
{
    int pressedKey;
    while (1)
    {
        if (_kbhit())
        {
            pressedKey = _getch();
            return pressedKey;
        }
    }

}

bool keyCheckerIgnoreCase(char key)
{
    while (1)
    {
        if (_kbhit())
        {
            int pressedKey = _getch();
            if ((key > 'A' && key < 'Z'))
            {
                if (pressedKey == key || pressedKey == key + 32)
                    return true;
                else
                    return false;
            }
            else if ((key > 'a' && key < 'z'))
            {
                if (pressedKey == key || pressedKey == key - 32)
                    return true;
                else
                    return false;
            }
            else
            {
                if (pressedKey == key)
                    return true;
                else
                    return false;
            }
        }
    }
}