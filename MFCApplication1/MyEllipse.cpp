#include "pch.h"
#include "MyEllipse.h"

//using namespace std;

IMPLEMENT_SERIAL(MyEllipse, MyShape, 1) // Step 5 on msdn

void MyEllipse::drawShape(CPaintDC &dc)
{
	dc.Ellipse(begin.getX(), begin.getY(), end.getX(), end.getY());
}