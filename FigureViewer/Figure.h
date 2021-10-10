#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
protected:
	int size;
	int offsetX, offsetY;
	COLORREF color;
private:
	bool isDragging, isResizing;
	int previousX, previousY, deltaX, deltaY;
	const int minSize = 10;
public:
	Figure(int size, int offsetX, int offsetY, COLORREF color) : size(size), offsetX(offsetX), offsetY(offsetY), isDragging(false), isResizing(false), previousX(0), previousY(0), color(color)
	{
	}
	void Clear(HDC dc)
	{
		RECT rect;
		GetClientRect(WindowFromDC(dc), &rect);
		HGDIOBJ brush = SelectObject(dc, CreateSolidBrush(RGB(255, 255, 255)));
		HGDIOBJ pen = SelectObject(dc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
		Rectangle(dc, 0, 0, rect.right, rect.bottom);
		DeleteObject(brush);
		DeleteObject(pen);
	}
	virtual void Draw(HDC dc) = 0;
	virtual bool InnerPoint(int X, int Y) = 0;
	void setSize(int Size) {
		size = Size;
	}
	int getSize() {
		return size;
	}
	void resize(int deltaSize) {
		int newSize = size + deltaSize;
		if (newSize >= minSize) {
			setSize(newSize);
		}
	}
	void setColor(const COLORREF& Color) {
		color = Color;
	}
	void MoveTo(int X, int Y)
	{
		offsetX = X;
		offsetY = Y;
	}
	void Move(int X, int Y)
	{
		offsetX += X;
		offsetY += Y;
	}
	void StartDragging(int X, int Y)
	{
		isDragging = true;
		deltaX = X - offsetX;
		deltaY = Y - offsetY;
	}
	void StartResizing(int X, int Y)
	{
		if (InnerPoint(X, Y)) {
			isResizing = true;
		}
	}
	void Drag(int X, int Y)
	{
		offsetX = X - deltaX;
		offsetY = Y - deltaY;
	}
	void StopDragging()
	{
		isDragging = false;
	}
	void StopResizing()
	{
		isResizing = false;
	}
	bool IsDragging()
	{
		return isDragging;
	}
	bool IsResizing()
	{
		return isResizing;
	}
};

#endif FIGURE_H
