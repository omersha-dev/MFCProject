#include "pch.h"
#include "MyLine.h"

IMPLEMENT_SERIAL(MyLine, MyShape, 1) // Step 5 on msdn

void MyLine::drawShape(CPaintDC &dc)
{
	dc.MoveTo(begin.getX(), begin.getY());
	dc.LineTo(end.getX(), end.getY());
}