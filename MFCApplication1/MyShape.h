#pragma once

#include "Point.h"

class MyShape : public CObject // Step 1 on msdn (CObject)
{
protected:
	Point begin, end;
	COLORREF bgColor, lastColor;
	int isDelete = 0;
	int selectBackground;

public:
	DECLARE_SERIAL(MyShape) // Step 3 on msdn
	MyShape();
	void setBegin(const Point &p);
	void setEnd(const Point &p);
	Point getBegin() { return begin; }
	Point getEnd() { return end; }
	virtual void drawShape(CPaintDC &dc) {}
	void Serialize(CArchive& archive);
	void draw(CPaintDC &dc);
	COLORREF getBg() const { return bgColor; }
	void setBg(COLORREF c) { bgColor = c; }
	COLORREF getLastColor() const { return lastColor; }
	void setLastColor(COLORREF c) { lastColor = c; }
	int getIsDelete() { return isDelete; }
	void setDelete(int isDelete) { this->isDelete = isDelete; }
	int getSelectBackground() { return selectBackground; }
	void setSelectBackground(int i) { selectBackground = i; }

};