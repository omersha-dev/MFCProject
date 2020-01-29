#include "pch.h"
#include "MyShape.h"

IMPLEMENT_SERIAL(MyShape, CObject, 1) // Step 5 on msdn

MyShape::MyShape() {}

void MyShape::setBegin(const Point &p) { begin = p; }
void MyShape::setEnd(const Point &p) { end = p; }
void MyShape::Serialize(CArchive& archive)
{
	if (archive.IsStoring()) // if we want to store (save)
	{
		archive << selectBackground << bgColor << begin.getX() << begin.getY()
			<< end.getX() << end.getY();
	}
	else // if we want to restore (open)
	{
		int bx, by, ex, ey;
		archive >> selectBackground >> bgColor >> bx >> by >> ex >> ey;
		begin.setX(bx);
		begin.setY(by);
		end.setX(ex);
		end.setY(ey);
	}
}
void MyShape::draw(CPaintDC &dc)
{
	CPen pen(PS_SOLID, 2, bgColor);
	CBrush brush(bgColor);
	CBrush *old = dc.SelectObject(&brush);
	CPen *oldPen = dc.SelectObject(&pen);
	drawShape(dc);
	dc.SelectObject(oldPen);
	dc.SelectObject(old);
}
