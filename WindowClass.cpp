#include "stdafx.h"
#include <conio.h>
#include <Windows.h>
#include "Wind.h"
#include <iostream>

enum ConsoleColor {
	Black = 0,
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


void PrintAll(int nWin, Wind mass[], HANDLE hConsole, int active)
{
	system("CLS");
	for (int i = 0; i < nWin; i++)
	{
		if (mass[i].GetActive() == 0)
			mass[i].Paint(hConsole);
	}
	mass[active].Paint(hConsole);
}

void Get(HANDLE hConsole, int nWin, Wind mass[])
{
	int active = 0;

	while (true)
	{
		char ch = _getch();
		switch (ch)
		{
		case '\t':

			mass[active].SetActive(0);
			active++;
			if (active == nWin)
				active = 0;
			mass[active].SetActive(1);

			PrintAll(nWin, mass, hConsole, active);
			break;

		case '0':
			mass[active].SetTextColor(0);
			PrintAll(nWin, mass, hConsole, active);
			break;
		case '1':
			mass[active].SetTextColor(1);
			PrintAll(nWin, mass, hConsole, active);
			break;
		case '2':
			mass[active].SetTextColor(2);
			PrintAll(nWin, mass, hConsole, active);
			break;
		case '3':
			mass[active].SetTextColor(3);
			PrintAll(nWin, mass, hConsole, active);
			break;
		case '4':
			mass[active].SetTextColor(4);
			PrintAll(nWin, mass, hConsole, active);
			break;
		case '5':
			mass[active].SetTextColor(5);
			PrintAll(nWin, mass, hConsole, active);
			break;
		case '6':
			mass[active].SetTextColor(6);
			PrintAll(nWin, mass, hConsole, active);
			break;
		case '7':
			mass[active].SetTextColor(7);
			PrintAll(nWin, mass, hConsole, active);
			break;
		case '8':
			mass[active].SetTextColor(8);
			PrintAll(nWin, mass, hConsole, active);
			break;
		case '9':
			mass[active].SetTextColor(9);
			PrintAll(nWin, mass, hConsole, active);
			break;
		case ' ':
		{	
			mass[active].SetPosition(hConsole, mass[active].GetX() + 1, mass[active].GetY() + 1);
			
		}
		break;
		case 13:
			system("slc");
			PrintAll(nWin, mass, hConsole, active);
			break;
		}

	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	// Дескриптор объекта КОНСОЛИ 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color 0");

	int nWin = 0;
	Wind mass[10];
	int iActive = 0;


	Wind w0; // Используется к-р по умолчанию
	w0.SetActive(1);
	Wind w1(5, 5, 15, 40); // Используется к-р 
	Wind w2(25, 15, 8, 50); // Используется к-р 

	mass[nWin++] = w0;
	mass[nWin++] = w1;
	mass[nWin++] = w2;

	PrintAll(nWin, mass, hConsole, 0);
	Get(hConsole, nWin, mass);











	return 0;
}
