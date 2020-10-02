#include <conio.h>
#include "Wind.h"

enum ConsoleColor {
	Black,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};


Wind::Wind(void)
{
	x = 30; y = 10;
	w = 30; h = 10;
	active = 0;
	TextColor = Green;
	BackColor = Black;
}

Wind::Wind(int _x, int _y, int _h, int _w)
{
	x = _x;
	y = _y;
	h = _h;
	w = _w;
	active = 0;
	TextColor = Green;
	BackColor = Black;
}

Wind::~Wind(void)
{}

void Wind::Paint(HANDLE hConsole)
{
	if (Empty == 1)
	{
		for (int i = 0; i < 256; i++)
		{
			bufer[i] = ' ';
		}
	}


	SetPosition(hConsole, x, y);

	SetConsoleTextAttribute(hConsole, (WORD)((BackColor << BackColor) | TextColor));
	_putch('+');
	for (int i = 0; i < w - 2; i++)
	{
		if (active == 1)
		{
			_putch('*');
		}
		else
			_putch('-');
	}
	_putch('+');
	_putch('\n');
	for (int j = 1; j < h - 1; j++)
	{
		SetPosition(hConsole, x, y + j);
		_putch('|');
		for (int i = 0; i < w - 2; i++)
		{
			if (j == 2) 
			{
				_putch('-');
			}
			else
			{
				int k = 0;
				_putch(bufer[k]);
				k++;
			}
		}
		_putch('|');
		_putch('\n');
	}

	SetPosition(hConsole, x, y + h - 1);
	_putch('+');
	for (int i = 0; i < w - 2; i++)
	{
		if (active)
		{
			_putch('*');
		}
		else
			_putch('-');
	}
	_putch('+');
	_putch('\n');
}

void Wind::SetPosition(HANDLE hConsole, int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(hConsole, c);
}

int Wind::GetX()
{
	return x;
}

int Wind::GetY()
{
	return y;
}

void Wind::SetActive(bool a)
{
	active = a;
}

int Wind::GetActive()
{
	return active;
}

void Wind::SetTextColor(int _TextColor)
{
	TextColor = _TextColor;
}

void Wind::Fill(char a[])
{

	
}
