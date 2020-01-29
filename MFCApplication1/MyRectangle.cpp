#include "pch.h"
#include "MyRectangle.h"

IMPLEMENT_SERIAL(MyRectangle, MyShape, 1) // Step 5 on msdn

void MyRectangle::drawShape(CPaintDC &dc)
{
	dc.Rectangle(begin.getX(), begin.getY(), end.getX(), end.getY());
}