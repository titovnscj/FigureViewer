#ifndef SIGHT_H
#define SIGHT_H

#include "Figure.h"

class Sight : public Figure
{
public:
	Sight(int size = 12, int offsetX = 100, int offsetY = 100, COLORREF color = RGB(0, 0, 0)) : Figure(size, offsetX, offsetY, color)
	{
	}
	void Draw(HDC dc)
	{
		HGDIOBJ pen = SelectObject(dc, CreatePen(PS_SOLID, 3, color));
		Rectangle(dc, offsetX, offsetY, offsetX + size, offsetY + size);
		DeleteObject(pen);
	}
	bool InnerPoint(int X, int Y)
	{
		return (X >= offsetX && X <= offsetX + size && Y >= offsetY && Y <= offsetY + size);
	}
};

#endif SIGHT_H
