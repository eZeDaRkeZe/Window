#pragma once

#include <Windows.h>

class Wind
{
	int x, y; // Координаты Л В У
	int h, w; // Ширина и высота
	bool active; // Активное
	bool Empty = 1;
	int TextColor, BackColor; // Цвета текста и фона
	char bufer[256]; 
public:
	Wind(void);
	Wind(int x, int y, int h, int w);
	~Wind(void);

	void Paint(HANDLE hConsole);
	void SetPosition(HANDLE hConsole, int x, int y);
	void SetActive(bool a);
	int  GetActive();
	void SetTextColor(int TextColor);
	void Fill(char a[]);
	int	 GetX();
	int  GetY();
};
